#include "T_BaseComponents.h"

#include "ElaCheckBox.h"
#include "ElaComboBox.h"
#include "ElaInputDialog.h"
#include "ElaMessageBox.h"
#include "ElaMessageButton.h"
#include "ElaMultiSelectComboBox.h"
#include "ElaPlainTextEdit.h"
#include "ElaProgressBar.h"
#include "ElaProgressRing.h"
#include "ElaRadioButton.h"
#include "ElaScrollPageArea.h"
#include "ElaSlider.h"
#include "ElaSpinBox.h"
#include "ElaText.h"
#include "ElaToggleButton.h"
#include "ElaToggleSwitch.h"
#include "ElaPushButton.h"
#include "ElaToolButton.h"

#include <QButtonGroup>
#include <QHBoxLayout>
#include <QVBoxLayout>

T_BaseComponents::T_BaseComponents(QWidget* parent)
    : T_BasePage(parent)
{
    // 预览窗口标题
    setWindowTitle("ElaBaseComponents");

    // 顶部元素
    createCustomWidget("一些常用的基础组件被放置于此，可在此界面体验其效果并按需添加进项目中");

    _toggleSwitch = new ElaToggleSwitch(this);
    ElaScrollPageArea* toggleSwitchArea = new ElaScrollPageArea(this);
    QHBoxLayout* toggleSwitchLayout = new QHBoxLayout(toggleSwitchArea);
    ElaText* toggleSwitchText = new ElaText("ElaToggleSwitch", this);
    toggleSwitchText->setTextPixelSize(15);
    toggleSwitchLayout->addWidget(toggleSwitchText);
    toggleSwitchLayout->addWidget(_toggleSwitch);
    toggleSwitchLayout->addStretch();
    ElaToggleSwitch* toggleSwitchDisableSwitch = new ElaToggleSwitch(this);
    ElaText* toggleSwitchDisableText = new ElaText("禁用", this);
    toggleSwitchDisableText->setTextPixelSize(15);
    connect(toggleSwitchDisableSwitch, &ElaToggleSwitch::toggled, this, [=](bool checked) {
        _toggleSwitch->setDisabled(checked);
    });
    toggleSwitchLayout->addWidget(toggleSwitchDisableSwitch);
    toggleSwitchLayout->addWidget(toggleSwitchDisableText);
    toggleSwitchLayout->addSpacing(10);

    _toggleButton = new ElaToggleButton("ToggleButton", this);
    _toggleButton->setFixedWidth(120);
    ElaScrollPageArea* toggleButtonArea = new ElaScrollPageArea(this);
    QHBoxLayout* toggleButtonLayout = new QHBoxLayout(toggleButtonArea);
    ElaText* toggleButtonText = new ElaText("ElaToggleButton", this);
    toggleButtonText->setTextPixelSize(15);
    toggleButtonLayout->addWidget(toggleButtonText);
    toggleButtonLayout->addWidget(_toggleButton);
    toggleButtonLayout->addStretch();
    ElaToggleSwitch* toggleButtonDisableSwitch = new ElaToggleSwitch(this);
    ElaText* toggleButtonDisableText = new ElaText("禁用", this);
    toggleButtonDisableText->setTextPixelSize(15);
    connect(toggleButtonDisableSwitch, &ElaToggleSwitch::toggled, this, [=](bool checked) {
        _toggleButton->setDisabled(checked);
    });
    toggleButtonLayout->addWidget(toggleButtonDisableSwitch);
    toggleButtonLayout->addWidget(toggleButtonDisableText);
    toggleButtonLayout->addSpacing(10);

    _comboBox = new ElaComboBox(this);
    QStringList comboList{
        "我愿投身前途未卜的群星",
        "潜行 步伐小心翼翼",
        "不留游走痕迹",
        "如同一簇幽灵",
        "所谓 道德加上伦理",
        "抱歉只能律己"};
    _comboBox->addItems(comboList);
    ElaScrollPageArea* comboBoxArea = new ElaScrollPageArea(this);
    QHBoxLayout* comboBoxLayout = new QHBoxLayout(comboBoxArea);
    ElaText* comboBoxText = new ElaText("ElaComboBox", this);
    comboBoxText->setTextPixelSize(15);
    comboBoxLayout->addWidget(comboBoxText);
    comboBoxLayout->addWidget(_comboBox);
    comboBoxLayout->addStretch();
    ElaToggleSwitch* comboBoxDisableSwitch = new ElaToggleSwitch(this);
    ElaText* comboBoxDisableText = new ElaText("禁用", this);
    comboBoxDisableText->setTextPixelSize(15);
    connect(comboBoxDisableSwitch, &ElaToggleSwitch::toggled, this, [=](bool checked) {
        _comboBox->setDisabled(checked);
    });
    comboBoxLayout->addWidget(comboBoxDisableSwitch);
    comboBoxLayout->addWidget(comboBoxDisableText);
    comboBoxLayout->addSpacing(10);

    _multiSelectComboBox = new ElaMultiSelectComboBox(this);
    QStringList multiComboList{"执念的鱼", "提着灯闯过远洋的甄选", "继续下潜", "无需誓言", "我的心像自沉的旧母舰", "没入深渊", "我曾凝望曾是航向的日出"};
    QStringList multiSelectComboList{"执念的鱼", "提着灯闯过远洋的甄选", "无需誓言", "我的心像自沉的旧母舰"};
    _multiSelectComboBox->addItems(multiComboList);
    _multiSelectComboBox->setCurrentSelection(multiSelectComboList);
    ElaScrollPageArea* multiSelectComboBoxArea = new ElaScrollPageArea(this);
    QHBoxLayout* multiSelectComboBoxLayout = new QHBoxLayout(multiSelectComboBoxArea);
    ElaText* multiSelectComboBoxText = new ElaText("ElaMutilSelectComboBox", this);
    multiSelectComboBoxText->setTextPixelSize(15);
    multiSelectComboBoxLayout->addWidget(multiSelectComboBoxText);
    multiSelectComboBoxLayout->addWidget(_multiSelectComboBox);
    multiSelectComboBoxLayout->addStretch();
    ElaToggleSwitch* multiSelectComboBoxDisableSwitch = new ElaToggleSwitch(this);
    ElaText* multiSelectComboBoxDisableText = new ElaText("禁用", this);
    multiSelectComboBoxDisableText->setTextPixelSize(15);
    connect(multiSelectComboBoxDisableSwitch, &ElaToggleSwitch::toggled, this, [=](bool checked) {
        _multiSelectComboBox->setDisabled(checked);
    });
    multiSelectComboBoxLayout->addWidget(multiSelectComboBoxDisableSwitch);
    multiSelectComboBoxLayout->addWidget(multiSelectComboBoxDisableText);
    multiSelectComboBoxLayout->addSpacing(10);

    _messageButton = new ElaMessageButton("Success", this);
    _messageButton->setBarTitle("Success");
    _messageButton->setBarText("点燃星 亲手点燃黑暗森林的火星 蒙昧初醒 而我却 轻声告别这新生的黎明");

    _infoMessageButton = new ElaMessageButton("Info", this);
    _infoMessageButton->setBarTitle("Information");
    _infoMessageButton->setBarText("点燃星 亲手点燃黑暗森林的火星 蒙昧初醒 而我却 轻声告别这新生的黎明");
    _infoMessageButton->setMessageMode(ElaMessageBarType::Information);
    _infoMessageButton->setPositionPolicy(ElaMessageBarType::TopLeft);

    _warningMessageButton = new ElaMessageButton("Warning", this);
    _warningMessageButton->setBarTitle("Warning");
    _warningMessageButton->setBarText("点燃星 亲手点燃黑暗森林的火星 蒙昧初醒 而我却 轻声告别这新生的黎明");
    _warningMessageButton->setMessageMode(ElaMessageBarType::Warning);
    _warningMessageButton->setPositionPolicy(ElaMessageBarType::BottomLeft);

    _errorMessageButton = new ElaMessageButton("Error", this);
    _errorMessageButton->setBarTitle("Error");
    _errorMessageButton->setBarText("点燃星 亲手点燃黑暗森林的火星 蒙昧初醒 而我却 轻声告别这新生的黎明");
    _errorMessageButton->setMessageMode(ElaMessageBarType::Error);
    _errorMessageButton->setPositionPolicy(ElaMessageBarType::BottomRight);

    ElaScrollPageArea* messageButtonArea = new ElaScrollPageArea(this);
    QHBoxLayout* messageButtonLayout = new QHBoxLayout(messageButtonArea);
    ElaText* messageButtonText = new ElaText("ElaMessageButton", this);
    messageButtonText->setTextPixelSize(15);
    messageButtonLayout->addWidget(messageButtonText);
    messageButtonLayout->addWidget(_messageButton);
    messageButtonLayout->addWidget(_infoMessageButton);
    messageButtonLayout->addWidget(_warningMessageButton);
    messageButtonLayout->addWidget(_errorMessageButton);
    messageButtonLayout->addStretch();
    ElaToggleSwitch* messageButtonDisableSwitch = new ElaToggleSwitch(this);
    ElaText* messageButtonDisableText = new ElaText("禁用", this);
    messageButtonDisableText->setTextPixelSize(15);
    connect(messageButtonDisableSwitch, &ElaToggleSwitch::toggled, this, [=](bool checked) {
        _messageButton->setDisabled(checked);
        _infoMessageButton->setDisabled(checked);
        _warningMessageButton->setDisabled(checked);
        _errorMessageButton->setDisabled(checked);
    });
    messageButtonLayout->addWidget(messageButtonDisableSwitch);
    messageButtonLayout->addWidget(messageButtonDisableText);
    messageButtonLayout->addSpacing(10);

    // ElaMessageBox 示例区域
    ElaPushButton* informationBoxButton = new ElaPushButton("Information", this);
    informationBoxButton->setFixedWidth(100);
    connect(informationBoxButton, &ElaPushButton::clicked, this, [=]() {
        ElaMessageBox::information(this, "提示", "这是一个信息提示框，用于显示一般信息。");
    });

    ElaPushButton* questionBoxButton = new ElaPushButton("Question", this);
    questionBoxButton->setFixedWidth(100);
    connect(questionBoxButton, &ElaPushButton::clicked, this, [=]() {
        auto result = ElaMessageBox::question(this, "询问", "是否保存当前更改？",
            QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel,
            QMessageBox::Yes);
        if (result == QMessageBox::Yes) {
            ElaMessageBox::information(this, "结果", "您选择了\"是\"");
        } else if (result == QMessageBox::No) {
            ElaMessageBox::information(this, "结果", "您选择了\"否\"");
        } else {
            ElaMessageBox::information(this, "结果", "您选择了\"取消\"");
        }
    });

    ElaPushButton* warningBoxButton = new ElaPushButton("Warning", this);
    warningBoxButton->setFixedWidth(100);
    connect(warningBoxButton, &ElaPushButton::clicked, this, [=]() {
        ElaMessageBox::warning(this, "警告", "这是一个警告消息，请注意可能的风险！");
    });

    ElaPushButton* criticalBoxButton = new ElaPushButton("Critical", this);
    criticalBoxButton->setFixedWidth(100);
    connect(criticalBoxButton, &ElaPushButton::clicked, this, [=]() {
        ElaMessageBox::critical(this, "错误", "发生了严重错误，操作无法继续！");
    });

    ElaPushButton* customBoxButton = new ElaPushButton("Custom", this);
    customBoxButton->setFixedWidth(100);
    connect(customBoxButton, &ElaPushButton::clicked, this, [=]() {
        ElaMessageBox box(this);
        box.setTitle("自定义对话框");
        box.setText("这是一个自定义的消息框示例");
        box.setInformativeText("您可以自定义按钮、图标和文本内容");
        box.setIcon(QMessageBox::Information);
        box.setStandardButtons(QMessageBox::Ok | QMessageBox::Help | QMessageBox::Cancel);
        box.setButtonText(QMessageBox::Ok, "确认操作");
        box.setButtonText(QMessageBox::Cancel, "稍后处理");
        box.setDefaultButton(QMessageBox::Ok);
        box.setEscapeButton(QMessageBox::Cancel)
            ;
        
        auto result = box.execForResult();
        if (result == QMessageBox::Ok) {
            ElaMessageBox::information(this, "结果", "您点击了\"确认操作\"");
        } else if (result == QMessageBox::Help) {
            ElaMessageBox::information(this, "帮助", "这里是帮助信息");
        }
    });

    ElaPushButton* aboutBoxButton = new ElaPushButton("About", this);
    aboutBoxButton->setFixedWidth(100);
    connect(aboutBoxButton, &ElaPushButton::clicked, this, [=]() {
        ElaMessageBox::about(this, "关于", "ElaWidgetTools - 基于 Qt 的现代化 Fluent UI 组件库\n\n版本：2.0.0\n作者：Liniyous\n许可证：MIT");
    });

    ElaScrollPageArea* messageBoxArea = new ElaScrollPageArea(this);
    QHBoxLayout* messageBoxLayout = new QHBoxLayout(messageBoxArea);
    ElaText* messageBoxText = new ElaText("ElaMessageBox", this);
    messageBoxText->setTextPixelSize(15);
    messageBoxLayout->addWidget(messageBoxText);
    messageBoxLayout->addWidget(informationBoxButton);
    messageBoxLayout->addWidget(questionBoxButton);
    messageBoxLayout->addWidget(warningBoxButton);
    messageBoxLayout->addWidget(criticalBoxButton);
    messageBoxLayout->addWidget(customBoxButton);
    messageBoxLayout->addWidget(aboutBoxButton);
    messageBoxLayout->addStretch();
    ElaToggleSwitch* messageBoxDisableSwitch = new ElaToggleSwitch(this);
    ElaText* messageBoxDisableText = new ElaText("禁用", this);
    messageBoxDisableText->setTextPixelSize(15);
    connect(messageBoxDisableSwitch, &ElaToggleSwitch::toggled, this, [=](bool checked) {
        informationBoxButton->setDisabled(checked);
        questionBoxButton->setDisabled(checked);
        warningBoxButton->setDisabled(checked);
        criticalBoxButton->setDisabled(checked);
        customBoxButton->setDisabled(checked);
        aboutBoxButton->setDisabled(checked);
    });
    messageBoxLayout->addWidget(messageBoxDisableSwitch);
    messageBoxLayout->addWidget(messageBoxDisableText);
    messageBoxLayout->addSpacing(10);

    // ElaInputDialog 示例区域
    ElaPushButton* getTextButton = new ElaPushButton("Text", this);
    getTextButton->setFixedWidth(80);
    connect(getTextButton, &ElaPushButton::clicked, this, [=]() {
        bool ok;
        QString text = ElaInputDialog::getText(this, "输入文本", "请输入您的姓名：",
                                              QLineEdit::Normal, "默认文本", &ok);
        if (ok && !text.isEmpty()) {
            ElaMessageBox::information(this, "输入结果", QString("您输入的文本是：%1").arg(text));
        }
    });

    ElaPushButton* getIntButton = new ElaPushButton("Integer", this);
    getIntButton->setFixedWidth(80);
    connect(getIntButton, &ElaPushButton::clicked, this, [=]() {
        bool ok;
        int value = ElaInputDialog::getInt(this, "输入整数", "请输入一个数字（0-100）：",
                                          50, 0, 100, 1, &ok);
        if (ok) {
            ElaMessageBox::information(this, "输入结果", QString("您输入的整数是：%1").arg(value));
        }
    });

    ElaPushButton* getDoubleButton = new ElaPushButton("Double", this);
    getDoubleButton->setFixedWidth(80);
    connect(getDoubleButton, &ElaPushButton::clicked, this, [=]() {
        bool ok;
        double value = ElaInputDialog::getDouble(this, "输入小数", "请输入一个小数（0.0-10.0）：",
                                                3.14, 0.0, 10.0, 2, &ok);
        if (ok) {
            ElaMessageBox::information(this, "输入结果", QString("您输入的小数是：%1").arg(value));
        }
    });

    ElaPushButton* getItemButton = new ElaPushButton("Item", this);
    getItemButton->setFixedWidth(80);
    connect(getItemButton, &ElaPushButton::clicked, this, [=]() {
        QStringList items;
        items << "春季" << "夏季" << "秋季" << "冬季";
        bool ok;
        QString item = ElaInputDialog::getItem(this, "选择项目", "请选择您喜欢的季节：",
                                              items, 0, false, &ok);
        if (ok && !item.isEmpty()) {
            ElaMessageBox::information(this, "选择结果", QString("您选择的是：%1").arg(item));
        }
    });

    ElaPushButton* getMultiLineButton = new ElaPushButton("MultiLine", this);
    getMultiLineButton->setFixedWidth(80);
    connect(getMultiLineButton, &ElaPushButton::clicked, this, [=]() {
        bool ok;
        QString text = ElaInputDialog::getMultiLineText(this, "输入多行文本", "请输入您的留言：",
                                                       "在此输入多行文本...", &ok);
        if (ok && !text.isEmpty()) {
            ElaMessageBox::information(this, "输入结果", QString("您输入的文本是：\n%1").arg(text));
        }
    });

    ElaPushButton* getPasswordButton = new ElaPushButton("Password", this);
    getPasswordButton->setFixedWidth(80);
    connect(getPasswordButton, &ElaPushButton::clicked, this, [=]() {
        bool ok;
        QString password = ElaInputDialog::getText(this, "输入密码", "请输入您的密码：",
                                                  QLineEdit::Password, "", &ok);
        if (ok && !password.isEmpty()) {
            ElaMessageBox::information(this, "输入结果", QString("密码长度：%1 位").arg(password.length()));
        }
    });

    ElaScrollPageArea* inputDialogArea = new ElaScrollPageArea(this);
    QHBoxLayout* inputDialogLayout = new QHBoxLayout(inputDialogArea);
    ElaText* inputDialogText = new ElaText("ElaInputDialog", this);
    inputDialogText->setTextPixelSize(15);
    inputDialogLayout->addWidget(inputDialogText);
    inputDialogLayout->addWidget(getTextButton);
    inputDialogLayout->addWidget(getIntButton);
    inputDialogLayout->addWidget(getDoubleButton);
    inputDialogLayout->addWidget(getItemButton);
    inputDialogLayout->addWidget(getMultiLineButton);
    inputDialogLayout->addWidget(getPasswordButton);
    inputDialogLayout->addStretch();
    ElaToggleSwitch* inputDialogDisableSwitch = new ElaToggleSwitch(this);
    ElaText* inputDialogDisableText = new ElaText("禁用", this);
    inputDialogDisableText->setTextPixelSize(15);
    connect(inputDialogDisableSwitch, &ElaToggleSwitch::toggled, this, [=](bool checked) {
        getTextButton->setDisabled(checked);
        getIntButton->setDisabled(checked);
        getDoubleButton->setDisabled(checked);
        getItemButton->setDisabled(checked);
        getMultiLineButton->setDisabled(checked);
        getPasswordButton->setDisabled(checked);
    });
    inputDialogLayout->addWidget(inputDialogDisableSwitch);
    inputDialogLayout->addWidget(inputDialogDisableText);
    inputDialogLayout->addSpacing(10);

    _checkBox = new ElaCheckBox("CheckBox", this);
    ElaScrollPageArea* checkBoxArea = new ElaScrollPageArea(this);
    QHBoxLayout* checkBoxLayout = new QHBoxLayout(checkBoxArea);
    ElaText* checkBoxText = new ElaText("ElacheckBox", this);
    checkBoxText->setTextPixelSize(15);
    checkBoxLayout->addWidget(checkBoxText);
    checkBoxLayout->addWidget(_checkBox);
    checkBoxLayout->addStretch();
    ElaToggleSwitch* checkBoxDisableSwitch = new ElaToggleSwitch(this);
    ElaText* checkBoxDisableText = new ElaText("禁用", this);
    checkBoxDisableText->setTextPixelSize(15);
    connect(checkBoxDisableSwitch, &ElaToggleSwitch::toggled, this, [=](bool checked) {
        _checkBox->setDisabled(checked);
    });
    checkBoxLayout->addWidget(checkBoxDisableSwitch);
    checkBoxLayout->addWidget(checkBoxDisableText);
    checkBoxLayout->addSpacing(10);

    _spinBox = new ElaSpinBox(this);
    ElaScrollPageArea* spinBoxArea = new ElaScrollPageArea(this);
    QHBoxLayout* spinBoxLayout = new QHBoxLayout(spinBoxArea);
    ElaText* spinBoxText = new ElaText("ElaSpinBox", this);
    spinBoxText->setTextPixelSize(15);
    spinBoxLayout->addWidget(spinBoxText);
    spinBoxLayout->addWidget(_spinBox);
    spinBoxLayout->addStretch();

    ElaRadioButton* inlineButton = new ElaRadioButton("Inline", this);
    ElaRadioButton* compactButton = new ElaRadioButton("Compact", this);
    ElaRadioButton* sideButton = new ElaRadioButton("Side", this);
    ElaRadioButton* pmSideButton = new ElaRadioButton("PMSide", this);
    inlineButton->setChecked(true);
    QHBoxLayout* buttonModeLayout = new QHBoxLayout();
    ElaText* buttonModeText = new ElaText("按钮模式切换", this);
    buttonModeText->setWordWrap(false);
    buttonModeText->setTextPixelSize(15);
    buttonModeLayout->addWidget(buttonModeText);
    buttonModeLayout->addWidget(inlineButton);
    buttonModeLayout->addWidget(compactButton);
    buttonModeLayout->addWidget(sideButton);
    buttonModeLayout->addWidget(pmSideButton);

    spinBoxLayout->addLayout(buttonModeLayout);

    QButtonGroup* spinButtonGroup = new QButtonGroup(this);
    spinButtonGroup->addButton(inlineButton, 0);
    spinButtonGroup->addButton(compactButton, 1);
    spinButtonGroup->addButton(sideButton, 2);
    spinButtonGroup->addButton(pmSideButton, 3);
    connect(spinButtonGroup, QOverload<QAbstractButton*, bool>::of(&QButtonGroup::buttonToggled), this, [=](QAbstractButton* button, bool isToggled) {
        if (isToggled)
        {
            _spinBox->setButtonMode((ElaSpinBoxType::ButtonMode)spinButtonGroup->id(button));
        }
    });

    _slider = new ElaSlider(this);
    ElaScrollPageArea* sliderArea = new ElaScrollPageArea(this);
    QHBoxLayout* sliderLayout = new QHBoxLayout(sliderArea);
    ElaText* sliderText = new ElaText("ElaSlider", this);
    sliderText->setTextPixelSize(15);
    sliderLayout->addWidget(sliderText);
    sliderLayout->addWidget(_slider);
    sliderLayout->addStretch();

    _radioButton = new ElaRadioButton("RadioButton", this);
    ElaScrollPageArea* radioButtonArea = new ElaScrollPageArea(this);
    QHBoxLayout* radioButtonLayout = new QHBoxLayout(radioButtonArea);
    ElaText* radioButtonText = new ElaText("ElaRadioButton", this);
    radioButtonText->setTextPixelSize(15);
    radioButtonLayout->addWidget(radioButtonText);
    radioButtonLayout->addWidget(_radioButton);
    radioButtonLayout->addStretch();

    _progressBar = new ElaProgressBar(this);
    _progressBar->setMinimum(0);
    _progressBar->setMaximum(0);
    ElaScrollPageArea* progressBarArea = new ElaScrollPageArea(this);
    QHBoxLayout* progressBarLayout = new QHBoxLayout(progressBarArea);
    ElaText* progressBarText = new ElaText("ElaProgressBar", this);
    progressBarText->setTextPixelSize(15);
    progressBarLayout->addWidget(progressBarText);
    progressBarLayout->addWidget(_progressBar);
    progressBarLayout->addStretch();

    _progressRing = new ElaProgressRing(this);
    _progressRing->setValue(30);
    _progressPercentRing = new ElaProgressRing(this);
    _progressPercentRing->setValue(50);
    _progressPercentRing->setValueDisplayMode(ElaProgressRingType::ValueDisplayMode::Percent);
    _progressBusyRing = new ElaProgressRing(this);
    _progressBusyRing->setIsBusying(true);
    _progressBusyTransparentRing = new ElaProgressRing(this);
    _progressBusyTransparentRing->setIsBusying(true);
    _progressBusyTransparentRing->setIsTransparent(true);
    ElaScrollPageArea* progressRingArea = new ElaScrollPageArea(this);
    progressRingArea->setFixedHeight(90);
    QHBoxLayout* progressRingLayout = new QHBoxLayout(progressRingArea);
    ElaText* progressRingText = new ElaText("ElaProgressRing", this);
    progressRingText->setTextPixelSize(15);
    progressRingLayout->addWidget(progressRingText);
    progressRingLayout->addWidget(_progressRing);
    progressRingLayout->addSpacing(10);
    progressRingLayout->addWidget(_progressPercentRing);
    progressRingLayout->addSpacing(10);
    progressRingLayout->addWidget(_progressBusyRing);
    progressRingLayout->addSpacing(10);
    progressRingLayout->addWidget(_progressBusyTransparentRing);
    progressRingLayout->addStretch();

    ElaPlainTextEdit* edit = new ElaPlainTextEdit(this);
    edit->setPlainText("这是一个ElaPlainTextEdit  暂时放在这里");
    _pushButton1 = new ElaPushButton("primary", this);
    _pushButton1->setButtonAppearance(ElaPushButtonType::Appearance::Primary);

    _pushButton2 = new ElaPushButton("circular", this);
    _pushButton2->setButtonShape(ElaPushButtonType::Shape::Circular);

    // ElaToolButtons
    _toolButton1 = new ElaToolButton(this);
    // _toolButton1->setText("primary");
    _toolButton1->setElaIcon(ElaIconType::Play);
    _toolButton1->setButtonAppearance(ElaPushButtonType::Appearance::Primary);

    _toolButton2 = new ElaToolButton(this);
    _toolButton2->setText("outline");
    _toolButton2->setButtonAppearance(ElaPushButtonType::Appearance::Outline);

    ElaScrollPageArea* buttonArea = new ElaScrollPageArea(this);
    QHBoxLayout* buttonLayout = new QHBoxLayout(buttonArea);
    ElaText* buttonText = new ElaText("ElaPushButton", this);
    buttonText->setTextPixelSize(15);
    buttonLayout->addWidget(buttonText);
    buttonLayout->addWidget(_pushButton1);
    buttonLayout->addWidget(_pushButton2);
    buttonLayout->addWidget(_toolButton1);
    buttonLayout->addWidget(_toolButton2);
    buttonLayout->addStretch();

    QWidget* centralWidget = new QWidget(this);
    centralWidget->setWindowTitle("ElaBaseComponents");
    QVBoxLayout* centerLayout = new QVBoxLayout(centralWidget);
    centerLayout->addWidget(toggleSwitchArea);
    centerLayout->addWidget(toggleButtonArea);
    centerLayout->addWidget(comboBoxArea);
    centerLayout->addWidget(multiSelectComboBoxArea);
    centerLayout->addWidget(messageButtonArea);
    centerLayout->addWidget(messageBoxArea);
    centerLayout->addWidget(inputDialogArea);
    centerLayout->addWidget(checkBoxArea);
    centerLayout->addWidget(spinBoxArea);
    centerLayout->addWidget(sliderArea);
    centerLayout->addWidget(radioButtonArea);
    centerLayout->addWidget(progressBarArea);
    centerLayout->addWidget(progressRingArea);
    centerLayout->addWidget(buttonArea);
    centerLayout->addWidget(edit);
    centerLayout->addStretch();
    centerLayout->setContentsMargins(0, 0, 0, 0);
    addCentralWidget(centralWidget, true, true, 0);

    ElaText* homeStack1 = new ElaText("HomeStack1", this);
    QFont font = homeStack1->font();
    font.setPixelSize(32);
    homeStack1->setFont(font);
    homeStack1->setAlignment(Qt::AlignCenter);
    homeStack1->setWindowTitle("HomeStack1");
    addCentralWidget(homeStack1);
    ElaText* homeStack2 = new ElaText("HomeStack2", this);
    homeStack2->setFont(font);
    homeStack2->setAlignment(Qt::AlignCenter);
    homeStack2->setWindowTitle("HomeStack2");
    addCentralWidget(homeStack2);
}

T_BaseComponents::~T_BaseComponents()
{
}

void T_BaseComponents::mouseReleaseEvent(QMouseEvent* event)
{
    switch (event->button())
    {
    case Qt::LeftButton:
    {
        //ElaMessageBar::success(ElaMessageBarType::TopRight, "Success", "Never Close Your Eyes", 2500);
        //ElaMessageBar::success(ElaMessageBarType::TopRight, "Success", "Never Close Your Eyes", 1500);
        break;
    }
    case Qt::BackButton:
    {
        this->navigation(0);
        break;
    }
    case Qt::ForwardButton:
    {
        this->navigation(1);
        break;
    }
    case Qt::MiddleButton:
    {
        this->navigation(2);
        break;
    }
    default:
    {
        break;
    }
    }
    ElaScrollPage::mouseReleaseEvent(event);
}
