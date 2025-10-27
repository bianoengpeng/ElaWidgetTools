#include "ElaThemePrivate.h"

ElaThemePrivate::ElaThemePrivate(QObject* parent)
    : QObject{parent}
{
}

ElaThemePrivate::~ElaThemePrivate()
{
}

void ElaThemePrivate::_initThemeColor()
{
    //ElaScrollBar
    _lightThemeColorList[ElaThemeType::ScrollBarHandle] = QColor(0xA0, 0xA0, 0xA0);
    _darkThemeColorList[ElaThemeType::ScrollBarHandle] = QColor(0x9F, 0x9F, 0x9F);

    //ElaToggleSwitch
    _lightThemeColorList[ElaThemeType::ToggleSwitchNoToggledCenter] = QColor(0x5A, 0x5A, 0x5A);
    _darkThemeColorList[ElaThemeType::ToggleSwitchNoToggledCenter] = QColor(0xD0, 0xD0, 0xD0);

    // 主题颜色
    _lightThemeColorList[ElaThemeType::PrimaryNormal] = QColor(0x00, 0x67, 0xC0);
    _darkThemeColorList[ElaThemeType::PrimaryNormal] = QColor(0x4C, 0xC2, 0xFF);
    _lightThemeColorList[ElaThemeType::PrimaryHover] = QColor(0x19, 0x75, 0xC5);
    _darkThemeColorList[ElaThemeType::PrimaryHover] = QColor(0x47, 0xB1, 0xE8);
    _lightThemeColorList[ElaThemeType::PrimaryPress] = QColor(0x31, 0x83, 0xCA);
    _darkThemeColorList[ElaThemeType::PrimaryPress] = QColor(0x42, 0xA1, 0xD2);

    // 通用颜色
    // 普通窗体
    _lightThemeColorList[ElaThemeType::WindowBase] = QColor(0xF3, 0xF3, 0xF3);
    _darkThemeColorList[ElaThemeType::WindowBase] = QColor(0x20, 0x20, 0x20);
    _lightThemeColorList[ElaThemeType::WindowCentralStackBase] = QColor(0xFF, 0xFF, 0xFF, 80);
    _darkThemeColorList[ElaThemeType::WindowCentralStackBase] = QColor(0x3E, 0x3E, 0x3E, 60);

    // 浮动窗体
    _lightThemeColorList[ElaThemeType::PopupBorder] = QColor(0xD6, 0xD6, 0xD6);
    _darkThemeColorList[ElaThemeType::PopupBorder] = QColor(0x47, 0x47, 0x47);
    _lightThemeColorList[ElaThemeType::PopupBorderHover] = QColor(0xCC, 0xCC, 0xCC);
    _darkThemeColorList[ElaThemeType::PopupBorderHover] = QColor(0x54, 0x54, 0x54);
    _lightThemeColorList[ElaThemeType::PopupBase] = QColor(0xFA, 0xFA, 0xFA);
    _darkThemeColorList[ElaThemeType::PopupBase] = QColor(0x2C, 0x2C, 0x2C);
    _lightThemeColorList[ElaThemeType::PopupHover] = QColor(0xF0, 0xF0, 0xF0);
    _darkThemeColorList[ElaThemeType::PopupHover] = QColor(0x38, 0x38, 0x38);

    // Dialog窗体
    _lightThemeColorList[ElaThemeType::DialogBase] = Qt::white;
    _darkThemeColorList[ElaThemeType::DialogBase] = QColor(0x1F, 0x1F, 0x1F);
    _lightThemeColorList[ElaThemeType::DialogLayoutArea] = QColor(0xF3, 0xF3, 0xF3);
    _darkThemeColorList[ElaThemeType::DialogLayoutArea] = QColor(0x20, 0x20, 0x20);

    // 基础颜色
    _lightThemeColorList[ElaThemeType::BasicText] = Qt::black;
    _darkThemeColorList[ElaThemeType::BasicText] = Qt::white;
    _lightThemeColorList[ElaThemeType::BasicTextInvert] = Qt::white;
    _darkThemeColorList[ElaThemeType::BasicTextInvert] = Qt::black;
    _lightThemeColorList[ElaThemeType::BasicDetailsText] = QColor(0x87, 0x87, 0x87);
    _darkThemeColorList[ElaThemeType::BasicDetailsText] = QColor(0xAD, 0xAD, 0xB0);
    _lightThemeColorList[ElaThemeType::BasicTextNoFocus] = QColor(0x86, 0x86, 0x8A);
    _darkThemeColorList[ElaThemeType::BasicTextNoFocus] = QColor(0x86, 0x86, 0x8A);
    _lightThemeColorList[ElaThemeType::BasicTextDisable] = QColor(0xB6, 0xB6, 0xB6);
    _darkThemeColorList[ElaThemeType::BasicTextDisable] = QColor(0xA7, 0xA7, 0xA7);
    _lightThemeColorList[ElaThemeType::BasicTextPress] = QColor(0x5A, 0x5A, 0x5D);
    _darkThemeColorList[ElaThemeType::BasicTextPress] = QColor(0xBB, 0xBB, 0xBF);
    _lightThemeColorList[ElaThemeType::BasicBorder] = QColor(0xE5, 0xE5, 0xE5);
    _darkThemeColorList[ElaThemeType::BasicBorder] = QColor(0x4B, 0x4B, 0x4B);
    _lightThemeColorList[ElaThemeType::BasicBorderDeep] = QColor(0xA8, 0xA8, 0xA8);
    _darkThemeColorList[ElaThemeType::BasicBorderDeep] = QColor(0x5C, 0x5C, 0x5C);
    _lightThemeColorList[ElaThemeType::BasicBorderHover] = QColor(0xDA, 0xDA, 0xDA);
    _darkThemeColorList[ElaThemeType::BasicBorderHover] = QColor(0x57, 0x57, 0x57);
    _lightThemeColorList[ElaThemeType::BasicBase] = QColor(0xFD, 0xFD, 0xFD);
    _darkThemeColorList[ElaThemeType::BasicBase] = QColor(0x34, 0x34, 0x34);
    _lightThemeColorList[ElaThemeType::BasicBaseDeep] = QColor(0xE6, 0xE6, 0xE6);
    _darkThemeColorList[ElaThemeType::BasicBaseDeep] = QColor(0x61, 0x61, 0x61);
    _lightThemeColorList[ElaThemeType::BasicDisable] = QColor(0xF5, 0xF5, 0xF5);
    _darkThemeColorList[ElaThemeType::BasicDisable] = QColor(0x2A, 0x2A, 0x2A);
    _lightThemeColorList[ElaThemeType::BasicHover] = QColor(0xF3, 0xF3, 0xF3);
    _darkThemeColorList[ElaThemeType::BasicHover] = QColor(0x40, 0x40, 0x40);
    _lightThemeColorList[ElaThemeType::BasicPress] = QColor(0xF7, 0xF7, 0xF7);
    _darkThemeColorList[ElaThemeType::BasicPress] = QColor(0x3A, 0x3A, 0x3A);
    _lightThemeColorList[ElaThemeType::BasicSelectedHover] = QColor(0xEB, 0xEB, 0xEB);
    _darkThemeColorList[ElaThemeType::BasicSelectedHover] = QColor(0x38, 0x38, 0x38);
    _lightThemeColorList[ElaThemeType::BasicBaseLine] = QColor(0xD1, 0xD1, 0xD1);
    _darkThemeColorList[ElaThemeType::BasicBaseLine] = QColor(0x45, 0x45, 0x45);
    _lightThemeColorList[ElaThemeType::BasicHemline] = QColor(0x86, 0x86, 0x86);
    _darkThemeColorList[ElaThemeType::BasicHemline] = QColor(0x9A, 0x9A, 0x9A);
    _lightThemeColorList[ElaThemeType::BasicIndicator] = QColor(0x75, 0x7C, 0x87);
    _darkThemeColorList[ElaThemeType::BasicIndicator] = QColor(0x75, 0x7C, 0x87);
    _lightThemeColorList[ElaThemeType::BasicChute] = QColor(0xB3, 0xB3, 0xB3);
    _darkThemeColorList[ElaThemeType::BasicChute] = QColor(0x63, 0x63, 0x63);

    // 基础透明
    _lightThemeColorList[ElaThemeType::BasicAlternating] = QColor(0xEF, 0xEF, 0xEF, 160);
    _darkThemeColorList[ElaThemeType::BasicAlternating] = QColor(0x45, 0x45, 0x45, 125);
    _lightThemeColorList[ElaThemeType::BasicBaseAlpha] = QColor(0xFF, 0xFF, 0xFF, 160);
    _darkThemeColorList[ElaThemeType::BasicBaseAlpha] = QColor(0x2D, 0x2D, 0x2D, 95);
    _lightThemeColorList[ElaThemeType::BasicBaseDeepAlpha] = QColor(0xCC, 0xCC, 0xCC, 160);
    _darkThemeColorList[ElaThemeType::BasicBaseDeepAlpha] = QColor(0x72, 0x72, 0x72, 95);
    _lightThemeColorList[ElaThemeType::BasicHoverAlpha] = QColor(0xCC, 0xCC, 0xCC, 70);
    _darkThemeColorList[ElaThemeType::BasicHoverAlpha] = QColor(0x4B, 0x4B, 0x4B, 75);
    _lightThemeColorList[ElaThemeType::BasicPressAlpha] = QColor(0xCC, 0xCC, 0xCC, 40);
    _darkThemeColorList[ElaThemeType::BasicPressAlpha] = QColor(0x4B, 0x4B, 0x4B, 55);
    _lightThemeColorList[ElaThemeType::BasicSelectedAlpha] = QColor(0xCC, 0xCC, 0xCC, 70);
    _darkThemeColorList[ElaThemeType::BasicSelectedAlpha] = QColor(0x4B, 0x4B, 0x4B, 75);
    _lightThemeColorList[ElaThemeType::BasicSelectedHoverAlpha] = QColor(0xCC, 0xCC, 0xCC, 40);
    _darkThemeColorList[ElaThemeType::BasicSelectedHoverAlpha] = QColor(0x4B, 0x4B, 0x4B, 55);

    // 状态颜色
    _lightThemeColorList[ElaThemeType::StatusDanger] = QColor(0xE8, 0x11, 0x23);
    _darkThemeColorList[ElaThemeType::StatusDanger] = QColor(0xE8, 0x11, 0x23);

    // ========== Fluent UI v9 色彩初始化（严格顺序，先darkTheme再lightTheme） ==========

    // colorNeutralForeground1
    _darkThemeColorList[ElaThemeType::colorNeutralForeground1] = QColor(0xFF, 0xFF, 0xFF); // #ffffff
    _lightThemeColorList[ElaThemeType::colorNeutralForeground1] = QColor(0x24, 0x24, 0x24); // #242424

    // colorNeutralForeground1Hover
    _darkThemeColorList[ElaThemeType::colorNeutralForeground1Hover] = QColor(0xFF, 0xFF, 0xFF); // #ffffff
    _lightThemeColorList[ElaThemeType::colorNeutralForeground1Hover] = QColor(0x24, 0x24, 0x24); // #242424

    // colorNeutralForeground1Pressed
    _darkThemeColorList[ElaThemeType::colorNeutralForeground1Pressed] = QColor(0xFF, 0xFF, 0xFF); // #ffffff
    _lightThemeColorList[ElaThemeType::colorNeutralForeground1Pressed] = QColor(0x24, 0x24, 0x24); // #242424

    // colorNeutralForeground1Selected
    _darkThemeColorList[ElaThemeType::colorNeutralForeground1Selected] = QColor(0xFF, 0xFF, 0xFF); // #ffffff
    _lightThemeColorList[ElaThemeType::colorNeutralForeground1Selected] = QColor(0x24, 0x24, 0x24); // #242424

    // colorNeutralForeground2
    _darkThemeColorList[ElaThemeType::colorNeutralForeground2] = QColor(0xD6, 0xD6, 0xD6); // #d6d6d6
    _lightThemeColorList[ElaThemeType::colorNeutralForeground2] = QColor(0x42, 0x42, 0x42); // #424242

    // colorNeutralForeground2Hover
    _darkThemeColorList[ElaThemeType::colorNeutralForeground2Hover] = QColor(0xFF, 0xFF, 0xFF); // #ffffff
    _lightThemeColorList[ElaThemeType::colorNeutralForeground2Hover] = QColor(0x24, 0x24, 0x24); // #242424

    // colorNeutralForeground2Pressed
    _darkThemeColorList[ElaThemeType::colorNeutralForeground2Pressed] = QColor(0xFF, 0xFF, 0xFF); // #ffffff
    _lightThemeColorList[ElaThemeType::colorNeutralForeground2Pressed] = QColor(0x24, 0x24, 0x24); // #242424

    // colorNeutralForeground2Selected
    _darkThemeColorList[ElaThemeType::colorNeutralForeground2Selected] = QColor(0xFF, 0xFF, 0xFF); // #ffffff
    _lightThemeColorList[ElaThemeType::colorNeutralForeground2Selected] = QColor(0x24, 0x24, 0x24); // #242424

    // colorNeutralForeground2BrandHover
    _darkThemeColorList[ElaThemeType::colorNeutralForeground2BrandHover] = QColor(0x47, 0x9E, 0xF5); // #479ef5
    _lightThemeColorList[ElaThemeType::colorNeutralForeground2BrandHover] = QColor(0x0F, 0x6C, 0xBD); // #0f6cbd

    // colorNeutralForeground2BrandPressed
    _darkThemeColorList[ElaThemeType::colorNeutralForeground2BrandPressed] = QColor(0x28, 0x86, 0xDE); // #2886de
    _lightThemeColorList[ElaThemeType::colorNeutralForeground2BrandPressed] = QColor(0x11, 0x5E, 0xA3); // #115ea3

    // colorNeutralForeground2BrandSelected
    _darkThemeColorList[ElaThemeType::colorNeutralForeground2BrandSelected] = QColor(0x47, 0x9E, 0xF5); // #479ef5
    _lightThemeColorList[ElaThemeType::colorNeutralForeground2BrandSelected] = QColor(0x0F, 0x6C, 0xBD); // #0f6cbd

    // colorNeutralForeground3
    _darkThemeColorList[ElaThemeType::colorNeutralForeground3] = QColor(0xAD, 0xAD, 0xAD); // #adadad
    _lightThemeColorList[ElaThemeType::colorNeutralForeground3] = QColor(0x61, 0x61, 0x61); // #616161

    // colorNeutralForeground3Hover
    _darkThemeColorList[ElaThemeType::colorNeutralForeground3Hover] = QColor(0xD6, 0xD6, 0xD6); // #d6d6d6
    _lightThemeColorList[ElaThemeType::colorNeutralForeground3Hover] = QColor(0x42, 0x42, 0x42); // #424242

    // colorNeutralForeground3Pressed
    _darkThemeColorList[ElaThemeType::colorNeutralForeground3Pressed] = QColor(0xD6, 0xD6, 0xD6); // #d6d6d6
    _lightThemeColorList[ElaThemeType::colorNeutralForeground3Pressed] = QColor(0x42, 0x42, 0x42); // #424242

    // colorNeutralForeground3Selected
    _darkThemeColorList[ElaThemeType::colorNeutralForeground3Selected] = QColor(0xD6, 0xD6, 0xD6); // #d6d6d6
    _lightThemeColorList[ElaThemeType::colorNeutralForeground3Selected] = QColor(0x42, 0x42, 0x42); // #424242

    // colorNeutralForeground3BrandHover
    _darkThemeColorList[ElaThemeType::colorNeutralForeground3BrandHover] = QColor(0x47, 0x9E, 0xF5); // #479ef5
    _lightThemeColorList[ElaThemeType::colorNeutralForeground3BrandHover] = QColor(0x0F, 0x6C, 0xBD); // #0f6cbd

    // colorNeutralForeground3BrandPressed
    _darkThemeColorList[ElaThemeType::colorNeutralForeground3BrandPressed] = QColor(0x28, 0x86, 0xDE); // #2886de
    _lightThemeColorList[ElaThemeType::colorNeutralForeground3BrandPressed] = QColor(0x11, 0x5E, 0xA3); // #115ea3

    // colorNeutralForeground3BrandSelected
    _darkThemeColorList[ElaThemeType::colorNeutralForeground3BrandSelected] = QColor(0x47, 0x9E, 0xF5); // #479ef5
    _lightThemeColorList[ElaThemeType::colorNeutralForeground3BrandSelected] = QColor(0x0F, 0x6C, 0xBD); // #0f6cbd

    // colorNeutralForeground4
    _darkThemeColorList[ElaThemeType::colorNeutralForeground4] = QColor(0x99, 0x99, 0x99); // #999999
    _lightThemeColorList[ElaThemeType::colorNeutralForeground4] = QColor(0x70, 0x70, 0x70); // #707070

    // colorNeutralForegroundDisabled
    _darkThemeColorList[ElaThemeType::colorNeutralForegroundDisabled] = QColor(0x5C, 0x5C, 0x5C); // #5c5c5c
    _lightThemeColorList[ElaThemeType::colorNeutralForegroundDisabled] = QColor(0xBD, 0xBD, 0xBD); // #bdbdbd

    // colorNeutralForegroundInvertedDisabled
    _darkThemeColorList[ElaThemeType::colorNeutralForegroundInvertedDisabled] = QColor(255, 255, 255, 102); // rgba(255,255,255,0.4)
    _lightThemeColorList[ElaThemeType::colorNeutralForegroundInvertedDisabled] = QColor(255, 255, 255, 102); // rgba(255,255,255,0.4)

    // colorBrandForegroundLink
    _darkThemeColorList[ElaThemeType::colorBrandForegroundLink] = QColor(0x47, 0x9E, 0xF5); // #479ef5
    _lightThemeColorList[ElaThemeType::colorBrandForegroundLink] = QColor(0x11, 0x5E, 0xA3); // #115ea3

    // colorBrandForegroundLinkHover
    _darkThemeColorList[ElaThemeType::colorBrandForegroundLinkHover] = QColor(0x62, 0xAB, 0xF5); // #62abf5
    _lightThemeColorList[ElaThemeType::colorBrandForegroundLinkHover] = QColor(0x0F, 0x54, 0x8C); // #0f548c

    // colorBrandForegroundLinkPressed
    _darkThemeColorList[ElaThemeType::colorBrandForegroundLinkPressed] = QColor(0x28, 0x86, 0xDE); // #2886de
    _lightThemeColorList[ElaThemeType::colorBrandForegroundLinkPressed] = QColor(0x0C, 0x3B, 0x5E); // #0c3b5e

    // colorBrandForegroundLinkSelected
    _darkThemeColorList[ElaThemeType::colorBrandForegroundLinkSelected] = QColor(0x47, 0x9E, 0xF5); // #479ef5
    _lightThemeColorList[ElaThemeType::colorBrandForegroundLinkSelected] = QColor(0x11, 0x5E, 0xA3); // #115ea3

    // colorNeutralForeground2Link
    _darkThemeColorList[ElaThemeType::colorNeutralForeground2Link] = QColor(0xD6, 0xD6, 0xD6); // #d6d6d6
    _lightThemeColorList[ElaThemeType::colorNeutralForeground2Link] = QColor(0x42, 0x42, 0x42); // #424242

    // colorNeutralForeground2LinkHover
    _darkThemeColorList[ElaThemeType::colorNeutralForeground2LinkHover] = QColor(0xFF, 0xFF, 0xFF); // #ffffff
    _lightThemeColorList[ElaThemeType::colorNeutralForeground2LinkHover] = QColor(0x24, 0x24, 0x24); // #242424

    // colorNeutralForeground2LinkPressed
    _darkThemeColorList[ElaThemeType::colorNeutralForeground2LinkPressed] = QColor(0xFF, 0xFF, 0xFF); // #ffffff
    _lightThemeColorList[ElaThemeType::colorNeutralForeground2LinkPressed] = QColor(0x24, 0x24, 0x24); // #242424

    // colorNeutralForeground2LinkSelected
    _darkThemeColorList[ElaThemeType::colorNeutralForeground2LinkSelected] = QColor(0xFF, 0xFF, 0xFF); // #ffffff
    _lightThemeColorList[ElaThemeType::colorNeutralForeground2LinkSelected] = QColor(0x24, 0x24, 0x24); // #242424

    // colorCompoundBrandForeground1
    _darkThemeColorList[ElaThemeType::colorCompoundBrandForeground1] = QColor(0x47, 0x9E, 0xF5); // #479ef5
    _lightThemeColorList[ElaThemeType::colorCompoundBrandForeground1] = QColor(0x0F, 0x6C, 0xBD); // #0f6cbd

    // colorCompoundBrandForeground1Hover
    _darkThemeColorList[ElaThemeType::colorCompoundBrandForeground1Hover] = QColor(0x62, 0xAB, 0xF5); // #62abf5
    _lightThemeColorList[ElaThemeType::colorCompoundBrandForeground1Hover] = QColor(0x11, 0x5E, 0xA3); // #115ea3

    // colorCompoundBrandForeground1Pressed
    _darkThemeColorList[ElaThemeType::colorCompoundBrandForeground1Pressed] = QColor(0x28, 0x86, 0xDE); // #2886de
    _lightThemeColorList[ElaThemeType::colorCompoundBrandForeground1Pressed] = QColor(0x0F, 0x54, 0x8C); // #0f548c

    // colorBrandForeground1
    _darkThemeColorList[ElaThemeType::colorBrandForeground1] = QColor(0x47, 0x9E, 0xF5); // #479ef5
    _lightThemeColorList[ElaThemeType::colorBrandForeground1] = QColor(0x0F, 0x6C, 0xBD); // #0f6cbd

    // colorBrandForeground2
    _darkThemeColorList[ElaThemeType::colorBrandForeground2] = QColor(0x62, 0xAB, 0xF5); // #62abf5
    _lightThemeColorList[ElaThemeType::colorBrandForeground2] = QColor(0x11, 0x5E, 0xA3); // #115ea3

    // colorBrandForeground2Hover
    _darkThemeColorList[ElaThemeType::colorBrandForeground2Hover] = QColor(0x96, 0xC6, 0xFA); // #96c6fa
    _lightThemeColorList[ElaThemeType::colorBrandForeground2Hover] = QColor(0x0F, 0x54, 0x8C); // #0f548c

    // colorBrandForeground2Pressed
    _darkThemeColorList[ElaThemeType::colorBrandForeground2Pressed] = QColor(0xEB, 0xF3, 0xFC); // #ebf3fc
    _lightThemeColorList[ElaThemeType::colorBrandForeground2Pressed] = QColor(0x0A, 0x2E, 0x4A); // #0a2e4a

    // colorNeutralForeground1Static
    _darkThemeColorList[ElaThemeType::colorNeutralForeground1Static] = QColor(0x24, 0x24, 0x24); // #242424
    _lightThemeColorList[ElaThemeType::colorNeutralForeground1Static] = QColor(0x24, 0x24, 0x24); // #242424

    // colorNeutralForegroundStaticInverted
    _darkThemeColorList[ElaThemeType::colorNeutralForegroundStaticInverted] = QColor(0xFF, 0xFF, 0xFF); // #ffffff
    _lightThemeColorList[ElaThemeType::colorNeutralForegroundStaticInverted] = QColor(0xFF, 0xFF, 0xFF); // #ffffff

    // colorNeutralForegroundInverted
    _darkThemeColorList[ElaThemeType::colorNeutralForegroundInverted] = QColor(0x24, 0x24, 0x24); // #242424
    _lightThemeColorList[ElaThemeType::colorNeutralForegroundInverted] = QColor(0xFF, 0xFF, 0xFF); // #ffffff

    // colorNeutralForegroundInvertedHover
    _darkThemeColorList[ElaThemeType::colorNeutralForegroundInvertedHover] = QColor(0x24, 0x24, 0x24); // #242424
    _lightThemeColorList[ElaThemeType::colorNeutralForegroundInvertedHover] = QColor(0xFF, 0xFF, 0xFF); // #ffffff

    // colorNeutralForegroundInvertedPressed
    _darkThemeColorList[ElaThemeType::colorNeutralForegroundInvertedPressed] = QColor(0x24, 0x24, 0x24); // #242424
    _lightThemeColorList[ElaThemeType::colorNeutralForegroundInvertedPressed] = QColor(0xFF, 0xFF, 0xFF); // #ffffff

    // colorNeutralForegroundInvertedSelected
    _darkThemeColorList[ElaThemeType::colorNeutralForegroundInvertedSelected] = QColor(0x24, 0x24, 0x24); // #242424
    _lightThemeColorList[ElaThemeType::colorNeutralForegroundInvertedSelected] = QColor(0xFF, 0xFF, 0xFF); // #ffffff

    // colorNeutralForegroundInverted2
    _darkThemeColorList[ElaThemeType::colorNeutralForegroundInverted2] = QColor(0x24, 0x24, 0x24); // #242424
    _lightThemeColorList[ElaThemeType::colorNeutralForegroundInverted2] = QColor(0xFF, 0xFF, 0xFF); // #ffffff

    // colorNeutralForegroundOnBrand
    _darkThemeColorList[ElaThemeType::colorNeutralForegroundOnBrand] = QColor(0xFF, 0xFF, 0xFF); // #ffffff
    _lightThemeColorList[ElaThemeType::colorNeutralForegroundOnBrand] = QColor(0xFF, 0xFF, 0xFF); // #ffffff

    // colorNeutralForegroundInvertedLink
    _darkThemeColorList[ElaThemeType::colorNeutralForegroundInvertedLink] = QColor(0xFF, 0xFF, 0xFF); // #ffffff
    _lightThemeColorList[ElaThemeType::colorNeutralForegroundInvertedLink] = QColor(0xFF, 0xFF, 0xFF); // #ffffff

    // colorNeutralForegroundInvertedLinkHover
    _darkThemeColorList[ElaThemeType::colorNeutralForegroundInvertedLinkHover] = QColor(0xFF, 0xFF, 0xFF); // #ffffff
    _lightThemeColorList[ElaThemeType::colorNeutralForegroundInvertedLinkHover] = QColor(0xFF, 0xFF, 0xFF); // #ffffff

    // colorNeutralForegroundInvertedLinkPressed
    _darkThemeColorList[ElaThemeType::colorNeutralForegroundInvertedLinkPressed] = QColor(0xFF, 0xFF, 0xFF); // #ffffff
    _lightThemeColorList[ElaThemeType::colorNeutralForegroundInvertedLinkPressed] = QColor(0xFF, 0xFF, 0xFF); // #ffffff

    // colorNeutralForegroundInvertedLinkSelected
    _darkThemeColorList[ElaThemeType::colorNeutralForegroundInvertedLinkSelected] = QColor(0xFF, 0xFF, 0xFF); // #ffffff
    _lightThemeColorList[ElaThemeType::colorNeutralForegroundInvertedLinkSelected] = QColor(0xFF, 0xFF, 0xFF); // #ffffff

    // colorBrandForegroundInverted
    _darkThemeColorList[ElaThemeType::colorBrandForegroundInverted] = QColor(0x0F, 0x6C, 0xBD); // #0f6cbd
    _lightThemeColorList[ElaThemeType::colorBrandForegroundInverted] = QColor(0x47, 0x9E, 0xF5); // #479ef5

    // colorBrandForegroundInvertedHover
    _darkThemeColorList[ElaThemeType::colorBrandForegroundInvertedHover] = QColor(0x11, 0x5E, 0xA3); // #115ea3
    _lightThemeColorList[ElaThemeType::colorBrandForegroundInvertedHover] = QColor(0x62, 0xAB, 0xF5); // #62abf5

    // colorBrandForegroundInvertedPressed
    _darkThemeColorList[ElaThemeType::colorBrandForegroundInvertedPressed] = QColor(0x0F, 0x54, 0x8C); // #0f548c
    _lightThemeColorList[ElaThemeType::colorBrandForegroundInvertedPressed] = QColor(0x47, 0x9E, 0xF5); // #479ef5

    // colorBrandForegroundOnLight
    _darkThemeColorList[ElaThemeType::colorBrandForegroundOnLight] = QColor(0x0F, 0x6C, 0xBD); // #0f6cbd
    _lightThemeColorList[ElaThemeType::colorBrandForegroundOnLight] = QColor(0x0F, 0x6C, 0xBD); // #0f6cbd

    // colorBrandForegroundOnLightHover
    _darkThemeColorList[ElaThemeType::colorBrandForegroundOnLightHover] = QColor(0x11, 0x5E, 0xA3); // #115ea3
    _lightThemeColorList[ElaThemeType::colorBrandForegroundOnLightHover] = QColor(0x11, 0x5E, 0xA3); // #115ea3

    // colorBrandForegroundOnLightPressed
    _darkThemeColorList[ElaThemeType::colorBrandForegroundOnLightPressed] = QColor(0x0E, 0x47, 0x75); // #0e4775
    _lightThemeColorList[ElaThemeType::colorBrandForegroundOnLightPressed] = QColor(0x0E, 0x47, 0x75); // #0e4775

    // colorBrandForegroundOnLightSelected
    _darkThemeColorList[ElaThemeType::colorBrandForegroundOnLightSelected] = QColor(0x0F, 0x54, 0x8C); // #0f548c
    _lightThemeColorList[ElaThemeType::colorBrandForegroundOnLightSelected] = QColor(0x0F, 0x54, 0x8C); // #0f548c

    // colorNeutralBackground1
    _darkThemeColorList[ElaThemeType::colorNeutralBackground1] = QColor(0x29, 0x29, 0x29); // #292929
    _lightThemeColorList[ElaThemeType::colorNeutralBackground1] = QColor(0xFF, 0xFF, 0xFF); // #ffffff

    // colorNeutralBackground1Hover
    _darkThemeColorList[ElaThemeType::colorNeutralBackground1Hover] = QColor(0x3D, 0x3D, 0x3D); // #3d3d3d
    _lightThemeColorList[ElaThemeType::colorNeutralBackground1Hover] = QColor(0xF5, 0xF5, 0xF5); // #f5f5f5

    // colorNeutralBackground1Pressed
    _darkThemeColorList[ElaThemeType::colorNeutralBackground1Pressed] = QColor(0x1F, 0x1F, 0x1F); // #1f1f1f
    _lightThemeColorList[ElaThemeType::colorNeutralBackground1Pressed] = QColor(0xE0, 0xE0, 0xE0); // #e0e0e0

    // colorNeutralBackground1Selected
    _darkThemeColorList[ElaThemeType::colorNeutralBackground1Selected] = QColor(0x38, 0x38, 0x38); // #383838
    _lightThemeColorList[ElaThemeType::colorNeutralBackground1Selected] = QColor(0xEB, 0xEB, 0xEB); // #ebebeb

    // colorNeutralBackground2
    _darkThemeColorList[ElaThemeType::colorNeutralBackground2] = QColor(0x1F, 0x1F, 0x1F); // #1f1f1f
    _lightThemeColorList[ElaThemeType::colorNeutralBackground2] = QColor(0xFA, 0xFA, 0xFA); // #fafafa

    // colorNeutralBackground2Hover
    _darkThemeColorList[ElaThemeType::colorNeutralBackground2Hover] = QColor(0x33, 0x33, 0x33); // #333333
    _lightThemeColorList[ElaThemeType::colorNeutralBackground2Hover] = QColor(0xF0, 0xF0, 0xF0); // #f0f0f0

    // colorNeutralBackground2Pressed
    _darkThemeColorList[ElaThemeType::colorNeutralBackground2Pressed] = QColor(0x14, 0x14, 0x14); // #141414
    _lightThemeColorList[ElaThemeType::colorNeutralBackground2Pressed] = QColor(0xDB, 0xDB, 0xDB); // #dbdbdb

    // colorNeutralBackground2Selected
    _darkThemeColorList[ElaThemeType::colorNeutralBackground2Selected] = QColor(0x2E, 0x2E, 0x2E); // #2e2e2e
    _lightThemeColorList[ElaThemeType::colorNeutralBackground2Selected] = QColor(0xE6, 0xE6, 0xE6); // #e6e6e6

    // colorNeutralBackground3
    _darkThemeColorList[ElaThemeType::colorNeutralBackground3] = QColor(0x14, 0x14, 0x14); // #141414
    _lightThemeColorList[ElaThemeType::colorNeutralBackground3] = QColor(0xF5, 0xF5, 0xF5); // #f5f5f5

    // colorNeutralBackground3Hover
    _darkThemeColorList[ElaThemeType::colorNeutralBackground3Hover] = QColor(0x29, 0x29, 0x29); // #292929
    _lightThemeColorList[ElaThemeType::colorNeutralBackground3Hover] = QColor(0xEB, 0xEB, 0xEB); // #ebebeb

    // colorNeutralBackground3Pressed
    _darkThemeColorList[ElaThemeType::colorNeutralBackground3Pressed] = QColor(0x0A, 0x0A, 0x0A); // #0a0a0a
    _lightThemeColorList[ElaThemeType::colorNeutralBackground3Pressed] = QColor(0xD6, 0xD6, 0xD6); // #d6d6d6

    // colorNeutralBackground3Selected
    _darkThemeColorList[ElaThemeType::colorNeutralBackground3Selected] = QColor(0x24, 0x24, 0x24); // #242424
    _lightThemeColorList[ElaThemeType::colorNeutralBackground3Selected] = QColor(0xE0, 0xE0, 0xE0); // #e0e0e0

    // colorNeutralBackground4
    _darkThemeColorList[ElaThemeType::colorNeutralBackground4] = QColor(0x0A, 0x0A, 0x0A); // #0a0a0a
    _lightThemeColorList[ElaThemeType::colorNeutralBackground4] = QColor(0xF0, 0xF0, 0xF0); // #f0f0f0

    // colorNeutralBackground4Hover
    _darkThemeColorList[ElaThemeType::colorNeutralBackground4Hover] = QColor(0x1F, 0x1F, 0x1F); // #1f1f1f
    _lightThemeColorList[ElaThemeType::colorNeutralBackground4Hover] = QColor(0xFA, 0xFA, 0xFA); // #fafafa

    // colorNeutralBackground4Pressed
    _darkThemeColorList[ElaThemeType::colorNeutralBackground4Pressed] = QColor(0x00, 0x00, 0x00); // #000000
    _lightThemeColorList[ElaThemeType::colorNeutralBackground4Pressed] = QColor(0xF5, 0xF5, 0xF5); // #f5f5f5

    // colorNeutralBackground4Selected
    _darkThemeColorList[ElaThemeType::colorNeutralBackground4Selected] = QColor(0x1A, 0x1A, 0x1A); // #1a1a1a
    _lightThemeColorList[ElaThemeType::colorNeutralBackground4Selected] = QColor(0xFF, 0xFF, 0xFF); // #ffffff

    // colorNeutralBackground5
    _darkThemeColorList[ElaThemeType::colorNeutralBackground5] = QColor(0x00, 0x00, 0x00); // #000000
    _lightThemeColorList[ElaThemeType::colorNeutralBackground5] = QColor(0xEB, 0xEB, 0xEB); // #ebebeb

    // colorNeutralBackground5Hover
    _darkThemeColorList[ElaThemeType::colorNeutralBackground5Hover] = QColor(0x14, 0x14, 0x14); // #141414
    _lightThemeColorList[ElaThemeType::colorNeutralBackground5Hover] = QColor(0xF5, 0xF5, 0xF5); // #f5f5f5

    // colorNeutralBackground5Pressed
    _darkThemeColorList[ElaThemeType::colorNeutralBackground5Pressed] = QColor(0x05, 0x05, 0x05); // #050505
    _lightThemeColorList[ElaThemeType::colorNeutralBackground5Pressed] = QColor(0xF0, 0xF0, 0xF0); // #f0f0f0

    // colorNeutralBackground5Selected
    _darkThemeColorList[ElaThemeType::colorNeutralBackground5Selected] = QColor(0x0F, 0x0F, 0x0F); // #0f0f0f
    _lightThemeColorList[ElaThemeType::colorNeutralBackground5Selected] = QColor(0xFA, 0xFA, 0xFA); // #fafafa

    // colorNeutralBackground6
    _darkThemeColorList[ElaThemeType::colorNeutralBackground6] = QColor(0x33, 0x33, 0x33); // #333333
    _lightThemeColorList[ElaThemeType::colorNeutralBackground6] = QColor(0xE6, 0xE6, 0xE6); // #e6e6e6

    // colorNeutralBackgroundInverted
    _darkThemeColorList[ElaThemeType::colorNeutralBackgroundInverted] = QColor(0xFF, 0xFF, 0xFF); // #ffffff
    _lightThemeColorList[ElaThemeType::colorNeutralBackgroundInverted] = QColor(0x29, 0x29, 0x29); // #292929

    // colorNeutralBackgroundStatic
    _darkThemeColorList[ElaThemeType::colorNeutralBackgroundStatic] = QColor(0x3D, 0x3D, 0x3D); // #3d3d3d
    _lightThemeColorList[ElaThemeType::colorNeutralBackgroundStatic] = QColor(0x33, 0x33, 0x33); // #333333

    // colorNeutralBackgroundAlpha
    _darkThemeColorList[ElaThemeType::colorNeutralBackgroundAlpha] = QColor(0x1A, 0x1A, 0x1A, 128); // rgba(26,26,26,0.5)
    _lightThemeColorList[ElaThemeType::colorNeutralBackgroundAlpha] = QColor(0xFF, 0xFF, 0xFF, 128); // rgba(255,255,255,0.5)

    // colorNeutralBackgroundAlpha2
    _darkThemeColorList[ElaThemeType::colorNeutralBackgroundAlpha2] = QColor(0x1F, 0x1F, 0x1F, 179); // rgba(31,31,31,0.7)
    _lightThemeColorList[ElaThemeType::colorNeutralBackgroundAlpha2] = QColor(0xFF, 0xFF, 0xFF, 204); // rgba(255,255,255,0.8)

    // colorSubtleBackground
    _darkThemeColorList[ElaThemeType::colorSubtleBackground] = QColor(0, 0, 0, 0); // transparent
    _lightThemeColorList[ElaThemeType::colorSubtleBackground] = QColor(0, 0, 0, 0); // transparent

    // colorSubtleBackgroundHover
    _darkThemeColorList[ElaThemeType::colorSubtleBackgroundHover] = QColor(0x38, 0x38, 0x38); // #383838
    _lightThemeColorList[ElaThemeType::colorSubtleBackgroundHover] = QColor(0xF5, 0xF5, 0xF5); // #f5f5f5

    // colorSubtleBackgroundPressed
    _darkThemeColorList[ElaThemeType::colorSubtleBackgroundPressed] = QColor(0x2E, 0x2E, 0x2E); // #2e2e2e
    _lightThemeColorList[ElaThemeType::colorSubtleBackgroundPressed] = QColor(0xE0, 0xE0, 0xE0); // #e0e0e0

    // colorSubtleBackgroundSelected
    _darkThemeColorList[ElaThemeType::colorSubtleBackgroundSelected] = QColor(0x33, 0x33, 0x33); // #333333
    _lightThemeColorList[ElaThemeType::colorSubtleBackgroundSelected] = QColor(0xEB, 0xEB, 0xEB); // #ebebeb

    // colorSubtleBackgroundLightAlphaHover
    _darkThemeColorList[ElaThemeType::colorSubtleBackgroundLightAlphaHover] = QColor(0x24, 0x24, 0x24, 204); // rgba(36,36,36,0.8)
    _lightThemeColorList[ElaThemeType::colorSubtleBackgroundLightAlphaHover] = QColor(0xFF, 0xFF, 0xFF, 179); // rgba(255,255,255,0.7)

    // colorSubtleBackgroundLightAlphaPressed
    _darkThemeColorList[ElaThemeType::colorSubtleBackgroundLightAlphaPressed] = QColor(0x24, 0x24, 0x24, 128); // rgba(36,36,36,0.5)
    _lightThemeColorList[ElaThemeType::colorSubtleBackgroundLightAlphaPressed] = QColor(0xFF, 0xFF, 0xFF, 128); // rgba(255,255,255,0.5)

    // colorSubtleBackgroundLightAlphaSelected
    _darkThemeColorList[ElaThemeType::colorSubtleBackgroundLightAlphaSelected] = QColor(0, 0, 0, 0); // transparent
    _lightThemeColorList[ElaThemeType::colorSubtleBackgroundLightAlphaSelected] = QColor(0, 0, 0, 0); // transparent

    // colorSubtleBackgroundInverted
    _darkThemeColorList[ElaThemeType::colorSubtleBackgroundInverted] = QColor(0, 0, 0, 0); // transparent
    _lightThemeColorList[ElaThemeType::colorSubtleBackgroundInverted] = QColor(0, 0, 0, 0); // transparent

    // colorSubtleBackgroundInvertedHover
    _darkThemeColorList[ElaThemeType::colorSubtleBackgroundInvertedHover] = QColor(0, 0, 0, 26); // rgba(0,0,0,0.1)
    _lightThemeColorList[ElaThemeType::colorSubtleBackgroundInvertedHover] = QColor(0, 0, 0, 26); // rgba(0,0,0,0.1)

    // colorSubtleBackgroundInvertedPressed
    _darkThemeColorList[ElaThemeType::colorSubtleBackgroundInvertedPressed] = QColor(0, 0, 0, 77); // rgba(0,0,0,0.3)
    _lightThemeColorList[ElaThemeType::colorSubtleBackgroundInvertedPressed] = QColor(0, 0, 0, 77); // rgba(0,0,0,0.3)

    // colorSubtleBackgroundInvertedSelected
    _darkThemeColorList[ElaThemeType::colorSubtleBackgroundInvertedSelected] = QColor(0, 0, 0, 51); // rgba(0,0,0,0.2)
    _lightThemeColorList[ElaThemeType::colorSubtleBackgroundInvertedSelected] = QColor(0, 0, 0, 51); // rgba(0,0,0,0.2)

    // colorTransparentBackground
    _darkThemeColorList[ElaThemeType::colorTransparentBackground] = QColor(0, 0, 0, 0); // transparent
    _lightThemeColorList[ElaThemeType::colorTransparentBackground] = QColor(0, 0, 0, 0); // transparent

    // colorTransparentBackgroundHover
    _darkThemeColorList[ElaThemeType::colorTransparentBackgroundHover] = QColor(0, 0, 0, 0); // transparent
    _lightThemeColorList[ElaThemeType::colorTransparentBackgroundHover] = QColor(0, 0, 0, 0); // transparent

    // colorTransparentBackgroundPressed
    _darkThemeColorList[ElaThemeType::colorTransparentBackgroundPressed] = QColor(0, 0, 0, 0); // transparent
    _lightThemeColorList[ElaThemeType::colorTransparentBackgroundPressed] = QColor(0, 0, 0, 0); // transparent

    // colorTransparentBackgroundSelected
    _darkThemeColorList[ElaThemeType::colorTransparentBackgroundSelected] = QColor(0, 0, 0, 0); // transparent
    _lightThemeColorList[ElaThemeType::colorTransparentBackgroundSelected] = QColor(0, 0, 0, 0); // transparent

    // colorNeutralBackgroundDisabled
    _darkThemeColorList[ElaThemeType::colorNeutralBackgroundDisabled] = QColor(0x14, 0x14, 0x14); // #141414
    _lightThemeColorList[ElaThemeType::colorNeutralBackgroundDisabled] = QColor(0xF0, 0xF0, 0xF0); // #f0f0f0

    // colorNeutralBackgroundInvertedDisabled
    _darkThemeColorList[ElaThemeType::colorNeutralBackgroundInvertedDisabled] = QColor(255, 255, 255, 26); // rgba(255,255,255,0.1)
    _lightThemeColorList[ElaThemeType::colorNeutralBackgroundInvertedDisabled] = QColor(255, 255, 255, 26); // rgba(255,255,255,0.1)

    // colorNeutralStencil1
    _darkThemeColorList[ElaThemeType::colorNeutralStencil1] = QColor(0x57, 0x57, 0x57); // #575757
    _lightThemeColorList[ElaThemeType::colorNeutralStencil1] = QColor(0xE6, 0xE6, 0xE6); // #e6e6e6

    // colorNeutralStencil2
    _darkThemeColorList[ElaThemeType::colorNeutralStencil2] = QColor(0x33, 0x33, 0x33); // #333333
    _lightThemeColorList[ElaThemeType::colorNeutralStencil2] = QColor(0xFA, 0xFA, 0xFA); // #fafafa

    // colorNeutralStencil1Alpha
    _darkThemeColorList[ElaThemeType::colorNeutralStencil1Alpha] = QColor(255, 255, 255, 26); // rgba(255,255,255,0.1)
    _lightThemeColorList[ElaThemeType::colorNeutralStencil1Alpha] = QColor(0, 0, 0, 26); // rgba(0,0,0,0.1)

    // colorNeutralStencil2Alpha
    _darkThemeColorList[ElaThemeType::colorNeutralStencil2Alpha] = QColor(255, 255, 255, 13); // rgba(255,255,255,0.05)
    _lightThemeColorList[ElaThemeType::colorNeutralStencil2Alpha] = QColor(0, 0, 0, 13); // rgba(0,0,0,0.05)

    // colorBackgroundOverlay
    _darkThemeColorList[ElaThemeType::colorBackgroundOverlay] = QColor(0, 0, 0, 128); // rgba(0,0,0,0.5)
    _lightThemeColorList[ElaThemeType::colorBackgroundOverlay] = QColor(0, 0, 0, 102); // rgba(0,0,0,0.4)

    // colorScrollbarOverlay
    _darkThemeColorList[ElaThemeType::colorScrollbarOverlay] = QColor(255, 255, 255, 153); // rgba(255,255,255,0.6)
    _lightThemeColorList[ElaThemeType::colorScrollbarOverlay] = QColor(0, 0, 0, 128); // rgba(0,0,0,0.5)

    // colorBrandBackground
    _darkThemeColorList[ElaThemeType::colorBrandBackground] = QColor(0x11, 0x5E, 0xA3); // #115ea3
    _lightThemeColorList[ElaThemeType::colorBrandBackground] = QColor(0x0F, 0x6C, 0xBD); // #0f6cbd

    // colorBrandBackgroundHover
    _darkThemeColorList[ElaThemeType::colorBrandBackgroundHover] = QColor(0x0F, 0x6C, 0xBD); // #0f6cbd
    _lightThemeColorList[ElaThemeType::colorBrandBackgroundHover] = QColor(0x11, 0x5E, 0xA3); // #115ea3

    // colorBrandBackgroundPressed
    _darkThemeColorList[ElaThemeType::colorBrandBackgroundPressed] = QColor(0x0C, 0x3B, 0x5E); // #0c3b5e
    _lightThemeColorList[ElaThemeType::colorBrandBackgroundPressed] = QColor(0x0C, 0x3B, 0x5E); // #0c3b5e

    // colorBrandBackgroundSelected
    _darkThemeColorList[ElaThemeType::colorBrandBackgroundSelected] = QColor(0x0F, 0x54, 0x8C); // #0f548c
    _lightThemeColorList[ElaThemeType::colorBrandBackgroundSelected] = QColor(0x0F, 0x54, 0x8C); // #0f548c

    // // colorCompoundBrandBackground
    // _darkThemeColorList[ElaThemeType::colorCompoundBrandBackground] = QColor(0x47, 0x9E, 0xF5); // #479ef5
    // _lightThemeColorList[ElaThemeType::colorCompoundBrandBackground] = QColor(0x0F, 0x6C, 0xBD); // #0f6cbd

    // // colorCompoundBrandBackgroundHover
    // _darkThemeColorList[ElaThemeType::colorCompoundBrandBackgroundHover] = QColor(0x62, 0xAB, 0xF5); // #62abf5
    // _lightThemeColorList[ElaThemeType::colorCompoundBrandBackgroundHover] = QColor(0x11, 0x5E, 0xA3); // #115ea3

    // // colorCompoundBrandBackgroundPressed
    // _darkThemeColorList[ElaThemeType::colorCompoundBrandBackgroundPressed] = QColor(0x28, 0x86, 0xDE); // #2886de
    // _lightThemeColorList[ElaThemeType::colorCompoundBrandBackgroundPressed] = QColor(0x0F, 0x54, 0x8C); // #0f548c

    // colorCompoundBrandBackground(teams)
    _darkThemeColorList[ElaThemeType::colorCompoundBrandBackground] = QColor(0x7f, 0x85, 0xf5); // #7f85f5
    _lightThemeColorList[ElaThemeType::colorCompoundBrandBackground] = QColor(0x5b, 0x5f, 0xc7); // #5b5fc7

    // colorCompoundBrandBackgroundHover(teams)
    _darkThemeColorList[ElaThemeType::colorCompoundBrandBackgroundHover] = QColor(0x92, 0x99, 0xf7); // #9299f7
    _lightThemeColorList[ElaThemeType::colorCompoundBrandBackgroundHover] = QColor(0x4f, 0x52, 0xb2); // #4f52b2

    // colorCompoundBrandBackgroundPressed(teams)
    _darkThemeColorList[ElaThemeType::colorCompoundBrandBackgroundPressed] = QColor(0x75, 0x79, 0xeb); // #7579eb
    _lightThemeColorList[ElaThemeType::colorCompoundBrandBackgroundPressed] = QColor(0x44, 0x47, 0x91); // #444791

    // colorBrandBackgroundStatic
    _darkThemeColorList[ElaThemeType::colorBrandBackgroundStatic] = QColor(0x0F, 0x6C, 0xBD); // #0f6cbd
    _lightThemeColorList[ElaThemeType::colorBrandBackgroundStatic] = QColor(0x0F, 0x6C, 0xBD); // #0f6cbd

    // colorBrandBackground2
    _darkThemeColorList[ElaThemeType::colorBrandBackground2] = QColor(0x08, 0x23, 0x38); // #082338
    _lightThemeColorList[ElaThemeType::colorBrandBackground2] = QColor(0xEB, 0xF3, 0xFC); // #ebf3fc

    // colorBrandBackground2Hover
    _darkThemeColorList[ElaThemeType::colorBrandBackground2Hover] = QColor(0x0C, 0x3B, 0x5E); // #0c3b5e
    _lightThemeColorList[ElaThemeType::colorBrandBackground2Hover] = QColor(0xCF, 0xE4, 0xFA); // #cfe4fa

    // colorBrandBackground2Pressed
    _darkThemeColorList[ElaThemeType::colorBrandBackground2Pressed] = QColor(0x06, 0x17, 0x24); // #061724
    _lightThemeColorList[ElaThemeType::colorBrandBackground2Pressed] = QColor(0x96, 0xC6, 0xFA); // #96c6fa

    // colorBrandBackground3Static
    _darkThemeColorList[ElaThemeType::colorBrandBackground3Static] = QColor(0x0F, 0x54, 0x8C); // #0f548c
    _lightThemeColorList[ElaThemeType::colorBrandBackground3Static] = QColor(0x0F, 0x54, 0x8C); // #0f548c

    // colorBrandBackground4Static
    _darkThemeColorList[ElaThemeType::colorBrandBackground4Static] = QColor(0x0C, 0x3B, 0x5E); // #0c3b5e
    _lightThemeColorList[ElaThemeType::colorBrandBackground4Static] = QColor(0x0C, 0x3B, 0x5E); // #0c3b5e

    // colorBrandBackgroundInverted
    _darkThemeColorList[ElaThemeType::colorBrandBackgroundInverted] = QColor(0xFF, 0xFF, 0xFF); // #ffffff
    _lightThemeColorList[ElaThemeType::colorBrandBackgroundInverted] = QColor(0xFF, 0xFF, 0xFF); // #ffffff

    // colorBrandBackgroundInvertedHover
    _darkThemeColorList[ElaThemeType::colorBrandBackgroundInvertedHover] = QColor(0xEB, 0xF3, 0xFC); // #ebf3fc
    _lightThemeColorList[ElaThemeType::colorBrandBackgroundInvertedHover] = QColor(0xEB, 0xF3, 0xFC); // #ebf3fc

    // colorBrandBackgroundInvertedPressed
    _darkThemeColorList[ElaThemeType::colorBrandBackgroundInvertedPressed] = QColor(0xB4, 0xD6, 0xFA); // #b4d6fa
    _lightThemeColorList[ElaThemeType::colorBrandBackgroundInvertedPressed] = QColor(0xB4, 0xD6, 0xFA); // #b4d6fa

    // colorBrandBackgroundInvertedSelected
    _darkThemeColorList[ElaThemeType::colorBrandBackgroundInvertedSelected] = QColor(0xCF, 0xE4, 0xFA); // #cfe4fa
    _lightThemeColorList[ElaThemeType::colorBrandBackgroundInvertedSelected] = QColor(0xCF, 0xE4, 0xFA); // #cfe4fa

    // colorNeutralCardBackground
    _darkThemeColorList[ElaThemeType::colorNeutralCardBackground] = QColor(0x33, 0x33, 0x33); // #333333
    _lightThemeColorList[ElaThemeType::colorNeutralCardBackground] = QColor(0xFA, 0xFA, 0xFA); // #fafafa

    // colorNeutralCardBackgroundHover
    _darkThemeColorList[ElaThemeType::colorNeutralCardBackgroundHover] = QColor(0x3D, 0x3D, 0x3D); // #3d3d3d
    _lightThemeColorList[ElaThemeType::colorNeutralCardBackgroundHover] = QColor(0xFF, 0xFF, 0xFF); // #ffffff

    // colorNeutralCardBackgroundPressed
    _darkThemeColorList[ElaThemeType::colorNeutralCardBackgroundPressed] = QColor(0x2E, 0x2E, 0x2E); // #2e2e2e
    _lightThemeColorList[ElaThemeType::colorNeutralCardBackgroundPressed] = QColor(0xF5, 0xF5, 0xF5); // #f5f5f5

    // colorNeutralCardBackgroundSelected
    _darkThemeColorList[ElaThemeType::colorNeutralCardBackgroundSelected] = QColor(0x38, 0x38, 0x38); // #383838
    _lightThemeColorList[ElaThemeType::colorNeutralCardBackgroundSelected] = QColor(0xEB, 0xEB, 0xEB); // #ebebeb

    // colorNeutralCardBackgroundDisabled
    _darkThemeColorList[ElaThemeType::colorNeutralCardBackgroundDisabled] = QColor(0x14, 0x14, 0x14); // #141414
    _lightThemeColorList[ElaThemeType::colorNeutralCardBackgroundDisabled] = QColor(0xF0, 0xF0, 0xF0); // #f0f0f0

    // colorNeutralStrokeAccessible
    _darkThemeColorList[ElaThemeType::colorNeutralStrokeAccessible] = QColor(0xAD, 0xAD, 0xAD); // #adadad
    _lightThemeColorList[ElaThemeType::colorNeutralStrokeAccessible] = QColor(0x61, 0x61, 0x61); // #616161

    // colorNeutralStrokeAccessibleHover
    _darkThemeColorList[ElaThemeType::colorNeutralStrokeAccessibleHover] = QColor(0xBD, 0xBD, 0xBD); // #bdbdbd
    _lightThemeColorList[ElaThemeType::colorNeutralStrokeAccessibleHover] = QColor(0x57, 0x57, 0x57); // #575757

    // colorNeutralStrokeAccessiblePressed
    _darkThemeColorList[ElaThemeType::colorNeutralStrokeAccessiblePressed] = QColor(0xB3, 0xB3, 0xB3); // #b3b3b3
    _lightThemeColorList[ElaThemeType::colorNeutralStrokeAccessiblePressed] = QColor(0x4D, 0x4D, 0x4D); // #4d4d4d

    // colorNeutralStrokeAccessibleSelected
    _darkThemeColorList[ElaThemeType::colorNeutralStrokeAccessibleSelected] = QColor(0x47, 0x9E, 0xF5); // #479ef5
    _lightThemeColorList[ElaThemeType::colorNeutralStrokeAccessibleSelected] = QColor(0x0F, 0x6C, 0xBD); // #0f6cbd

    // colorNeutralStroke1
    _darkThemeColorList[ElaThemeType::colorNeutralStroke1] = QColor(0x66, 0x66, 0x66); // #666666
    _lightThemeColorList[ElaThemeType::colorNeutralStroke1] = QColor(0xD1, 0xD1, 0xD1); // #d1d1d1

    // colorNeutralStroke1Hover
    _darkThemeColorList[ElaThemeType::colorNeutralStroke1Hover] = QColor(0x75, 0x75, 0x75); // #757575
    _lightThemeColorList[ElaThemeType::colorNeutralStroke1Hover] = QColor(0xC7, 0xC7, 0xC7); // #c7c7c7

    // colorNeutralStroke1Pressed
    _darkThemeColorList[ElaThemeType::colorNeutralStroke1Pressed] = QColor(0x6B, 0x6B, 0x6B); // #6b6b6b
    _lightThemeColorList[ElaThemeType::colorNeutralStroke1Pressed] = QColor(0xB3, 0xB3, 0xB3); // #b3b3b3

    // colorNeutralStroke1Selected
    _darkThemeColorList[ElaThemeType::colorNeutralStroke1Selected] = QColor(0x70, 0x70, 0x70); // #707070
    _lightThemeColorList[ElaThemeType::colorNeutralStroke1Selected] = QColor(0xBD, 0xBD, 0xBD); // #bdbdbd

    // colorNeutralStroke2
    _darkThemeColorList[ElaThemeType::colorNeutralStroke2] = QColor(0x52, 0x52, 0x52); // #525252
    _lightThemeColorList[ElaThemeType::colorNeutralStroke2] = QColor(0xE0, 0xE0, 0xE0); // #e0e0e0

    // colorNeutralStroke3
    _darkThemeColorList[ElaThemeType::colorNeutralStroke3] = QColor(0x3D, 0x3D, 0x3D); // #3d3d3d
    _lightThemeColorList[ElaThemeType::colorNeutralStroke3] = QColor(0xF0, 0xF0, 0xF0); // #f0f0f0

    // colorNeutralStrokeSubtle
    _darkThemeColorList[ElaThemeType::colorNeutralStrokeSubtle] = QColor(0x0A, 0x0A, 0x0A); // #0a0a0a
    _lightThemeColorList[ElaThemeType::colorNeutralStrokeSubtle] = QColor(0xE0, 0xE0, 0xE0); // #e0e0e0

    // colorNeutralStrokeOnBrand
    _darkThemeColorList[ElaThemeType::colorNeutralStrokeOnBrand] = QColor(0x29, 0x29, 0x29); // #292929
    _lightThemeColorList[ElaThemeType::colorNeutralStrokeOnBrand] = QColor(0xFF, 0xFF, 0xFF); // #ffffff

    // colorNeutralStrokeOnBrand2
    _darkThemeColorList[ElaThemeType::colorNeutralStrokeOnBrand2] = QColor(0xFF, 0xFF, 0xFF); // #ffffff
    _lightThemeColorList[ElaThemeType::colorNeutralStrokeOnBrand2] = QColor(0xFF, 0xFF, 0xFF); // #ffffff

    // colorNeutralStrokeOnBrand2Hover
    _darkThemeColorList[ElaThemeType::colorNeutralStrokeOnBrand2Hover] = QColor(0xFF, 0xFF, 0xFF); // #ffffff
    _lightThemeColorList[ElaThemeType::colorNeutralStrokeOnBrand2Hover] = QColor(0xFF, 0xFF, 0xFF); // #ffffff

    // colorNeutralStrokeOnBrand2Pressed
    _darkThemeColorList[ElaThemeType::colorNeutralStrokeOnBrand2Pressed] = QColor(0xFF, 0xFF, 0xFF); // #ffffff
    _lightThemeColorList[ElaThemeType::colorNeutralStrokeOnBrand2Pressed] = QColor(0xFF, 0xFF, 0xFF); // #ffffff

    // colorNeutralStrokeOnBrand2Selected
    _darkThemeColorList[ElaThemeType::colorNeutralStrokeOnBrand2Selected] = QColor(0xFF, 0xFF, 0xFF); // #ffffff
    _lightThemeColorList[ElaThemeType::colorNeutralStrokeOnBrand2Selected] = QColor(0xFF, 0xFF, 0xFF); // #ffffff

    // colorBrandStroke1
    _darkThemeColorList[ElaThemeType::colorBrandStroke1] = QColor(0x47, 0x9E, 0xF5); // #479ef5
    _lightThemeColorList[ElaThemeType::colorBrandStroke1] = QColor(0x0F, 0x6C, 0xBD); // #0f6cbd

    // colorBrandStroke2
    _darkThemeColorList[ElaThemeType::colorBrandStroke2] = QColor(0x0E, 0x47, 0x75); // #0e4775
    _lightThemeColorList[ElaThemeType::colorBrandStroke2] = QColor(0xB4, 0xD6, 0xFA); // #b4d6fa

    // colorBrandStroke2Hover
    _darkThemeColorList[ElaThemeType::colorBrandStroke2Hover] = QColor(0x0E, 0x47, 0x75); // #0e4775
    _lightThemeColorList[ElaThemeType::colorBrandStroke2Hover] = QColor(0x77, 0xB7, 0xF7); // #77b7f7

    // colorBrandStroke2Pressed
    _darkThemeColorList[ElaThemeType::colorBrandStroke2Pressed] = QColor(0x0A, 0x2E, 0x4A); // #0a2e4a
    _lightThemeColorList[ElaThemeType::colorBrandStroke2Pressed] = QColor(0x0F, 0x6C, 0xBD); // #0f6cbd

    // colorBrandStroke2Contrast
    _darkThemeColorList[ElaThemeType::colorBrandStroke2Contrast] = QColor(0x0E, 0x47, 0x75); // #0e4775
    _lightThemeColorList[ElaThemeType::colorBrandStroke2Contrast] = QColor(0xB4, 0xD6, 0xFA); // #b4d6fa

    // colorCompoundBrandStroke
    _darkThemeColorList[ElaThemeType::colorCompoundBrandStroke] = QColor(0x47, 0x9E, 0xF5); // #479ef5
    _lightThemeColorList[ElaThemeType::colorCompoundBrandStroke] = QColor(0x0F, 0x6C, 0xBD); // #0f6cbd

    // colorCompoundBrandStrokeHover
    _darkThemeColorList[ElaThemeType::colorCompoundBrandStrokeHover] = QColor(0x62, 0xAB, 0xF5); // #62abf5
    _lightThemeColorList[ElaThemeType::colorCompoundBrandStrokeHover] = QColor(0x11, 0x5E, 0xA3); // #115ea3

    // colorCompoundBrandStrokePressed
    _darkThemeColorList[ElaThemeType::colorCompoundBrandStrokePressed] = QColor(0x28, 0x86, 0xDE); // #2886de
    _lightThemeColorList[ElaThemeType::colorCompoundBrandStrokePressed] = QColor(0x0F, 0x54, 0x8C); // #0f548c

    // colorNeutralStrokeDisabled
    _darkThemeColorList[ElaThemeType::colorNeutralStrokeDisabled] = QColor(0x42, 0x42, 0x42); // #424242
    _lightThemeColorList[ElaThemeType::colorNeutralStrokeDisabled] = QColor(0xE0, 0xE0, 0xE0); // #e0e0e0

    // colorNeutralStrokeInvertedDisabled
    _darkThemeColorList[ElaThemeType::colorNeutralStrokeInvertedDisabled] = QColor(255, 255, 255, 102); // rgba(255,255,255,0.4)
    _lightThemeColorList[ElaThemeType::colorNeutralStrokeInvertedDisabled] = QColor(255, 255, 255, 102); // rgba(255,255,255,0.4)

    // colorTransparentStroke
    _darkThemeColorList[ElaThemeType::colorTransparentStroke] = QColor(0, 0, 0, 0); // transparent
    _lightThemeColorList[ElaThemeType::colorTransparentStroke] = QColor(0, 0, 0, 0); // transparent

    // colorTransparentStrokeInteractive
    _darkThemeColorList[ElaThemeType::colorTransparentStrokeInteractive] = QColor(0, 0, 0, 0); // transparent
    _lightThemeColorList[ElaThemeType::colorTransparentStrokeInteractive] = QColor(0, 0, 0, 0); // transparent

    // colorTransparentStrokeDisabled
    _darkThemeColorList[ElaThemeType::colorTransparentStrokeDisabled] = QColor(0, 0, 0, 0); // transparent
    _lightThemeColorList[ElaThemeType::colorTransparentStrokeDisabled] = QColor(0, 0, 0, 0); // transparent

    // colorNeutralStrokeAlpha
    _darkThemeColorList[ElaThemeType::colorNeutralStrokeAlpha] = QColor(255, 255, 255, 26); // rgba(255,255,255,0.1)
    _lightThemeColorList[ElaThemeType::colorNeutralStrokeAlpha] = QColor(0, 0, 0, 13); // rgba(0,0,0,0.05)

    // colorNeutralStrokeAlpha2
    _darkThemeColorList[ElaThemeType::colorNeutralStrokeAlpha2] = QColor(255, 255, 255, 51); // rgba(255,255,255,0.2)
    _lightThemeColorList[ElaThemeType::colorNeutralStrokeAlpha2] = QColor(255, 255, 255, 51); // rgba(255,255,255,0.2)

    // colorStrokeFocus1
    _darkThemeColorList[ElaThemeType::colorStrokeFocus1] = QColor(0x00, 0x00, 0x00); // #000000
    _lightThemeColorList[ElaThemeType::colorStrokeFocus1] = QColor(0xFF, 0xFF, 0xFF); // #ffffff

    // colorStrokeFocus2
    _darkThemeColorList[ElaThemeType::colorStrokeFocus2] = QColor(0xFF, 0xFF, 0xFF); // #ffffff
    _lightThemeColorList[ElaThemeType::colorStrokeFocus2] = QColor(0x00, 0x00, 0x00); // #000000

    // colorNeutralShadowAmbient
    _darkThemeColorList[ElaThemeType::colorNeutralShadowAmbient] = QColor(0, 0, 0, 61); // rgba(0,0,0,0.24)
    _lightThemeColorList[ElaThemeType::colorNeutralShadowAmbient] = QColor(0, 0, 0, 31); // rgba(0,0,0,0.12)

    // colorNeutralShadowKey
    _darkThemeColorList[ElaThemeType::colorNeutralShadowKey] = QColor(0, 0, 0, 71); // rgba(0,0,0,0.28)
    _lightThemeColorList[ElaThemeType::colorNeutralShadowKey] = QColor(0, 0, 0, 36); // rgba(0,0,0,0.14)

    // colorNeutralShadowAmbientLighter
    _darkThemeColorList[ElaThemeType::colorNeutralShadowAmbientLighter] = QColor(0, 0, 0, 31); // rgba(0,0,0,0.12)
    _lightThemeColorList[ElaThemeType::colorNeutralShadowAmbientLighter] = QColor(0, 0, 0, 15); // rgba(0,0,0,0.06)

    // colorNeutralShadowKeyLighter
    _darkThemeColorList[ElaThemeType::colorNeutralShadowKeyLighter] = QColor(0, 0, 0, 36); // rgba(0,0,0,0.14)
    _lightThemeColorList[ElaThemeType::colorNeutralShadowKeyLighter] = QColor(0, 0, 0, 18); // rgba(0,0,0,0.07)

    // colorNeutralShadowAmbientDarker
    _darkThemeColorList[ElaThemeType::colorNeutralShadowAmbientDarker] = QColor(0, 0, 0, 102); // rgba(0,0,0,0.40)
    _lightThemeColorList[ElaThemeType::colorNeutralShadowAmbientDarker] = QColor(0, 0, 0, 51); // rgba(0,0,0,0.20)

    // colorNeutralShadowKeyDarker
    _darkThemeColorList[ElaThemeType::colorNeutralShadowKeyDarker] = QColor(0, 0, 0, 122); // rgba(0,0,0,0.48)
    _lightThemeColorList[ElaThemeType::colorNeutralShadowKeyDarker] = QColor(0, 0, 0, 61); // rgba(0,0,0,0.24)

    // colorBrandShadowAmbient
    _darkThemeColorList[ElaThemeType::colorBrandShadowAmbient] = QColor(0, 0, 0, 77); // rgba(0,0,0,0.30)
    _lightThemeColorList[ElaThemeType::colorBrandShadowAmbient] = QColor(0, 0, 0, 77); // rgba(0,0,0,0.30)

    // colorBrandShadowKey
    _darkThemeColorList[ElaThemeType::colorBrandShadowKey] = QColor(0, 0, 0, 64); // rgba(0,0,0,0.25)
    _lightThemeColorList[ElaThemeType::colorBrandShadowKey] = QColor(0, 0, 0, 64); // rgba(0,0,0,0.25)

    // colorPaletteRedBackground1
    _darkThemeColorList[ElaThemeType::colorPaletteRedBackground1] = QColor(0x3F, 0x10, 0x11); // #3f1011
    _lightThemeColorList[ElaThemeType::colorPaletteRedBackground1] = QColor(0xFD, 0xF6, 0xF6); // #fdf6f6

    // colorPaletteRedBackground2
    _darkThemeColorList[ElaThemeType::colorPaletteRedBackground2] = QColor(0x75, 0x1D, 0x1F); // #751d1f
    _lightThemeColorList[ElaThemeType::colorPaletteRedBackground2] = QColor(0xF1, 0xBB, 0xBC); // #f1bbbc

    // colorPaletteRedBackground3
    _darkThemeColorList[ElaThemeType::colorPaletteRedBackground3] = QColor(0xD1, 0x34, 0x38); // #d13438
    _lightThemeColorList[ElaThemeType::colorPaletteRedBackground3] = QColor(0xD1, 0x34, 0x38); // #d13438

    // colorPaletteRedForeground1
    _darkThemeColorList[ElaThemeType::colorPaletteRedForeground1] = QColor(0xE3, 0x7D, 0x80); // #e37d80
    _lightThemeColorList[ElaThemeType::colorPaletteRedForeground1] = QColor(0xBC, 0x2F, 0x32); // #bc2f32

    // colorPaletteRedForeground2
    _darkThemeColorList[ElaThemeType::colorPaletteRedForeground2] = QColor(0xF1, 0xBB, 0xBC); // #f1bbbc
    _lightThemeColorList[ElaThemeType::colorPaletteRedForeground2] = QColor(0x75, 0x1D, 0x1F); // #751d1f

    // colorPaletteRedForeground3
    _darkThemeColorList[ElaThemeType::colorPaletteRedForeground3] = QColor(0xE3, 0x7D, 0x80); // #e37d80
    _lightThemeColorList[ElaThemeType::colorPaletteRedForeground3] = QColor(0xD1, 0x34, 0x38); // #d13438

    // colorPaletteRedBorderActive
    _darkThemeColorList[ElaThemeType::colorPaletteRedBorderActive] = QColor(0xE3, 0x7D, 0x80); // #e37d80
    _lightThemeColorList[ElaThemeType::colorPaletteRedBorderActive] = QColor(0xD1, 0x34, 0x38); // #d13438

    // colorPaletteRedBorder1
    _darkThemeColorList[ElaThemeType::colorPaletteRedBorder1] = QColor(0xD1, 0x34, 0x38); // #d13438
    _lightThemeColorList[ElaThemeType::colorPaletteRedBorder1] = QColor(0xF1, 0xBB, 0xBC); // #f1bbbc

    // colorPaletteRedBorder2
    _darkThemeColorList[ElaThemeType::colorPaletteRedBorder2] = QColor(0xE3, 0x7D, 0x80); // #e37d80
    _lightThemeColorList[ElaThemeType::colorPaletteRedBorder2] = QColor(0xD1, 0x34, 0x38); // #d13438

    // colorPaletteGreenBackground1
    _darkThemeColorList[ElaThemeType::colorPaletteGreenBackground1] = QColor(0x05, 0x25, 0x05); // #052505
    _lightThemeColorList[ElaThemeType::colorPaletteGreenBackground1] = QColor(0xF1, 0xFA, 0xF1); // #f1faf1

    // colorPaletteGreenBackground2
    _darkThemeColorList[ElaThemeType::colorPaletteGreenBackground2] = QColor(0x09, 0x45, 0x09); // #094509
    _lightThemeColorList[ElaThemeType::colorPaletteGreenBackground2] = QColor(0x9F, 0xD8, 0x9F); // #9fd89f

    // colorPaletteGreenBackground3
    _darkThemeColorList[ElaThemeType::colorPaletteGreenBackground3] = QColor(0x10, 0x7C, 0x10); // #107c10
    _lightThemeColorList[ElaThemeType::colorPaletteGreenBackground3] = QColor(0x10, 0x7C, 0x10); // #107c10

    // colorPaletteGreenForeground1
    _darkThemeColorList[ElaThemeType::colorPaletteGreenForeground1] = QColor(0x54, 0xB0, 0x54); // #54b054
    _lightThemeColorList[ElaThemeType::colorPaletteGreenForeground1] = QColor(0x0E, 0x70, 0x0E); // #0e700e

    // colorPaletteGreenForeground2
    _darkThemeColorList[ElaThemeType::colorPaletteGreenForeground2] = QColor(0x9F, 0xD8, 0x9F); // #9fd89f
    _lightThemeColorList[ElaThemeType::colorPaletteGreenForeground2] = QColor(0x09, 0x45, 0x09); // #094509

    // colorPaletteGreenForeground3
    _darkThemeColorList[ElaThemeType::colorPaletteGreenForeground3] = QColor(0x9F, 0xD8, 0x9F); // #9fd89f
    _lightThemeColorList[ElaThemeType::colorPaletteGreenForeground3] = QColor(0x10, 0x7C, 0x10); // #107c10

    // colorPaletteGreenBorderActive
    _darkThemeColorList[ElaThemeType::colorPaletteGreenBorderActive] = QColor(0x54, 0xB0, 0x54); // #54b054
    _lightThemeColorList[ElaThemeType::colorPaletteGreenBorderActive] = QColor(0x10, 0x7C, 0x10); // #107c10

    // colorPaletteGreenBorder1
    _darkThemeColorList[ElaThemeType::colorPaletteGreenBorder1] = QColor(0x10, 0x7C, 0x10); // #107c10
    _lightThemeColorList[ElaThemeType::colorPaletteGreenBorder1] = QColor(0x9F, 0xD8, 0x9F); // #9fd89f

    // colorPaletteGreenBorder2
    _darkThemeColorList[ElaThemeType::colorPaletteGreenBorder2] = QColor(0x9F, 0xD8, 0x9F); // #9fd89f
    _lightThemeColorList[ElaThemeType::colorPaletteGreenBorder2] = QColor(0x10, 0x7C, 0x10); // #107c10

    // colorPaletteDarkOrangeBackground1
    _darkThemeColorList[ElaThemeType::colorPaletteDarkOrangeBackground1] = QColor(0x41, 0x12, 0x00); // #411200
    _lightThemeColorList[ElaThemeType::colorPaletteDarkOrangeBackground1] = QColor(0xFD, 0xF6, 0xF3); // #fdf6f3

    // colorPaletteDarkOrangeBackground2
    _darkThemeColorList[ElaThemeType::colorPaletteDarkOrangeBackground2] = QColor(0x7A, 0x21, 0x01); // #7a2101
    _lightThemeColorList[ElaThemeType::colorPaletteDarkOrangeBackground2] = QColor(0xF4, 0xBF, 0xAB); // #f4bfab

    // colorPaletteDarkOrangeBackground3
    _darkThemeColorList[ElaThemeType::colorPaletteDarkOrangeBackground3] = QColor(0xDA, 0x3B, 0x01); // #da3b01
    _lightThemeColorList[ElaThemeType::colorPaletteDarkOrangeBackground3] = QColor(0xDA, 0x3B, 0x01); // #da3b01

    // colorPaletteDarkOrangeForeground1
    _darkThemeColorList[ElaThemeType::colorPaletteDarkOrangeForeground1] = QColor(0xE9, 0x83, 0x5E); // #e9835e
    _lightThemeColorList[ElaThemeType::colorPaletteDarkOrangeForeground1] = QColor(0xC4, 0x35, 0x01); // #c43501

    // colorPaletteDarkOrangeForeground2
    _darkThemeColorList[ElaThemeType::colorPaletteDarkOrangeForeground2] = QColor(0xF4, 0xBF, 0xAB); // #f4bfab
    _lightThemeColorList[ElaThemeType::colorPaletteDarkOrangeForeground2] = QColor(0x7A, 0x21, 0x01); // #7a2101

    // colorPaletteDarkOrangeForeground3
    _darkThemeColorList[ElaThemeType::colorPaletteDarkOrangeForeground3] = QColor(0xE9, 0x83, 0x5E); // #e9835e
    _lightThemeColorList[ElaThemeType::colorPaletteDarkOrangeForeground3] = QColor(0xDA, 0x3B, 0x01); // #da3b01

    // colorPaletteDarkOrangeBorderActive
    _darkThemeColorList[ElaThemeType::colorPaletteDarkOrangeBorderActive] = QColor(0xE9, 0x83, 0x5E); // #e9835e
    _lightThemeColorList[ElaThemeType::colorPaletteDarkOrangeBorderActive] = QColor(0xDA, 0x3B, 0x01); // #da3b01

    // colorPaletteDarkOrangeBorder1
    _darkThemeColorList[ElaThemeType::colorPaletteDarkOrangeBorder1] = QColor(0xDA, 0x3B, 0x01); // #da3b01
    _lightThemeColorList[ElaThemeType::colorPaletteDarkOrangeBorder1] = QColor(0xF4, 0xBF, 0xAB); // #f4bfab

    // colorPaletteDarkOrangeBorder2
    _darkThemeColorList[ElaThemeType::colorPaletteDarkOrangeBorder2] = QColor(0xE9, 0x83, 0x5E); // #e9835e
    _lightThemeColorList[ElaThemeType::colorPaletteDarkOrangeBorder2] = QColor(0xDA, 0x3B, 0x01); // #da3b01

    // colorPaletteYellowBackground1
    _darkThemeColorList[ElaThemeType::colorPaletteYellowBackground1] = QColor(0x4C, 0x44, 0x00); // #4c4400
    _lightThemeColorList[ElaThemeType::colorPaletteYellowBackground1] = QColor(0xFF, 0xFE, 0xF5); // #fffef5

    // colorPaletteYellowBackground2
    _darkThemeColorList[ElaThemeType::colorPaletteYellowBackground2] = QColor(0x81, 0x74, 0x00); // #817400
    _lightThemeColorList[ElaThemeType::colorPaletteYellowBackground2] = QColor(0xFE, 0xF7, 0xB2); // #fef7b2

    // colorPaletteYellowBackground3
    _darkThemeColorList[ElaThemeType::colorPaletteYellowBackground3] = QColor(0xFD, 0xE3, 0x00); // #fde300
    _lightThemeColorList[ElaThemeType::colorPaletteYellowBackground3] = QColor(0xFD, 0xE3, 0x00); // #fde300

    // colorPaletteYellowForeground1
    _darkThemeColorList[ElaThemeType::colorPaletteYellowForeground1] = QColor(0xFE, 0xEE, 0x66); // #feee66
    _lightThemeColorList[ElaThemeType::colorPaletteYellowForeground1] = QColor(0x81, 0x74, 0x00); // #817400

    // colorPaletteYellowForeground2
    _darkThemeColorList[ElaThemeType::colorPaletteYellowForeground2] = QColor(0xFE, 0xF7, 0xB2); // #fef7b2
    _lightThemeColorList[ElaThemeType::colorPaletteYellowForeground2] = QColor(0x81, 0x74, 0x00); // #817400

    // colorPaletteYellowForeground3
    _darkThemeColorList[ElaThemeType::colorPaletteYellowForeground3] = QColor(0xFD, 0xEA, 0x3D); // #fdea3d
    _lightThemeColorList[ElaThemeType::colorPaletteYellowForeground3] = QColor(0xFD, 0xE3, 0x00); // #fde300

    // colorPaletteYellowBorderActive
    _darkThemeColorList[ElaThemeType::colorPaletteYellowBorderActive] = QColor(0xFE, 0xEE, 0x66); // #feee66
    _lightThemeColorList[ElaThemeType::colorPaletteYellowBorderActive] = QColor(0xFD, 0xE3, 0x00); // #fde300

    // colorPaletteYellowBorder1
    _darkThemeColorList[ElaThemeType::colorPaletteYellowBorder1] = QColor(0xFD, 0xE3, 0x00); // #fde300
    _lightThemeColorList[ElaThemeType::colorPaletteYellowBorder1] = QColor(0xFE, 0xF7, 0xB2); // #fef7b2

    // colorPaletteYellowBorder2
    _darkThemeColorList[ElaThemeType::colorPaletteYellowBorder2] = QColor(0xFD, 0xEA, 0x3D); // #fdea3d
    _lightThemeColorList[ElaThemeType::colorPaletteYellowBorder2] = QColor(0xFD, 0xE3, 0x00); // #fde300

    // colorPaletteBerryBackground1
    _darkThemeColorList[ElaThemeType::colorPaletteBerryBackground1] = QColor(0x3A, 0x11, 0x36); // #3a1136
    _lightThemeColorList[ElaThemeType::colorPaletteBerryBackground1] = QColor(0xFD, 0xF5, 0xFC); // #fdf5fc

    // colorPaletteBerryBackground2
    _darkThemeColorList[ElaThemeType::colorPaletteBerryBackground2] = QColor(0x6D, 0x20, 0x64); // #6d2064
    _lightThemeColorList[ElaThemeType::colorPaletteBerryBackground2] = QColor(0xED, 0xBB, 0xE7); // #edbbe7

    // colorPaletteBerryBackground3
    _darkThemeColorList[ElaThemeType::colorPaletteBerryBackground3] = QColor(0xC2, 0x39, 0xB3); // #c239b3
    _lightThemeColorList[ElaThemeType::colorPaletteBerryBackground3] = QColor(0xC2, 0x39, 0xB3); // #c239b3

    // colorPaletteBerryForeground1
    _darkThemeColorList[ElaThemeType::colorPaletteBerryForeground1] = QColor(0xDA, 0x7E, 0xD0); // #da7ed0
    _lightThemeColorList[ElaThemeType::colorPaletteBerryForeground1] = QColor(0xAF, 0x33, 0xA1); // #af33a1

    // colorPaletteBerryForeground2
    _darkThemeColorList[ElaThemeType::colorPaletteBerryForeground2] = QColor(0xED, 0xBB, 0xE7); // #edbbe7
    _lightThemeColorList[ElaThemeType::colorPaletteBerryForeground2] = QColor(0x6D, 0x20, 0x64); // #6d2064

    // colorPaletteBerryForeground3
    _darkThemeColorList[ElaThemeType::colorPaletteBerryForeground3] = QColor(0xD1, 0x61, 0xC4); // #d161c4
    _lightThemeColorList[ElaThemeType::colorPaletteBerryForeground3] = QColor(0xC2, 0x39, 0xB3); // #c239b3

    // colorPaletteBerryBorderActive
    _darkThemeColorList[ElaThemeType::colorPaletteBerryBorderActive] = QColor(0xDA, 0x7E, 0xD0); // #da7ed0
    _lightThemeColorList[ElaThemeType::colorPaletteBerryBorderActive] = QColor(0xC2, 0x39, 0xB3); // #c239b3

    // colorPaletteBerryBorder1
    _darkThemeColorList[ElaThemeType::colorPaletteBerryBorder1] = QColor(0xC2, 0x39, 0xB3); // #c239b3
    _lightThemeColorList[ElaThemeType::colorPaletteBerryBorder1] = QColor(0xED, 0xBB, 0xE7); // #edbbe7

    // colorPaletteBerryBorder2
    _darkThemeColorList[ElaThemeType::colorPaletteBerryBorder2] = QColor(0xD1, 0x61, 0xC4); // #d161c4
    _lightThemeColorList[ElaThemeType::colorPaletteBerryBorder2] = QColor(0xC2, 0x39, 0xB3); // #c239b3

    // colorPaletteLightGreenBackground1
    _darkThemeColorList[ElaThemeType::colorPaletteLightGreenBackground1] = QColor(0x06, 0x30, 0x04); // #063004
    _lightThemeColorList[ElaThemeType::colorPaletteLightGreenBackground1] = QColor(0xF2, 0xFB, 0xF2); // #f2fbf2

    // colorPaletteLightGreenBackground2
    _darkThemeColorList[ElaThemeType::colorPaletteLightGreenBackground2] = QColor(0x0B, 0x5A, 0x08); // #0b5a08
    _lightThemeColorList[ElaThemeType::colorPaletteLightGreenBackground2] = QColor(0xA7, 0xE3, 0xA5); // #a7e3a5

    // colorPaletteLightGreenBackground3
    _darkThemeColorList[ElaThemeType::colorPaletteLightGreenBackground3] = QColor(0x13, 0xA1, 0x0E); // #13a10e
    _lightThemeColorList[ElaThemeType::colorPaletteLightGreenBackground3] = QColor(0x13, 0xA1, 0x0E); // #13a10e

    // colorPaletteLightGreenForeground1
    _darkThemeColorList[ElaThemeType::colorPaletteLightGreenForeground1] = QColor(0x5E, 0xC7, 0x5A); // #5ec75a
    _lightThemeColorList[ElaThemeType::colorPaletteLightGreenForeground1] = QColor(0x11, 0x91, 0x0D); // #11910d

    // colorPaletteLightGreenForeground2
    _darkThemeColorList[ElaThemeType::colorPaletteLightGreenForeground2] = QColor(0xA7, 0xE3, 0xA5); // #a7e3a5
    _lightThemeColorList[ElaThemeType::colorPaletteLightGreenForeground2] = QColor(0x0B, 0x5A, 0x08); // #0b5a08

    // colorPaletteLightGreenForeground3
    _darkThemeColorList[ElaThemeType::colorPaletteLightGreenForeground3] = QColor(0x3D, 0xB8, 0x38); // #3db838
    _lightThemeColorList[ElaThemeType::colorPaletteLightGreenForeground3] = QColor(0x13, 0xA1, 0x0E); // #13a10e

    // colorPaletteLightGreenBorderActive
    _darkThemeColorList[ElaThemeType::colorPaletteLightGreenBorderActive] = QColor(0x5E, 0xC7, 0x5A); // #5ec75a
    _lightThemeColorList[ElaThemeType::colorPaletteLightGreenBorderActive] = QColor(0x13, 0xA1, 0x0E); // #13a10e

    // colorPaletteLightGreenBorder1
    _darkThemeColorList[ElaThemeType::colorPaletteLightGreenBorder1] = QColor(0x13, 0xA1, 0x0E); // #13a10e
    _lightThemeColorList[ElaThemeType::colorPaletteLightGreenBorder1] = QColor(0xA7, 0xE3, 0xA5); // #a7e3a5

    // colorPaletteLightGreenBorder2
    _darkThemeColorList[ElaThemeType::colorPaletteLightGreenBorder2] = QColor(0x3D, 0xB8, 0x38); // #3db838
    _lightThemeColorList[ElaThemeType::colorPaletteLightGreenBorder2] = QColor(0x13, 0xA1, 0x0E); // #13a10e

    // colorPaletteMarigoldBackground1
    _darkThemeColorList[ElaThemeType::colorPaletteMarigoldBackground1] = QColor(0x46, 0x31, 0x00); // #463100
    _lightThemeColorList[ElaThemeType::colorPaletteMarigoldBackground1] = QColor(0xFE, 0xFB, 0xF4); // #fefbf4

    // colorPaletteMarigoldBackground2
    _darkThemeColorList[ElaThemeType::colorPaletteMarigoldBackground2] = QColor(0x83, 0x5B, 0x00); // #835b00
    _lightThemeColorList[ElaThemeType::colorPaletteMarigoldBackground2] = QColor(0xF9, 0xE2, 0xAE); // #f9e2ae

    // colorPaletteMarigoldBackground3
    _darkThemeColorList[ElaThemeType::colorPaletteMarigoldBackground3] = QColor(0xEA, 0xA3, 0x00); // #eaa300
    _lightThemeColorList[ElaThemeType::colorPaletteMarigoldBackground3] = QColor(0xEA, 0xA3, 0x00); // #eaa300

    // colorPaletteMarigoldForeground1
    _darkThemeColorList[ElaThemeType::colorPaletteMarigoldForeground1] = QColor(0xF2, 0xC6, 0x61); // #f2c661
    _lightThemeColorList[ElaThemeType::colorPaletteMarigoldForeground1] = QColor(0xD3, 0x93, 0x00); // #d39300

    // colorPaletteMarigoldForeground2
    _darkThemeColorList[ElaThemeType::colorPaletteMarigoldForeground2] = QColor(0xF9, 0xE2, 0xAE); // #f9e2ae
    _lightThemeColorList[ElaThemeType::colorPaletteMarigoldForeground2] = QColor(0x83, 0x5B, 0x00); // #835b00

    // colorPaletteMarigoldForeground3
    _darkThemeColorList[ElaThemeType::colorPaletteMarigoldForeground3] = QColor(0xEF, 0xB8, 0x39); // #efb839
    _lightThemeColorList[ElaThemeType::colorPaletteMarigoldForeground3] = QColor(0xEA, 0xA3, 0x00); // #eaa300

    // colorPaletteMarigoldBorderActive
    _darkThemeColorList[ElaThemeType::colorPaletteMarigoldBorderActive] = QColor(0xF2, 0xC6, 0x61); // #f2c661
    _lightThemeColorList[ElaThemeType::colorPaletteMarigoldBorderActive] = QColor(0xEA, 0xA3, 0x00); // #eaa300

    // colorPaletteMarigoldBorder1
    _darkThemeColorList[ElaThemeType::colorPaletteMarigoldBorder1] = QColor(0xEA, 0xA3, 0x00); // #eaa300
    _lightThemeColorList[ElaThemeType::colorPaletteMarigoldBorder1] = QColor(0xF9, 0xE2, 0xAE); // #f9e2ae

    // colorPaletteMarigoldBorder2
    _darkThemeColorList[ElaThemeType::colorPaletteMarigoldBorder2] = QColor(0xEF, 0xB8, 0x39); // #efb839
    _lightThemeColorList[ElaThemeType::colorPaletteMarigoldBorder2] = QColor(0xEA, 0xA3, 0x00); // #eaa300

    // colorPaletteRedForegroundInverted
    _darkThemeColorList[ElaThemeType::colorPaletteRedForegroundInverted] = QColor(0xD1, 0x34, 0x38); // #d13438
    _lightThemeColorList[ElaThemeType::colorPaletteRedForegroundInverted] = QColor(0xDC, 0x5E, 0x62); // #dc5e62

    // colorPaletteGreenForegroundInverted
    _darkThemeColorList[ElaThemeType::colorPaletteGreenForegroundInverted] = QColor(0x10, 0x7C, 0x10); // #107c10
    _lightThemeColorList[ElaThemeType::colorPaletteGreenForegroundInverted] = QColor(0x35, 0x9B, 0x35); // #359b35

    // colorPaletteYellowForegroundInverted
    _darkThemeColorList[ElaThemeType::colorPaletteYellowForegroundInverted] = QColor(0x81, 0x74, 0x00); // #817400
    _lightThemeColorList[ElaThemeType::colorPaletteYellowForegroundInverted] = QColor(0xFE, 0xF7, 0xB2); // #fef7b2

    // colorPaletteDarkRedBackground2
    _darkThemeColorList[ElaThemeType::colorPaletteDarkRedBackground2] = QColor(0x59, 0x08, 0x15); // #590815
    _lightThemeColorList[ElaThemeType::colorPaletteDarkRedBackground2] = QColor(0xD6, 0x9C, 0xA5); // #d69ca5

    // colorPaletteDarkRedForeground2
    _darkThemeColorList[ElaThemeType::colorPaletteDarkRedForeground2] = QColor(0xD6, 0x9C, 0xA5); // #d69ca5
    _lightThemeColorList[ElaThemeType::colorPaletteDarkRedForeground2] = QColor(0x42, 0x06, 0x10); // #420610

    // colorPaletteDarkRedBorderActive
    _darkThemeColorList[ElaThemeType::colorPaletteDarkRedBorderActive] = QColor(0xAC, 0x4F, 0x5E); // #ac4f5e
    _lightThemeColorList[ElaThemeType::colorPaletteDarkRedBorderActive] = QColor(0x75, 0x0B, 0x1C); // #750b1c

    // colorPaletteCranberryBackground2
    _darkThemeColorList[ElaThemeType::colorPaletteCranberryBackground2] = QColor(0x6E, 0x08, 0x11); // #6e0811
    _lightThemeColorList[ElaThemeType::colorPaletteCranberryBackground2] = QColor(0xEE, 0xAC, 0xB2); // #eeacb2

    // colorPaletteCranberryForeground2
    _darkThemeColorList[ElaThemeType::colorPaletteCranberryForeground2] = QColor(0xEE, 0xAC, 0xB2); // #eeacb2
    _lightThemeColorList[ElaThemeType::colorPaletteCranberryForeground2] = QColor(0x6E, 0x08, 0x11); // #6e0811

    // colorPaletteCranberryBorderActive
    _darkThemeColorList[ElaThemeType::colorPaletteCranberryBorderActive] = QColor(0xDC, 0x62, 0x6D); // #dc626d
    _lightThemeColorList[ElaThemeType::colorPaletteCranberryBorderActive] = QColor(0xC5, 0x0F, 0x1F); // #c50f1f

    // colorPalettePumpkinBackground2
    _darkThemeColorList[ElaThemeType::colorPalettePumpkinBackground2] = QColor(0x71, 0x2D, 0x09); // #712d09
    _lightThemeColorList[ElaThemeType::colorPalettePumpkinBackground2] = QColor(0xEF, 0xC4, 0xAD); // #efc4ad

    // colorPalettePumpkinForeground2
    _darkThemeColorList[ElaThemeType::colorPalettePumpkinForeground2] = QColor(0xEF, 0xC4, 0xAD); // #efc4ad
    _lightThemeColorList[ElaThemeType::colorPalettePumpkinForeground2] = QColor(0x71, 0x2D, 0x09); // #712d09

    // colorPalettePumpkinBorderActive
    _darkThemeColorList[ElaThemeType::colorPalettePumpkinBorderActive] = QColor(0xDF, 0x8E, 0x64); // #df8e64
    _lightThemeColorList[ElaThemeType::colorPalettePumpkinBorderActive] = QColor(0xCA, 0x50, 0x10); // #ca5010

    // colorPalettePeachBackground2
    _darkThemeColorList[ElaThemeType::colorPalettePeachBackground2] = QColor(0x8F, 0x4E, 0x00); // #8f4e00
    _lightThemeColorList[ElaThemeType::colorPalettePeachBackground2] = QColor(0xFF, 0xDD, 0xB3); // #ffddb3

    // colorPalettePeachForeground2
    _darkThemeColorList[ElaThemeType::colorPalettePeachForeground2] = QColor(0xFF, 0xDD, 0xB3); // #ffddb3
    _lightThemeColorList[ElaThemeType::colorPalettePeachForeground2] = QColor(0x8F, 0x4E, 0x00); // #8f4e00

    // colorPalettePeachBorderActive
    _darkThemeColorList[ElaThemeType::colorPalettePeachBorderActive] = QColor(0xFF, 0xBA, 0x66); // #ffba66
    _lightThemeColorList[ElaThemeType::colorPalettePeachBorderActive] = QColor(0xFF, 0x8C, 0x00); // #ff8c00

    // colorPaletteGoldBackground2
    _darkThemeColorList[ElaThemeType::colorPaletteGoldBackground2] = QColor(0x6C, 0x57, 0x00); // #6c5700
    _lightThemeColorList[ElaThemeType::colorPaletteGoldBackground2] = QColor(0xEC, 0xDF, 0xA5); // #ecdfa5

    // colorPaletteGoldForeground2
    _darkThemeColorList[ElaThemeType::colorPaletteGoldForeground2] = QColor(0xEC, 0xDF, 0xA5); // #ecdfa5
    _lightThemeColorList[ElaThemeType::colorPaletteGoldForeground2] = QColor(0x6C, 0x57, 0x00); // #6c5700

    // colorPaletteGoldBorderActive
    _darkThemeColorList[ElaThemeType::colorPaletteGoldBorderActive] = QColor(0xDA, 0xC1, 0x57); // #dac157
    _lightThemeColorList[ElaThemeType::colorPaletteGoldBorderActive] = QColor(0xC1, 0x9C, 0x00); // #c19c00

    // colorPaletteBrassBackground2
    _darkThemeColorList[ElaThemeType::colorPaletteBrassBackground2] = QColor(0x55, 0x3E, 0x06); // #553e06
    _lightThemeColorList[ElaThemeType::colorPaletteBrassBackground2] = QColor(0xE0, 0xCE, 0xA2); // #e0cea2

    // colorPaletteBrassForeground2
    _darkThemeColorList[ElaThemeType::colorPaletteBrassForeground2] = QColor(0xE0, 0xCE, 0xA2); // #e0cea2
    _lightThemeColorList[ElaThemeType::colorPaletteBrassForeground2] = QColor(0x55, 0x3E, 0x06); // #553e06

    // colorPaletteBrassBorderActive
    _darkThemeColorList[ElaThemeType::colorPaletteBrassBorderActive] = QColor(0xC1, 0xA2, 0x56); // #c1a256
    _lightThemeColorList[ElaThemeType::colorPaletteBrassBorderActive] = QColor(0x98, 0x6F, 0x0B); // #986f0b

    // colorPaletteBrownBackground2
    _darkThemeColorList[ElaThemeType::colorPaletteBrownBackground2] = QColor(0x50, 0x30, 0x1A); // #50301a
    _lightThemeColorList[ElaThemeType::colorPaletteBrownBackground2] = QColor(0xDD, 0xC3, 0xB0); // #ddc3b0

    // colorPaletteBrownForeground2
    _darkThemeColorList[ElaThemeType::colorPaletteBrownForeground2] = QColor(0xDD, 0xC3, 0xB0); // #ddc3b0
    _lightThemeColorList[ElaThemeType::colorPaletteBrownForeground2] = QColor(0x50, 0x30, 0x1A); // #50301a

    // colorPaletteBrownBorderActive
    _darkThemeColorList[ElaThemeType::colorPaletteBrownBorderActive] = QColor(0xBB, 0x8F, 0x6F); // #bb8f6f
    _lightThemeColorList[ElaThemeType::colorPaletteBrownBorderActive] = QColor(0x8E, 0x56, 0x2E); // #8e562e

    // colorPaletteForestBackground2
    _darkThemeColorList[ElaThemeType::colorPaletteForestBackground2] = QColor(0x29, 0x49, 0x03); // #294903
    _lightThemeColorList[ElaThemeType::colorPaletteForestBackground2] = QColor(0xBD, 0xD9, 0x9B); // #bdd99b

    // colorPaletteForestForeground2
    _darkThemeColorList[ElaThemeType::colorPaletteForestForeground2] = QColor(0xBD, 0xD9, 0x9B); // #bdd99b
    _lightThemeColorList[ElaThemeType::colorPaletteForestForeground2] = QColor(0x29, 0x49, 0x03); // #294903

    // colorPaletteForestBorderActive
    _darkThemeColorList[ElaThemeType::colorPaletteForestBorderActive] = QColor(0x85, 0xB4, 0x4C); // #85b44c
    _lightThemeColorList[ElaThemeType::colorPaletteForestBorderActive] = QColor(0x49, 0x82, 0x05); // #498205

    // colorPaletteSeafoamBackground2
    _darkThemeColorList[ElaThemeType::colorPaletteSeafoamBackground2] = QColor(0x00, 0x72, 0x3B); // #00723b
    _lightThemeColorList[ElaThemeType::colorPaletteSeafoamBackground2] = QColor(0xA8, 0xF0, 0xCD); // #a8f0cd

    // colorPaletteSeafoamForeground2
    _darkThemeColorList[ElaThemeType::colorPaletteSeafoamForeground2] = QColor(0xA8, 0xF0, 0xCD); // #a8f0cd
    _lightThemeColorList[ElaThemeType::colorPaletteSeafoamForeground2] = QColor(0x00, 0x72, 0x3B); // #00723b

    // colorPaletteSeafoamBorderActive
    _darkThemeColorList[ElaThemeType::colorPaletteSeafoamBorderActive] = QColor(0x5A, 0xE0, 0xA0); // #5ae0a0
    _lightThemeColorList[ElaThemeType::colorPaletteSeafoamBorderActive] = QColor(0x00, 0xCC, 0x6A); // #00cc6a

    // colorPaletteDarkGreenBackground2
    _darkThemeColorList[ElaThemeType::colorPaletteDarkGreenBackground2] = QColor(0x06, 0x3B, 0x06); // #063b06
    _lightThemeColorList[ElaThemeType::colorPaletteDarkGreenBackground2] = QColor(0x9A, 0xD2, 0x9A); // #9ad29a

    // colorPaletteDarkGreenForeground2
    _darkThemeColorList[ElaThemeType::colorPaletteDarkGreenForeground2] = QColor(0x9A, 0xD2, 0x9A);  // #9ad29a
    _lightThemeColorList[ElaThemeType::colorPaletteDarkGreenForeground2] = QColor(0x06, 0x3B, 0x06); // #063b06

    // colorPaletteDarkGreenBorderActive
    _darkThemeColorList[ElaThemeType::colorPaletteDarkGreenBorderActive] = QColor(0x4D, 0xA6, 0x4D); // #4da64d
    _lightThemeColorList[ElaThemeType::colorPaletteDarkGreenBorderActive] = QColor(0x0B, 0x6A, 0x0B); // #0b6a0b

    // colorPaletteLightTealBackground2
    _darkThemeColorList[ElaThemeType::colorPaletteLightTealBackground2] = QColor(0x00, 0x66, 0x6D); // #00666d
    _lightThemeColorList[ElaThemeType::colorPaletteLightTealBackground2] = QColor(0xA6, 0xE9, 0xED); // #a6e9ed

    // colorPaletteLightTealForeground2
    _darkThemeColorList[ElaThemeType::colorPaletteLightTealForeground2] = QColor(0xA6, 0xE9, 0xED); // #a6e9ed
    _lightThemeColorList[ElaThemeType::colorPaletteLightTealForeground2] = QColor(0x00, 0x66, 0x6D); // #00666d

    // colorPaletteLightTealBorderActive
    _darkThemeColorList[ElaThemeType::colorPaletteLightTealBorderActive] = QColor(0x58, 0xD3, 0xDB); // #58d3db
    _lightThemeColorList[ElaThemeType::colorPaletteLightTealBorderActive] = QColor(0x00, 0xB7, 0xC3); // #00b7c3

    // colorPaletteTealBackground2
    _darkThemeColorList[ElaThemeType::colorPaletteTealBackground2] = QColor(0x02, 0x49, 0x4C); // #02494c
    _lightThemeColorList[ElaThemeType::colorPaletteTealBackground2] = QColor(0x9B, 0xD9, 0xDB); // #9bd9db

    // colorPaletteTealForeground2
    _darkThemeColorList[ElaThemeType::colorPaletteTealForeground2] = QColor(0x9B, 0xD9, 0xDB); // #9bd9db
    _lightThemeColorList[ElaThemeType::colorPaletteTealForeground2] = QColor(0x02, 0x49, 0x4C); // #02494c

    // colorPaletteTealBorderActive
    _darkThemeColorList[ElaThemeType::colorPaletteTealBorderActive] = QColor(0x4C, 0xB4, 0xB7); // #4cb4b7
    _lightThemeColorList[ElaThemeType::colorPaletteTealBorderActive] = QColor(0x03, 0x83, 0x87); // #038387

    // colorPaletteSteelBackground2
    _darkThemeColorList[ElaThemeType::colorPaletteSteelBackground2] = QColor(0x00, 0x33, 0x3F); // #00333f
    _lightThemeColorList[ElaThemeType::colorPaletteSteelBackground2] = QColor(0x94, 0xC8, 0xD4); // #94c8d4

    // colorPaletteSteelForeground2
    _darkThemeColorList[ElaThemeType::colorPaletteSteelForeground2] = QColor(0x94, 0xC8, 0xD4); // #94c8d4
    _lightThemeColorList[ElaThemeType::colorPaletteSteelForeground2] = QColor(0x00, 0x33, 0x3F); // #00333f

    // colorPaletteSteelBorderActive
    _darkThemeColorList[ElaThemeType::colorPaletteSteelBorderActive] = QColor(0x44, 0x96, 0xA9); // #4496a9
    _lightThemeColorList[ElaThemeType::colorPaletteSteelBorderActive] = QColor(0x00, 0x5B, 0x70); // #005b70

    // colorPaletteBlueBackground2
    _darkThemeColorList[ElaThemeType::colorPaletteBlueBackground2] = QColor(0x00, 0x43, 0x77); // #004377
    _lightThemeColorList[ElaThemeType::colorPaletteBlueBackground2] = QColor(0xA9, 0xD3, 0xF2); // #a9d3f2

    // colorPaletteBlueForeground2
    _darkThemeColorList[ElaThemeType::colorPaletteBlueForeground2] = QColor(0xA9, 0xD3, 0xF2); // #a9d3f2
    _lightThemeColorList[ElaThemeType::colorPaletteBlueForeground2] = QColor(0x00, 0x43, 0x77); // #004377

    // colorPaletteBlueBorderActive
    _darkThemeColorList[ElaThemeType::colorPaletteBlueBorderActive] = QColor(0x5C, 0xAA, 0xE5); // #5caae5
    _lightThemeColorList[ElaThemeType::colorPaletteBlueBorderActive] = QColor(0x00, 0x78, 0xD4); // #0078d4

    // colorPaletteRoyalBlueBackground2
    _darkThemeColorList[ElaThemeType::colorPaletteRoyalBlueBackground2] = QColor(0x00, 0x2C, 0x4E); // #002c4e
    _lightThemeColorList[ElaThemeType::colorPaletteRoyalBlueBackground2] = QColor(0x9A, 0xBF, 0xDC); // #9abfdc

    // colorPaletteRoyalBlueForeground2
    _darkThemeColorList[ElaThemeType::colorPaletteRoyalBlueForeground2] = QColor(0x9A, 0xBF, 0xDC); // #9abfdc
    _lightThemeColorList[ElaThemeType::colorPaletteRoyalBlueForeground2] = QColor(0x00, 0x2C, 0x4E); // #002c4e

    // colorPaletteRoyalBlueBorderActive
    _darkThemeColorList[ElaThemeType::colorPaletteRoyalBlueBorderActive] = QColor(0x4A, 0x89, 0xBA); // #4a89ba
    _lightThemeColorList[ElaThemeType::colorPaletteRoyalBlueBorderActive] = QColor(0x00, 0x4E, 0x8C); // #004e8c

    // colorPaletteCornflowerBackground2
    _darkThemeColorList[ElaThemeType::colorPaletteCornflowerBackground2] = QColor(0x2C, 0x3C, 0x85); // #2c3c85
    _lightThemeColorList[ElaThemeType::colorPaletteCornflowerBackground2] = QColor(0xC8, 0xD1, 0xFA); // #c8d1fa

    // colorPaletteCornflowerForeground2
    _darkThemeColorList[ElaThemeType::colorPaletteCornflowerForeground2] = QColor(0xC8, 0xD1, 0xFA); // #c8d1fa
    _lightThemeColorList[ElaThemeType::colorPaletteCornflowerForeground2] = QColor(0x2C, 0x3C, 0x85); // #2c3c85

    // colorPaletteCornflowerBorderActive
    _darkThemeColorList[ElaThemeType::colorPaletteCornflowerBorderActive] = QColor(0x93, 0xA4, 0xF4); // #93a4f4
    _lightThemeColorList[ElaThemeType::colorPaletteCornflowerBorderActive] = QColor(0x4F, 0x6B, 0xED); // #4f6bed

    // colorPaletteNavyBackground2
    _darkThemeColorList[ElaThemeType::colorPaletteNavyBackground2] = QColor(0x00, 0x16, 0x65); // #001665
    _lightThemeColorList[ElaThemeType::colorPaletteNavyBackground2] = QColor(0xA3, 0xB2, 0xE8); // #a3b2e8

    // colorPaletteNavyForeground2
    _darkThemeColorList[ElaThemeType::colorPaletteNavyForeground2] = QColor(0xA3, 0xB2, 0xE8); // #a3b2e8
    _lightThemeColorList[ElaThemeType::colorPaletteNavyForeground2] = QColor(0x00, 0x16, 0x65); // #001665

    // colorPaletteNavyBorderActive
    _darkThemeColorList[ElaThemeType::colorPaletteNavyBorderActive] = QColor(0x54, 0x6F, 0xD2); // #546fd2
    _lightThemeColorList[ElaThemeType::colorPaletteNavyBorderActive] = QColor(0x00, 0x27, 0xB4); // #0027b4

    // colorPaletteLavenderBackground2
    _darkThemeColorList[ElaThemeType::colorPaletteLavenderBackground2] = QColor(0x3F, 0x36, 0x82); // #3f3682
    _lightThemeColorList[ElaThemeType::colorPaletteLavenderBackground2] = QColor(0xD2, 0xCC, 0xF8); // #d2ccf8

    // colorPaletteLavenderForeground2
    _darkThemeColorList[ElaThemeType::colorPaletteLavenderForeground2] = QColor(0xD2, 0xCC, 0xF8); // #d2ccf8
    _lightThemeColorList[ElaThemeType::colorPaletteLavenderForeground2] = QColor(0x3F, 0x36, 0x82); // #3f3682

    // colorPaletteLavenderBorderActive
    _darkThemeColorList[ElaThemeType::colorPaletteLavenderBorderActive] = QColor(0xA7, 0x9C, 0xF1); // #a79cf1
    _lightThemeColorList[ElaThemeType::colorPaletteLavenderBorderActive] = QColor(0x71, 0x60, 0xE8); // #7160e8

    // colorPalettePurpleBackground2
    _darkThemeColorList[ElaThemeType::colorPalettePurpleBackground2] = QColor(0x34, 0x1A, 0x51); // #341a51
    _lightThemeColorList[ElaThemeType::colorPalettePurpleBackground2] = QColor(0xC6, 0xB1, 0xDE); // #c6b1de

    // colorPalettePurpleForeground2
    _darkThemeColorList[ElaThemeType::colorPalettePurpleForeground2] = QColor(0xC6, 0xB1, 0xDE); // #c6b1de
    _lightThemeColorList[ElaThemeType::colorPalettePurpleForeground2] = QColor(0x34, 0x1A, 0x51); // #341a51

    // colorPalettePurpleBorderActive
    _darkThemeColorList[ElaThemeType::colorPalettePurpleBorderActive] = QColor(0x94, 0x70, 0xBD); // #9470bd
    _lightThemeColorList[ElaThemeType::colorPalettePurpleBorderActive] = QColor(0x5C, 0x2E, 0x91); // #5c2e91

    // colorPaletteGrapeBackground2
    _darkThemeColorList[ElaThemeType::colorPaletteGrapeBackground2] = QColor(0x4C, 0x0D, 0x55); // #4c0d55
    _lightThemeColorList[ElaThemeType::colorPaletteGrapeBackground2] = QColor(0xD9, 0xA7, 0xE0); // #d9a7e0

    // colorPaletteGrapeForeground2
    _darkThemeColorList[ElaThemeType::colorPaletteGrapeForeground2] = QColor(0xD9, 0xA7, 0xE0); // #d9a7e0
    _lightThemeColorList[ElaThemeType::colorPaletteGrapeForeground2] = QColor(0x4C, 0x0D, 0x55); // #4c0d55

    // colorPaletteGrapeBorderActive
    _darkThemeColorList[ElaThemeType::colorPaletteGrapeBorderActive] = QColor(0xB5, 0x5F, 0xC1); // #b55fc1
    _lightThemeColorList[ElaThemeType::colorPaletteGrapeBorderActive] = QColor(0x88, 0x17, 0x98); // #881798

    // colorPaletteLilacBackground2
    _darkThemeColorList[ElaThemeType::colorPaletteLilacBackground2] = QColor(0x63, 0x27, 0x6D); // #63276d
    _lightThemeColorList[ElaThemeType::colorPaletteLilacBackground2] = QColor(0xE6, 0xBF, 0xED); // #e6bfed

    // colorPaletteLilacForeground2
    _darkThemeColorList[ElaThemeType::colorPaletteLilacForeground2] = QColor(0xE6, 0xBF, 0xED); // #e6bfed
    _lightThemeColorList[ElaThemeType::colorPaletteLilacForeground2] = QColor(0x63, 0x27, 0x6D); // #63276d

    // colorPaletteLilacBorderActive
    _darkThemeColorList[ElaThemeType::colorPaletteLilacBorderActive] = QColor(0xCF, 0x87, 0xDA); // #cf87da
    _lightThemeColorList[ElaThemeType::colorPaletteLilacBorderActive] = QColor(0xB1, 0x46, 0xC2); // #b146c2

    // colorPalettePinkBackground2
    _darkThemeColorList[ElaThemeType::colorPalettePinkBackground2] = QColor(0x80, 0x21, 0x5D); // #80215d
    _lightThemeColorList[ElaThemeType::colorPalettePinkBackground2] = QColor(0xF7, 0xC0, 0xE3); // #f7c0e3

    // colorPalettePinkForeground2
    _darkThemeColorList[ElaThemeType::colorPalettePinkForeground2] = QColor(0xF7, 0xC0, 0xE3); // #f7c0e3
    _lightThemeColorList[ElaThemeType::colorPalettePinkForeground2] = QColor(0x80, 0x21, 0x5D); // #80215d

    // colorPalettePinkBorderActive
    _darkThemeColorList[ElaThemeType::colorPalettePinkBorderActive] = QColor(0xEF, 0x85, 0xC8); // #ef85c8
    _lightThemeColorList[ElaThemeType::colorPalettePinkBorderActive] = QColor(0xE4, 0x3B, 0xA6); // #e43ba6

    // colorPaletteMagentaBackground2
    _darkThemeColorList[ElaThemeType::colorPaletteMagentaBackground2] = QColor(0x6B, 0x00, 0x43); // #6b0043
    _lightThemeColorList[ElaThemeType::colorPaletteMagentaBackground2] = QColor(0xEC, 0xA5, 0xD1); // #eca5d1

    // colorPaletteMagentaForeground2
    _darkThemeColorList[ElaThemeType::colorPaletteMagentaForeground2] = QColor(0xEC, 0xA5, 0xD1); // #eca5d1
    _lightThemeColorList[ElaThemeType::colorPaletteMagentaForeground2] = QColor(0x6B, 0x00, 0x43); // #6b0043

    // colorPaletteMagentaBorderActive
    _darkThemeColorList[ElaThemeType::colorPaletteMagentaBorderActive] = QColor(0xD9, 0x57, 0xA8); // #d957a8
    _lightThemeColorList[ElaThemeType::colorPaletteMagentaBorderActive] = QColor(0xBF, 0x00, 0x77); // #bf0077

    // colorPalettePlumBackground2
    _darkThemeColorList[ElaThemeType::colorPalettePlumBackground2] = QColor(0x5A, 0x00, 0x3B); // #5a003b
    _lightThemeColorList[ElaThemeType::colorPalettePlumBackground2] = QColor(0xD6, 0x96, 0xC0); // #d696c0

    // colorPalettePlumForeground2
    _darkThemeColorList[ElaThemeType::colorPalettePlumForeground2] = QColor(0xD6, 0x96, 0xC0); // #d696c0
    _lightThemeColorList[ElaThemeType::colorPalettePlumForeground2] = QColor(0x43, 0x00, 0x2B); // #43002b

    // colorPalettePlumBorderActive
    _darkThemeColorList[ElaThemeType::colorPalettePlumBorderActive] = QColor(0xAD, 0x45, 0x89); // #ad4589
    _lightThemeColorList[ElaThemeType::colorPalettePlumBorderActive] = QColor(0x77, 0x00, 0x4D); // #77004d

    // colorPaletteBeigeBackground2
    _darkThemeColorList[ElaThemeType::colorPaletteBeigeBackground2] = QColor(0x44, 0x42, 0x41); // #444241
    _lightThemeColorList[ElaThemeType::colorPaletteBeigeBackground2] = QColor(0xD7, 0xD4, 0xD4); // #d7d4d4

    // colorPaletteBeigeForeground2
    _darkThemeColorList[ElaThemeType::colorPaletteBeigeForeground2] = QColor(0xD7, 0xD4, 0xD4); // #d7d4d4
    _lightThemeColorList[ElaThemeType::colorPaletteBeigeForeground2] = QColor(0x44, 0x42, 0x41); // #444241

    // colorPaletteBeigeBorderActive
    _darkThemeColorList[ElaThemeType::colorPaletteBeigeBorderActive] = QColor(0xAF, 0xAB, 0xAA); // #afabaa
    _lightThemeColorList[ElaThemeType::colorPaletteBeigeBorderActive] = QColor(0x7A, 0x75, 0x74); // #7a7574

    // colorPaletteMinkBackground2
    _darkThemeColorList[ElaThemeType::colorPaletteMinkBackground2] = QColor(0x34, 0x32, 0x31); // #343231
    _lightThemeColorList[ElaThemeType::colorPaletteMinkBackground2] = QColor(0xCE, 0xCC, 0xCB); // #cecccb

    // colorPaletteMinkForeground2
    _darkThemeColorList[ElaThemeType::colorPaletteMinkForeground2] = QColor(0xCE, 0xCC, 0xCB); // #cecccb
    _lightThemeColorList[ElaThemeType::colorPaletteMinkForeground2] = QColor(0x34, 0x32, 0x31); // #343231

    // colorPaletteMinkBorderActive
    _darkThemeColorList[ElaThemeType::colorPaletteMinkBorderActive] = QColor(0x9E, 0x9B, 0x99); // #9e9b99
    _lightThemeColorList[ElaThemeType::colorPaletteMinkBorderActive] = QColor(0x5D, 0x5A, 0x58); // #5d5a58

    // colorPalettePlatinumBackground2
    _darkThemeColorList[ElaThemeType::colorPalettePlatinumBackground2] = QColor(0x3B, 0x44, 0x47); // #3b4447
    _lightThemeColorList[ElaThemeType::colorPalettePlatinumBackground2] = QColor(0xCD, 0xD6, 0xD8); // #cdd6d8

    // colorPalettePlatinumForeground2
    _darkThemeColorList[ElaThemeType::colorPalettePlatinumForeground2] = QColor(0xCD, 0xD6, 0xD8); // #cdd6d8
    _lightThemeColorList[ElaThemeType::colorPalettePlatinumForeground2] = QColor(0x3B, 0x44, 0x47); // #3b4447

    // colorPalettePlatinumBorderActive
    _darkThemeColorList[ElaThemeType::colorPalettePlatinumBorderActive] = QColor(0xA0, 0xAD, 0xB2); // #a0adb2
    _lightThemeColorList[ElaThemeType::colorPalettePlatinumBorderActive] = QColor(0x69, 0x79, 0x7E); // #69797e

    // colorPaletteAnchorBackground2
    _darkThemeColorList[ElaThemeType::colorPaletteAnchorBackground2] = QColor(0x20, 0x24, 0x27); // #202427
    _lightThemeColorList[ElaThemeType::colorPaletteAnchorBackground2] = QColor(0xBC, 0xC3, 0xC7); // #bcc3c7

    // colorPaletteAnchorForeground2
    _darkThemeColorList[ElaThemeType::colorPaletteAnchorForeground2] = QColor(0xBC, 0xC3, 0xC7); // #bcc3c7
    _lightThemeColorList[ElaThemeType::colorPaletteAnchorForeground2] = QColor(0x20, 0x24, 0x27); // #202427

    // colorPaletteAnchorBorderActive
    _darkThemeColorList[ElaThemeType::colorPaletteAnchorBorderActive] = QColor(0x80, 0x8A, 0x90); // #808a90
    _lightThemeColorList[ElaThemeType::colorPaletteAnchorBorderActive] = QColor(0x39, 0x41, 0x46); // #394146

        // colorStatusSuccessBackground1
    _darkThemeColorList[ElaThemeType::colorStatusSuccessBackground1] = QColor(0x05, 0x25, 0x05); // #052505
    _lightThemeColorList[ElaThemeType::colorStatusSuccessBackground1] = QColor(0xF1, 0xFA, 0xF1); // #f1faf1

    // colorStatusSuccessBackground2
    _darkThemeColorList[ElaThemeType::colorStatusSuccessBackground2] = QColor(0x09, 0x45, 0x09); // #094509
    _lightThemeColorList[ElaThemeType::colorStatusSuccessBackground2] = QColor(0x9F, 0xD8, 0x9F); // #9fd89f

    // colorStatusSuccessBackground3
    _darkThemeColorList[ElaThemeType::colorStatusSuccessBackground3] = QColor(0x10, 0x7C, 0x10); // #107c10
    _lightThemeColorList[ElaThemeType::colorStatusSuccessBackground3] = QColor(0x10, 0x7C, 0x10); // #107c10

    // colorStatusSuccessForeground1
    _darkThemeColorList[ElaThemeType::colorStatusSuccessForeground1] = QColor(0x54, 0xB0, 0x54); // #54b054
    _lightThemeColorList[ElaThemeType::colorStatusSuccessForeground1] = QColor(0x0E, 0x70, 0x0E); // #0e700e

    // colorStatusSuccessForeground2
    _darkThemeColorList[ElaThemeType::colorStatusSuccessForeground2] = QColor(0x9F, 0xD8, 0x9F); // #9fd89f
    _lightThemeColorList[ElaThemeType::colorStatusSuccessForeground2] = QColor(0x09, 0x45, 0x09); // #094509

    // colorStatusSuccessForeground3
    _darkThemeColorList[ElaThemeType::colorStatusSuccessForeground3] = QColor(0x9F, 0xD8, 0x9F); // #9fd89f
    _lightThemeColorList[ElaThemeType::colorStatusSuccessForeground3] = QColor(0x10, 0x7C, 0x10); // #107c10

    // colorStatusSuccessForegroundInverted
    _darkThemeColorList[ElaThemeType::colorStatusSuccessForegroundInverted] = QColor(0x0E, 0x70, 0x0E); // #0e700e
    _lightThemeColorList[ElaThemeType::colorStatusSuccessForegroundInverted] = QColor(0x54, 0xB0, 0x54); // #54b054

    // colorStatusSuccessBorderActive
    _darkThemeColorList[ElaThemeType::colorStatusSuccessBorderActive] = QColor(0x54, 0xB0, 0x54); // #54b054
    _lightThemeColorList[ElaThemeType::colorStatusSuccessBorderActive] = QColor(0x10, 0x7C, 0x10); // #107c10

    // colorStatusSuccessBorder1
    _darkThemeColorList[ElaThemeType::colorStatusSuccessBorder1] = QColor(0x10, 0x7C, 0x10); // #107c10
    _lightThemeColorList[ElaThemeType::colorStatusSuccessBorder1] = QColor(0x9F, 0xD8, 0x9F); // #9fd89f

    // colorStatusSuccessBorder2
    _darkThemeColorList[ElaThemeType::colorStatusSuccessBorder2] = QColor(0x9F, 0xD8, 0x9F); // #9fd89f
    _lightThemeColorList[ElaThemeType::colorStatusSuccessBorder2] = QColor(0x10, 0x7C, 0x10); // #107c10

    // colorStatusWarningBackground1
    _darkThemeColorList[ElaThemeType::colorStatusWarningBackground1] = QColor(0x4A, 0x1E, 0x04); // #4a1e04
    _lightThemeColorList[ElaThemeType::colorStatusWarningBackground1] = QColor(0xFF, 0xF9, 0xF5); // #fff9f5

    // colorStatusWarningBackground2
    _darkThemeColorList[ElaThemeType::colorStatusWarningBackground2] = QColor(0x8A, 0x37, 0x07); // #8a3707
    _lightThemeColorList[ElaThemeType::colorStatusWarningBackground2] = QColor(0xFD, 0xCF, 0xB4); // #fdcfb4

    // colorStatusWarningBackground3
    _darkThemeColorList[ElaThemeType::colorStatusWarningBackground3] = QColor(0xF7, 0x63, 0x0C); // #f7630c
    _lightThemeColorList[ElaThemeType::colorStatusWarningBackground3] = QColor(0xF7, 0x63, 0x0C); // #f7630c

    // colorStatusWarningForeground1
    _darkThemeColorList[ElaThemeType::colorStatusWarningForeground1] = QColor(0xFA, 0xA0, 0x6B); // #faa06b
    _lightThemeColorList[ElaThemeType::colorStatusWarningForeground1] = QColor(0xBC, 0x4B, 0x09); // #bc4b09

    // colorStatusWarningForeground2
    _darkThemeColorList[ElaThemeType::colorStatusWarningForeground2] = QColor(0xFD, 0xCF, 0xB4); // #fdcfb4
    _lightThemeColorList[ElaThemeType::colorStatusWarningForeground2] = QColor(0x8A, 0x37, 0x07); // #8a3707

    // colorStatusWarningForeground3
    _darkThemeColorList[ElaThemeType::colorStatusWarningForeground3] = QColor(0xF9, 0x88, 0x45); // #f98845
    _lightThemeColorList[ElaThemeType::colorStatusWarningForeground3] = QColor(0xBC, 0x4B, 0x09); // #bc4b09

    // colorStatusWarningForegroundInverted
    _darkThemeColorList[ElaThemeType::colorStatusWarningForegroundInverted] = QColor(0xBC, 0x4B, 0x09); // #bc4b09
    _lightThemeColorList[ElaThemeType::colorStatusWarningForegroundInverted] = QColor(0xFA, 0xA0, 0x6B); // #faa06b

    // colorStatusWarningBorderActive
    _darkThemeColorList[ElaThemeType::colorStatusWarningBorderActive] = QColor(0xFA, 0xA0, 0x6B); // #faa06b
    _lightThemeColorList[ElaThemeType::colorStatusWarningBorderActive] = QColor(0xF7, 0x63, 0x0C); // #f7630c

    // colorStatusWarningBorder1
    _darkThemeColorList[ElaThemeType::colorStatusWarningBorder1] = QColor(0xF7, 0x63, 0x0C); // #f7630c
    _lightThemeColorList[ElaThemeType::colorStatusWarningBorder1] = QColor(0xFD, 0xCF, 0xB4); // #fdcfb4

    // colorStatusWarningBorder2
    _darkThemeColorList[ElaThemeType::colorStatusWarningBorder2] = QColor(0xF9, 0x88, 0x45); // #f98845
    _lightThemeColorList[ElaThemeType::colorStatusWarningBorder2] = QColor(0xBC, 0x4B, 0x09); // #bc4b09

    // colorStatusDangerBackground1
    _darkThemeColorList[ElaThemeType::colorStatusDangerBackground1] = QColor(0x3B, 0x05, 0x09); // #3b0509
    _lightThemeColorList[ElaThemeType::colorStatusDangerBackground1] = QColor(0xFD, 0xF3, 0xF4); // #fdf3f4

    // colorStatusDangerBackground2
    _darkThemeColorList[ElaThemeType::colorStatusDangerBackground2] = QColor(0x6E, 0x08, 0x11); // #6e0811
    _lightThemeColorList[ElaThemeType::colorStatusDangerBackground2] = QColor(0xEE, 0xAC, 0xB2); // #eeacb2

    // colorStatusDangerBackground3
    _darkThemeColorList[ElaThemeType::colorStatusDangerBackground3] = QColor(0xC5, 0x0F, 0x1F); // #c50f1f
    _lightThemeColorList[ElaThemeType::colorStatusDangerBackground3] = QColor(0xC5, 0x0F, 0x1F); // #c50f1f

    // colorStatusDangerForeground1
    _darkThemeColorList[ElaThemeType::colorStatusDangerForeground1] = QColor(0xDC, 0x62, 0x6D); // #dc626d
    _lightThemeColorList[ElaThemeType::colorStatusDangerForeground1] = QColor(0xB1, 0x0E, 0x1C); // #b10e1c

    // colorStatusDangerForeground2
    _darkThemeColorList[ElaThemeType::colorStatusDangerForeground2] = QColor(0xEE, 0xAC, 0xB2); // #eeacb2
    _lightThemeColorList[ElaThemeType::colorStatusDangerForeground2] = QColor(0x6E, 0x08, 0x11); // #6e0811

    // colorStatusDangerForeground3
    _darkThemeColorList[ElaThemeType::colorStatusDangerForeground3] = QColor(0xEE, 0xAC, 0xB2); // #eeacb2
    _lightThemeColorList[ElaThemeType::colorStatusDangerForeground3] = QColor(0xC5, 0x0F, 0x1F); // #c50f1f

    // colorStatusDangerForegroundInverted
    _darkThemeColorList[ElaThemeType::colorStatusDangerForegroundInverted] = QColor(0xB1, 0x0E, 0x1C); // #b10e1c
    _lightThemeColorList[ElaThemeType::colorStatusDangerForegroundInverted] = QColor(0xDC, 0x62, 0x6D); // #dc626d

    // colorStatusDangerBorderActive
    _darkThemeColorList[ElaThemeType::colorStatusDangerBorderActive] = QColor(0xDC, 0x62, 0x6D); // #dc626d
    _lightThemeColorList[ElaThemeType::colorStatusDangerBorderActive] = QColor(0xC5, 0x0F, 0x1F); // #c50f1f

    // colorStatusDangerBorder1
    _darkThemeColorList[ElaThemeType::colorStatusDangerBorder1] = QColor(0xC5, 0x0F, 0x1F); // #c50f1f
    _lightThemeColorList[ElaThemeType::colorStatusDangerBorder1] = QColor(0xEE, 0xAC, 0xB2); // #eeacb2

    // colorStatusDangerBorder2
    _darkThemeColorList[ElaThemeType::colorStatusDangerBorder2] = QColor(0xDC, 0x62, 0x6D); // #dc626d
    _lightThemeColorList[ElaThemeType::colorStatusDangerBorder2] = QColor(0xC5, 0x0F, 0x1F); // #c50f1f

    // colorStatusDangerBackground3Hover
    _darkThemeColorList[ElaThemeType::colorStatusDangerBackground3Hover] = QColor(0xB1, 0x0E, 0x1C); // #b10e1c
    _lightThemeColorList[ElaThemeType::colorStatusDangerBackground3Hover] = QColor(0xB1, 0x0E, 0x1C); // #b10e1c

    // colorStatusDangerBackground3Pressed
    _darkThemeColorList[ElaThemeType::colorStatusDangerBackground3Pressed] = QColor(0x96, 0x0B, 0x18); // #960b18
    _lightThemeColorList[ElaThemeType::colorStatusDangerBackground3Pressed] = QColor(0x96, 0x0B, 0x18); // #960b18

    // Win10顶部边框颜色
    _lightThemeColorList[ElaThemeType::Win10BorderActive] = QColor(0x6E, 0x6E, 0x6E);
    _darkThemeColorList[ElaThemeType::Win10BorderActive] = QColor(0x33, 0x33, 0x33);
    _lightThemeColorList[ElaThemeType::Win10BorderInactive] = QColor(0xA7, 0xA7, 0xA7);
    _darkThemeColorList[ElaThemeType::Win10BorderInactive] = QColor(0x3D, 0x3D, 0x3D);
}
