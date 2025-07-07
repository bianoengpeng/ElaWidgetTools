#ifndef T_TABLEVIEWMODEL_H
#define T_TABLEVIEWMODEL_H

#include <QAbstractTableModel>
#include <QVector>
#include <QIcon>

class T_TableViewModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit T_TableViewModel(QObject* parent = nullptr);
    ~T_TableViewModel();
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // 复选框支持
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

private:
    QStringList _header;
    QList<QStringList> _dataList;
    QList<QIcon> _iconList;
    QVector<Qt::CheckState> _checkStates; // 存储复选框状态
};

#endif // T_TABLEVIEWMODEL_H
