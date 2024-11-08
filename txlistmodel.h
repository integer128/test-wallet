#ifndef TXLISTMODEL_H
#define TXLISTMODEL_H

#include <QAbstractListModel>
#include <QList>

#include "tx.h"


class TxListModel : public QAbstractListModel
{
public:
    TxListModel(QObject *parent = nullptr);

    enum Roles {
        model = Qt::UserRole + 1
    };

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;

private:
    QList<Tx*> tx_list;
};

#endif // TXLISTMODEL_H
