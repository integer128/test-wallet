#include "address.h"

Address::Address(QObject *parent, const QString &address)
    : QObject(parent)
    , address(address)
{
    tx_list_model = new TxListModel(this);
}

QString Address::getAddress()
{
    return address;
}

void Address::setAddress(const QString &new_address)
{
    if (address != new_address)
    {
        address = new_address;
        emit addressChanged();
    }
}

TxListModel *Address::addressTxListModel()
{
    return tx_list_model;
}
