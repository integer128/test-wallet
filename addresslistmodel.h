#ifndef ADDRESSLISTMODEL_H
#define ADDRESSLISTMODEL_H

#include <QAbstractListModel>
#include <QList>

#include "address.h"


class AddressListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    AddressListModel(QObject *parent = nullptr);

    enum Roles {
        model = Qt::UserRole + 1
    };

    QList<Address*> getSource() const;

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;

    Q_INVOKABLE void generateNewAddress();

private:
    QList<Address*> address_list;
};

#endif // ADDRESSLISTMODEL_H
