#ifndef CLIPLISTMODEL_H
#define CLIPLISTMODEL_H

#include <QAbstractTableModel>

class ClipListModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    ClipListModel(QObject *parent  = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
};

#endif // CLIPLISTMODEL_H
