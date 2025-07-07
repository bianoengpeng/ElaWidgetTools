#include "T_TableViewModel.h"

#include <QIcon>
T_TableViewModel::T_TableViewModel(QObject* parent)
    : QAbstractTableModel{parent}
{
    _header << "预览"
            << "歌名"
            << "歌手"
            << "专辑"
            << "时长";
    QStringList data0;
    QStringList data1;
    QStringList data2;
    QStringList data3;
    QStringList data4;
    QStringList data5;
    QStringList data6;
    QStringList data7;
    QStringList data8;
    data0 << "夜航星(Night Voyager)"
          << "不才/三体宇宙"
          << "我的三体之章北海传"
          << "05:03";
    data1 << "玫瑰少年"
          << "五月天"
          << "玫瑰少年"
          << "03:55";
    data2 << "Collapsing World(Original Mix)"
          << "Lightscape"
          << "Collapsing World"
          << "03:10";
    data3 << "RAIN MAN (雨人)"
          << "AKIHIDE (佐藤彰秀)"
          << "RAIN STORY"
          << "05:37";
    data4 << "黑暗森林"
          << "雲翼星辰"
          << "黑暗森林"
          << "05:47";
    data5 << "轻(我的三体第四季主题曲)"
          << "刘雪茗"
          << "我的三体第四季"
          << "01:59";
    data6 << "STYX HELIX"
          << "MYTH & ROID"
          << "STYX HELIX"
          << "04:51";
    data7 << "LAST STARDUST"
          << "Aimer"
          << "DAWN"
          << "05:18";
    data8 << "Running In The Dark"
          << "MONKEY MAJIK/塞壬唱片"
          << "Running In The Dark"
          << "03:40";
    _dataList.append(data0);
    _dataList.append(data1);
    _dataList.append(data2);
    _dataList.append(data3);
    _dataList.append(data4);
    _dataList.append(data5);
    _dataList.append(data6);
    _dataList.append(data7);
    _dataList.append(data8);

    _iconList.append(QIcon(QPixmap(":/Resource/Image/Model/NaightNavigationStar.jpg").scaled(38, 38, Qt::KeepAspectRatio, Qt::SmoothTransformation)));
    _iconList.append(QIcon(QPixmap(":/Resource/Image/Model/MaVieEnRose.jpg").scaled(38, 38, Qt::KeepAspectRatio, Qt::SmoothTransformation)));
    _iconList.append(QIcon(QPixmap(":/Resource/Image/Model/CollapsingWorld.jpg").scaled(38, 38, Qt::KeepAspectRatio, Qt::SmoothTransformation)));
    _iconList.append(QIcon(QPixmap(":/Resource/Image/Model/RainMan.jpg").scaled(38, 38, Qt::KeepAspectRatio, Qt::SmoothTransformation)));
    _iconList.append(QIcon(QPixmap(":/Resource/Image/Model/DarkForest.jpg").scaled(38, 38, Qt::KeepAspectRatio, Qt::SmoothTransformation)));
    _iconList.append(QIcon(QPixmap(":/Resource/Image/Model/Light.jpg").scaled(38, 38, Qt::KeepAspectRatio, Qt::SmoothTransformation)));
    _iconList.append(QIcon(QPixmap(":/Resource/Image/Model/STYXHELIX.jpg").scaled(38, 38, Qt::KeepAspectRatio, Qt::SmoothTransformation)));
    _iconList.append(QIcon(QPixmap(":/Resource/Image/Model/LASTSTARDUST.jpg").scaled(38, 38, Qt::KeepAspectRatio, Qt::SmoothTransformation)));
    _iconList.append(QIcon(QPixmap(":/Resource/Image/Model/RunningInTheDark.jpg").scaled(38, 38, Qt::KeepAspectRatio, Qt::SmoothTransformation)));

    // 初始化复选框状态（100 行）
    _checkStates.fill(Qt::Unchecked, 100);
}

T_TableViewModel::~T_TableViewModel()
{
}

int T_TableViewModel::rowCount(const QModelIndex& parent) const
{
    return 100;
}

int T_TableViewModel::columnCount(const QModelIndex& parent) const
{
    return _header.count() + 1; // 额外增加一列用于复选框
}

QVariant T_TableViewModel::data(const QModelIndex& index, int role) const
{
    // 第 0 列：复选框
    if (index.column() == 0)
    {
        if (role == Qt::CheckStateRole)
        {
            return _checkStates[index.row()];
        }
        return QVariant();
    }

    // 第 1 列：预览图标
    if (index.column() == 1)
    {
        if (role == Qt::DecorationRole)
        {
            return _iconList[index.row() % 9];
        }
        else if (role == Qt::DecorationPropertyRole)
        {
            return Qt::AlignCenter;
        }
        return QVariant();
    }

    // 其它列显示文字数据
    if (role == Qt::DisplayRole)
    {
        return _dataList[index.row() % 9][index.column() - 2];
    }
    else if (role == Qt::TextAlignmentRole && index.column() == 5)
    {
        return Qt::AlignCenter;
    }

    return QVariant();
}

QVariant T_TableViewModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
    {
        if (section == 0)
            return "选择";
        return _header[section - 1];
    }
    return QAbstractTableModel::headerData(section, orientation, role);
}

// 复选框支持
Qt::ItemFlags T_TableViewModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags defaultFlags = QAbstractTableModel::flags(index);
    if (!index.isValid())
        return defaultFlags;

    if (index.column() == 0)
    {
        return defaultFlags | Qt::ItemIsUserCheckable;
    }

    return defaultFlags;
}

bool T_TableViewModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.column() == 0 && role == Qt::CheckStateRole)
    {
        _checkStates[index.row()] = static_cast<Qt::CheckState>(value.toInt());
        emit dataChanged(index, index, {Qt::CheckStateRole});
        return true;
    }

    return QAbstractTableModel::setData(index, value, role);
}
