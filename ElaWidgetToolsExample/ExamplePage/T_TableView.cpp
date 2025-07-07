#include "T_TableView.h"

#include <QHBoxLayout>
#include <QHeaderView>
#include <QVBoxLayout>

#include "ElaTableView.h"
#include "ElaText.h"
#include "T_TableViewModel.h"
T_TableView::T_TableView(QWidget* parent)
    : T_BasePage(parent)
{
    // 预览窗口标题
    setWindowTitle("ElaTableView");

    // 顶部元素
    createCustomWidget("表格视图被放置于此，可在此界面体验其效果并按需添加进项目中");

    //ElaTableView
    ElaText* tableText = new ElaText("ElaTableView", this);
    tableText->setTextPixelSize(18);
    _tableView = new ElaTableView(this);
    // ElaScrollBar* tableViewFloatScrollBar = new ElaScrollBar(_tableView->verticalScrollBar(), _tableView);
    // tableViewFloatScrollBar->setIsAnimation(true);
    QFont tableHeaderFont = _tableView->horizontalHeader()->font();
    tableHeaderFont.setPixelSize(16);
    _tableView->horizontalHeader()->setFont(tableHeaderFont);
    _tableView->setModel(new T_TableViewModel(this));
    _tableView->setAlternatingRowColors(true);
    _tableView->setIconSize(QSize(38, 38));
    // 显示行号
    _tableView->verticalHeader()->setHidden(false);
    _tableView->verticalHeader()->setFixedWidth(40);
    _tableView->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);
    _tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    _tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    _tableView->horizontalHeader()->setMinimumSectionSize(60);
    _tableView->verticalHeader()->setMinimumSectionSize(46);
    _tableView->setFixedHeight(450);
    connect(_tableView, &ElaTableView::tableViewShow, this, [=]() {
        _tableView->setColumnWidth(0, 40); // 选择
        _tableView->setColumnWidth(1, 60); // 预览
        _tableView->setColumnWidth(2, 205); // 歌名
        _tableView->setColumnWidth(3, 170); // 歌手
        _tableView->setColumnWidth(4, 150); // 专辑
        _tableView->setColumnWidth(5, 60); // 时长
    });
    QHBoxLayout* tableViewLayout = new QHBoxLayout();
    tableViewLayout->setContentsMargins(0, 0, 10, 0);
    tableViewLayout->addWidget(_tableView);

    QWidget* centralWidget = new QWidget(this);
    centralWidget->setWindowTitle("ElaView");
    QVBoxLayout* centerVLayout = new QVBoxLayout(centralWidget);
    centerVLayout->setContentsMargins(0, 0, 0, 0);
    centerVLayout->addWidget(tableText);
    centerVLayout->addSpacing(10);
    centerVLayout->addLayout(tableViewLayout);
    centerVLayout->addStretch();
    addCentralWidget(centralWidget, true, false, 0);
}

T_TableView::~T_TableView()
{
}
