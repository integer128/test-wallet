#include "addresslistmodel.h"

#include <QUuid>

AddressListModel::AddressListModel(QObject *parent)
    : QAbstractListModel(parent)
{
    // Generate data for AddressListModel
    for (int i = 0; i < 25; ++i)
    {
        address_list.push_back(new Address(
            this,
            QUuid::createUuid().toString(QUuid::StringFormat::WithoutBraces))
        );
    }
}

QList<Address *> AddressListModel::getSource() const
{
    return address_list;
}

int AddressListModel::rowCount(const QModelIndex &parent) const
{
    return address_list.length();
}

QVariant AddressListModel::data(const QModelIndex &index, int role) const
{
    if (0 <= index.row() < address_list.length() && index.isValid())
        if (role == Roles::model)
            return QVariant::fromValue<Address*>(address_list.at(index.row()));

    return {};
}

QHash<int, QByteArray> AddressListModel::roleNames() const
{
    return {{Roles::model, "modelObject"}};
}

void AddressListModel::generateNewAddress()
{
    beginInsertRows(QModelIndex{}, address_list.length(), address_list.length());

    address_list.push_back(new Address(
        this,
        QUuid::createUuid().toString(QUuid::StringFormat::WithoutBraces))
    );

    endInsertRows();
}
