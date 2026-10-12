<#
.SYNOPSIS
    一键编译并安装 ElaWidgetTools，无需启动 Qt Creator。

.DESCRIPTION
    依次执行：加载 MSVC x64 编译环境、CMake 配置（Ninja）、编译、安装，并对示例程序执行 windeployqt。
    Debug 与 Release 安装到同一目录，库文件依靠 Debug 后缀 d 共存；示例程序目录中的 exe 以最后安装的配置为准，
    每次安装后都会重新部署 Qt 运行库，保证与当前 exe 的配置一致。
    构建目录为 build\script-<Qt 版本>-<套件>-<配置>，与 Qt Creator 的构建目录互不影响，再次执行时增量编译。

.PARAMETER Config
    构建配置：Debug、Release 或 Both（先 Debug 后 Release），默认 Both。

.PARAMETER QtDir
    Qt 套件目录，默认 C:\Qt\6.8.3\msvc2022_64。

.PARAMETER InstallDir
    安装目录，默认为脚本所在目录下的 Install。

.PARAMETER Clean
    编译前删除所选配置对应的构建目录，进行全量编译。

.PARAMETER CleanInstall
    安装前删除安装目录下的 ElaWidgetTools 与 ElaWidgetToolsExample，避免残留旧版本中已删除的文件。

.EXAMPLE
    .\build_elawidgettools.ps1
    编译 Debug 与 Release，并安装到 .\Install。

.EXAMPLE
    .\build_elawidgettools.ps1 -Config Release -CleanInstall
    清理旧的安装内容后，仅编译并安装 Release。
#>
[CmdletBinding()]
param(
    [ValidateSet('Debug', 'Release', 'Both')]
    [string]$Config = 'Both',
    [string]$QtDir = 'C:\Qt\6.8.3\msvc2022_64',
    [string]$InstallDir = '',
    [switch]$Clean,
    [switch]$CleanInstall
)

Set-StrictMode -Version 3.0
$ErrorActionPreference = 'Stop'

# 输出阶段标题
function Write-Step {
    param([string]$Message)
    Write-Host ''
    Write-Host "==> $Message" -ForegroundColor Cyan
}

# 执行外部命令，退出码非 0 时抛出异常
function Invoke-NativeCommand {
    param(
        [string]$FilePath,
        [string[]]$ArgumentList
    )
    & $FilePath @ArgumentList
    if ($LASTEXITCODE -ne 0) {
        throw "命令执行失败（退出码 $LASTEXITCODE）：$FilePath $($ArgumentList -join ' ')"
    }
}

# 查找工具：优先使用候选路径，其次在 PATH 中查找
function Resolve-ToolPath {
    param(
        [string]$Name,
        [string[]]$Candidates
    )
    foreach ($candidate in $Candidates) {
        if ($candidate -and (Test-Path -LiteralPath $candidate)) {
            return (Resolve-Path -LiteralPath $candidate).Path
        }
    }
    $command = Get-Command $Name -CommandType Application -ErrorAction SilentlyContinue | Select-Object -First 1
    if ($command) {
        return $command.Path
    }
    throw "未找到 $Name，请安装后重试或将其加入 PATH。"
}

