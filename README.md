# ElaWidgetTools

## 简介

本项目是基于 [Liniyous/ElaWidgetTools](https://github.com/Liniyous/ElaWidgetTools) 的 Fork 版本，在原项目基础上进行了个人定制和修改。

原项目是基于 QT-Widget 开发的 FluentUI 风格的组件库，同时提供不限于组件的常用集成功能；目前 Main 分支支持 QT5.12 以上所有版本（Linux 为 QT5.15 以上），推荐版本为 QT6.4.3 和 QT6.6.2。

## Fork 说明

**上游项目：** [Liniyous/ElaWidgetTools](https://github.com/Liniyous/ElaWidgetTools)

**Fork 目的：** 基于原项目进行个人定制和功能扩展

**主要修改：** 
- 新增 ElaDialog 无边框对话框组件
- 新增 ElaMessageBox 自定义消息框（完全兼容 QMessageBox API）
- 新增 ElaInputDialog 输入对话框（支持多种输入模式）
- 优化 ElaAppBar 窗口拖动体验和自定义菜单功能
- 改进 ElaMessageBar 消息数量限制机制
- 增强 ElaWindow 多屏和全屏支持
- 修复多个组件的稳定性问题
- 优化 Visual Studio 调试体验

## 致谢

感谢 [Liniyous](https://github.com/Liniyous) 提供的优秀开源项目 ElaWidgetTools。

## 支持平台

| [Windows][win-link] | [Ubuntu/Kylin][ubuntu-link] |
|---------------------|-----------------------|
| ![win-badge]        | ![ubuntu-badge]       |

[win-link]: https://github.com/Liniyous/ElaWidgetTools/actions?query=workflow%3AWindows "WindowsAction"

[win-badge]: https://img.shields.io/badge/Windows-Passing-61C263

[ubuntu-link]: https://github.com/Liniyous/ElaWidgetTools/actions?query=workflow%3AUbuntu "UbuntuAction"

[ubuntu-badge]: https://img.shields.io/badge/Ubuntu-Passing-61C263

## 主界面预览

<div align=center>
  <img src="doc/preview/ElaWidgetTools_Light.png">
</div>
<div align=center>
  <img src="doc/preview/ElaWidgetTools_Dark.png">
</div> 

## 支持的组件

| 目录                     | 说明           | 备注                         |
|------------------------|--------------|----------------------------|
| ElaApplication         | 程序初始化        |                            |
| ElaAppBar              | 窗口顶部标题栏      | 支持拖动窗口，最小化、最大化、关闭窗口、调整窗口尺寸、自定义菜单 |
| ElaAcrylicUrlCard      | 带图片的交互式亚克力卡片 | 支持URL跳转                    |
| ElaBreadcrumbBar       | 面包屑组件        | 自动处理点击事件                   |
| ElaCheckBox            | 勾选框          |                            |
| ElaComboBox            | 下拉框          |                            |
| ElaColorDialog         | 颜色选择器        |                            |
| ElaCalendar            | 日历视图         |                            |
| ElaCalendarPicker      | 日期选择器        |                            |
| ElaMultiSelectComboBox | 多选下拉框        |                            |
| ElaContentDialog       | 带遮罩的对话框      |                            |
| ElaDialog              | 无边框对话框       | 支持自定义标题栏按钮                |
| ElaMessageBox          | 自定义消息框       | 完全兼容 QMessageBox API        |
| ElaInputDialog         | 输入对话框        | 支持文本、整数、浮点数、列表和多行文本输入    |
| ElaDockWidget          | 停靠窗口         |                            |
| ElaSpinBox             | 微调框          |                            |
| ElaDoubleSpinBox       | 微调框          | 浮点数                        |
| ElaDxgiManager         | DXGI采集器      | 支持自动选择采集设备 效率远高于原生采集       |
| ElaEventBus            | 事件总线         |                            |
| ElaFlowLayout          | 流式布局         | 支持动画                       |
| ElaIcon                | 图标           |                            |
| ElaIconButton          | 图标按钮         |                            |
| ElaImageCard           | 图片卡片         |                            |
| ElaInteractiveCard     | 带图片的交互式透明卡片  |                            |
| ElaKeyBinder           | 单按键绑定器       |                            |
| ElaLineEdit            | 输入框          |                            |
| ElaListView            | 列表视图         |                            |
| ElaLog                 | 消息日志         |                            |
| ElaMenu                | 菜单           |                            |
| ElaMenuBar             | 菜单栏          |                            |
| ElaMessageBar          | 弹出式信息栏       | 支持八方向，锚定位置，自动限制消息数量       |
| ElaMessageButton       | 弹出信息按钮       |                            |
| ElaPivot               | 轴转导航         |                            |
| ElaPlainTextEdit       | 文本编辑框        |                            |
| ElaPushButton          | 按钮           |                            |
| ElaPopularCard         | 热门卡片         |                            |
| ElaProgressBar         | 进度条          |                            |
| ElaPromotionCard       | 促销卡片         |                            |
| ElaPromotionView       | 促销卡片视窗       |                            |
| ElaSwitchButton        | 切换按钮         |                            |
| ElaSuggestBox          | 建议搜索框        |                            |
| ElaRadioButton         | 单选按钮         |                            |
| ElaNavigationRouter    | 路由跳转         |                            |
| ElaToggleSwitch        | 开关按钮         |                            |
| ElaTabBar              | 选项卡          | 谷歌浏览器风格                    |
| ElaTabWidget           | 选项卡页面        | 谷歌浏览器风格                    |
| ElaTableView           | 表格视图         |                            |
| ElaTreeView            | 树型视图         |                            |
| ElaToolButton          | 带下拉菜单的工具按钮   |                            |
| ElaToolBar             | 工具栏          |                            |
| ElaTheme               | 主题管理器        |                            |
| ElaReminderCard        | 带图片的提醒卡片     |                            |
| ElaScrollbar           | 滚动条          |                            |
| ElaScrollArea          | 滚动区域         | 可设置鼠标拖动                    |
| ElaScrollPage          | 滚动页面         | 自带堆栈页面和面包屑导航               |
| ElaScrollPageArea      | 滚动页面区域组件     |                            |
| ElaSlider              | 拖动条          |                            |
| ElaStatusBar           | 状态栏          |                            |
| ElaExponentialBlur     | 指数模糊         |                            |
| ElaText                | Text文本       |                            |
| ElaGraphicsScene       | 高级场景         | 大量实用API                    |
| ElaGraphicsView        | 高级视图         | 按键缩放、拖动                    |
| ElaGraphicsItem        | 高级图元         | 大量实用API                    |
| ElaWindow              | 带导航栏的无边框窗口   | 增强多屏和全屏支持                  |
| ElaWidget              | 无边框模态窗口      |                            |

## 许可证

本项目遵循 MIT 许可证。原项目也采用 MIT 许可证。

## 联系方式

如有问题或建议，请通过 Issues 反馈。
