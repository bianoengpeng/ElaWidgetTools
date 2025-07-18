﻿#ifndef T_BASECOMPONENTS_H
#define T_BASECOMPONENTS_H

#include "T_BasePage.h"

class ElaToggleSwitch;
class ElaToggleButton;
class ElaComboBox;
class ElaMultiSelectComboBox;
class ElaMessageButton;
class ElaCheckBox;
class ElaSpinBox;
class ElaSlider;
class ElaRadioButton;
class ElaProgressBar;
class ElaProgressRing;
class ElaPushButton;
class ElaToolButton;
class T_BaseComponents : public T_BasePage
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit T_BaseComponents(QWidget* parent = nullptr);
    ~T_BaseComponents() override;

protected:
    virtual void mouseReleaseEvent(QMouseEvent* event);

private:
    ElaToggleSwitch* _toggleSwitch{nullptr};
    ElaToggleButton* _toggleButton{nullptr};
    ElaComboBox* _comboBox{nullptr};
    ElaMultiSelectComboBox* _multiSelectComboBox{nullptr};
    ElaMessageButton* _messageButton{nullptr};
    ElaMessageButton* _infoMessageButton{nullptr};
    ElaMessageButton* _warningMessageButton{nullptr};
    ElaMessageButton* _errorMessageButton{nullptr};
    ElaCheckBox* _checkBox{nullptr};
    ElaSpinBox* _spinBox{nullptr};
    ElaSlider* _slider{nullptr};
    ElaRadioButton* _radioButton{nullptr};
    ElaProgressBar* _progressBar{nullptr};
    ElaProgressRing* _progressRing{nullptr};
    ElaProgressRing* _progressPercentRing{nullptr};
    ElaProgressRing* _progressBusyRing{nullptr};
    ElaProgressRing* _progressBusyTransparentRing{nullptr};
	
	ElaPushButton* _pushButton1{nullptr};
    ElaPushButton* _pushButton2{nullptr};
    ElaPushButton* _pushButton4{nullptr};
    ElaToolButton* _toolButton1{nullptr};
    ElaToolButton* _toolButton2{nullptr};
};

#endif // T_BASECOMPONENTS_H