# 加载 Visual Studio x64 编译环境；当前已是 x64 开发者环境时跳过
function Import-MsvcEnvironment {
    $targetArch = [Environment]::GetEnvironmentVariable('VSCMD_ARG_TGT_ARCH')
    if ($targetArch -eq 'x64' -and (Get-Command cl.exe -CommandType Application -ErrorAction SilentlyContinue)) {
        Write-Host '当前已是 MSVC x64 开发者环境，跳过加载。'
        return
    }
    $vswherePath = Join-Path ${env:ProgramFiles(x86)} 'Microsoft Visual Studio\Installer\vswhere.exe'
    if (-not (Test-Path -LiteralPath $vswherePath)) {
        throw "未找到 vswhere.exe（$vswherePath），请确认已安装 Visual Studio 2019 或更高版本。"
    }
    $vsInstallPath = & $vswherePath -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath | Select-Object -First 1
    if (-not $vsInstallPath) {
        throw '未找到安装了 MSVC x64 工具集的 Visual Studio。'
    }
    $vcvarsPath = Join-Path $vsInstallPath 'VC\Auxiliary\Build\vcvars64.bat'
    if (-not (Test-Path -LiteralPath $vcvarsPath)) {
        throw "未找到 vcvars64.bat：$vcvarsPath"
    }
    Write-Host "加载编译环境：$vcvarsPath"
    # 在 cmd 中执行 vcvars64.bat 后输出全部环境变量，再写回当前进程
    $environmentLines = & cmd.exe /c "`"$vcvarsPath`" >nul 2>&1 && set"
    if ($LASTEXITCODE -ne 0) {
        throw "执行 vcvars64.bat 失败（退出码 $LASTEXITCODE）。"
    }
    foreach ($line in $environmentLines) {
        $separatorIndex = $line.IndexOf('=')
        if ($separatorIndex -gt 0) {
            [Environment]::SetEnvironmentVariable($line.Substring(0, $separatorIndex), $line.Substring($separatorIndex + 1), 'Process')
        }
    }
}

$totalStopwatch = [System.Diagnostics.Stopwatch]::StartNew()
try {
    $repoRoot = $PSScriptRoot
    if (-not $InstallDir) {
        $InstallDir = Join-Path $repoRoot 'Install'
    }
    $InstallDir = $ExecutionContext.SessionState.Path.GetUnresolvedProviderPathFromPSPath($InstallDir)
    $QtDir = $ExecutionContext.SessionState.Path.GetUnresolvedProviderPathFromPSPath($QtDir)

    Write-Step '检查 Qt 与构建工具'
    $qt6ConfigPath = Join-Path $QtDir 'lib\cmake\Qt6\Qt6Config.cmake'
    $qt5ConfigPath = Join-Path $QtDir 'lib\cmake\Qt5\Qt5Config.cmake'
    if (-not (Test-Path -LiteralPath $qt6ConfigPath) -and -not (Test-Path -LiteralPath $qt5ConfigPath)) {
        throw "Qt 目录无效：$QtDir（未找到 Qt6Config.cmake 或 Qt5Config.cmake），请通过 -QtDir 指定。"
    }
    # 构建目录名包含 Qt 版本与套件，切换 Qt 后不会复用缓存了旧 Qt 路径的构建目录
    $qtVersionName = Split-Path (Split-Path $QtDir -Parent) -Leaf
    $qtKitName = Split-Path $QtDir -Leaf
    $qtToolsDir = Join-Path (Split-Path (Split-Path $QtDir -Parent) -Parent) 'Tools'
    $windeployqtPath = Join-Path $QtDir 'bin\windeployqt.exe'

    Import-MsvcEnvironment
    $env:PATH = (Join-Path $QtDir 'bin') + ';' + $env:PATH
    $cmakePath = Resolve-ToolPath -Name 'cmake.exe' -Candidates @(Join-Path $qtToolsDir 'CMake_64\bin\cmake.exe')
    $ninjaPath = Resolve-ToolPath -Name 'ninja.exe' -Candidates @(Join-Path $qtToolsDir 'Ninja\ninja.exe')
    Write-Host "Qt：      $QtDir"
    Write-Host "CMake：   $cmakePath"
    Write-Host "Ninja：   $ninjaPath"
    Write-Host "安装目录：$InstallDir"

    if ($Config -eq 'Both') {
        $configList = @('Debug', 'Release')
    }
    else {
        $configList = @($Config)
    }

    # 清理只针对本项目安装的两个子目录，且在所有配置安装之前执行一次
    if ($CleanInstall) {
        Write-Step '清理旧的安装内容'
        foreach ($subDirName in @('ElaWidgetTools', 'ElaWidgetToolsExample')) {
            $subDirPath = Join-Path $InstallDir $subDirName
            if (Test-Path -LiteralPath $subDirPath) {
                Remove-Item -LiteralPath $subDirPath -Recurse -Force
                Write-Host "已删除：$subDirPath"
            }
        }
    }

    # CMake 参数统一使用正斜杠路径
    $qtDirForCMake = $QtDir.Replace('\', '/')
    $ninjaPathForCMake = $ninjaPath.Replace('\', '/')
    $installDirForCMake = $InstallDir.Replace('\', '/')
    $configTimeTable = [ordered]@{}

    foreach ($buildConfig in $configList) {
        $configStopwatch = [System.Diagnostics.Stopwatch]::StartNew()
        $buildDir = Join-Path $repoRoot ('build\script-{0}-{1}-{2}' -f $qtVersionName, $qtKitName, $buildConfig)
        if ($Clean -and (Test-Path -LiteralPath $buildDir)) {
            Write-Step "[$buildConfig] 删除构建目录 $buildDir"
            Remove-Item -LiteralPath $buildDir -Recurse -Force
        }

        Write-Step "[$buildConfig] CMake 配置"
        Invoke-NativeCommand -FilePath $cmakePath -ArgumentList @(
            '-S', $repoRoot,
            '-B', $buildDir,
            '-G', 'Ninja',
            "-DCMAKE_BUILD_TYPE=$buildConfig",
            "-DCMAKE_MAKE_PROGRAM=$ninjaPathForCMake",
            '-DCMAKE_CXX_COMPILER=cl',
            "-DCMAKE_PREFIX_PATH=$qtDirForCMake",
            "-DQT_SDK_DIR=$qtDirForCMake",
            "-DCMAKE_INSTALL_PREFIX=$installDirForCMake"
        )

        Write-Step "[$buildConfig] 编译"
        Invoke-NativeCommand -FilePath $cmakePath -ArgumentList @('--build', $buildDir, '--parallel')

        Write-Step "[$buildConfig] 安装到 $InstallDir"
        Invoke-NativeCommand -FilePath $cmakePath -ArgumentList @('--install', $buildDir)

        # CMake 安装脚本只在示例目录尚无 platforms 子目录时调用 windeployqt，
        # Debug 与 Release 混装时需按本次安装的 exe 重新部署，使 Qt 运行库与其配置一致
        $exampleDir = Join-Path $InstallDir 'ElaWidgetToolsExample'
        $exampleExePath = Join-Path $exampleDir 'ElaWidgetToolsExample.exe'
        if ((Test-Path -LiteralPath $windeployqtPath) -and (Test-Path -LiteralPath $exampleExePath)) {
            Write-Step "[$buildConfig] 部署示例程序的 Qt 运行库"
            Invoke-NativeCommand -FilePath $windeployqtPath -ArgumentList @(
                '--dir', $exampleDir,
                '--no-compiler-runtime',
                '--no-system-d3d-compiler',
                '--no-opengl-sw',
                '--verbose', '0',
                $exampleExePath
            )
        }
        else {
            Write-Warning '未找到 windeployqt 或已安装的示例程序，跳过 Qt 运行库部署。'
        }
        $configTimeTable[$buildConfig] = $configStopwatch.Elapsed
    }

    Write-Step '完成'
    foreach ($entry in $configTimeTable.GetEnumerator()) {
        Write-Host ('{0,-8}用时 {1:mm\:ss}' -f $entry.Key, $entry.Value)
    }
    Write-Host ('总用时  {0:mm\:ss}' -f $totalStopwatch.Elapsed)
    Write-Host "安装目录：$InstallDir"
    $libraryDir = Join-Path $InstallDir 'ElaWidgetTools'
    foreach ($subDirName in @('bin', 'lib')) {
        $subDirPath = Join-Path $libraryDir $subDirName
        if (Test-Path -LiteralPath $subDirPath) {
            $fileNameList = @(Get-ChildItem -LiteralPath $subDirPath -File | Select-Object -ExpandProperty Name)
            Write-Host ('  ElaWidgetTools\{0}：{1}' -f $subDirName, ($fileNameList -join '，'))
        }
    }
    Write-Host ('  CMake 包配置：{0}' -f (Join-Path $libraryDir 'lib\cmake'))
    Write-Host ('  示例程序：    {0}' -f (Join-Path $InstallDir 'ElaWidgetToolsExample\ElaWidgetToolsExample.exe'))
    exit 0
}
catch {
    Write-Host ''
    Write-Host "构建失败：$($_.Exception.Message)" -ForegroundColor Red
    exit 1
}
