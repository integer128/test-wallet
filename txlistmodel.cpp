#include "txlistmodel.h"

#include <QUuid>
#include <QRandomGenerator>

TxListModel::TxListModel(QObject *parent)
    : QAbstractListModel(parent)
{
    // Generate data for TxListModel
    for (int i = 0; i < 25; ++i)
    {
        tx_list.push_back(new Tx(
            this,
            QUuid::createUuid().toString(QUuid::StringFormat::WithoutBraces),
            QRandomGenerator::global()->bounded(0, 10),
            i % 2 == 0 ? Tx::TxType::Receive : Tx::TxType::Send)
        );
    }
}

int TxListModel::rowCount(const QModelIndex &parent) const
{
    return tx_list.length();
}

QVariant TxListModel::data(const QModelIndex &index, int role) const
{
    if (0 <= index.row() < tx_list.length() && index.isValid())
        if (role == Roles::model)
            return QVariant::fromValue<Tx*>(tx_list.at(index.row()));

    return {};
}

QHash<int, QByteArray> TxListModel::roleNames() const
{
    return {{Roles::model, "modelObject"}};
}
