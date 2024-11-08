#include "tx.h"

Tx::Tx(QObject *parent, const QString &txId, int amount, TxType type)
    : QObject{parent}
    , tx_id(txId)
    , amount_(amount)
    , tx_type(type)
{
    dt = QDateTime::currentDateTime();
}

QString Tx::txId()
{
    return tx_id;
}

void Tx::setTxId(const QString &id)
{
    if (tx_id != id)
    {
        tx_id = id;
        emit txIdChanged();
    }
}

int Tx::amount()
{
    return amount_;
}

void Tx::setAmount(int value)
{
    if (value != amount_)
    {
        amount_ = value;

        emit amountChanged();
    }
}

Tx::TxType Tx::txType()
{
    return tx_type;
}

QString Tx::datetime()
{
    return dt.toString("M/d/yy h:mm");
}
