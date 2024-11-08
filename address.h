#ifndef ADDRESS_H
#define ADDRESS_H

#include <QObject>
#include <QList>

#include "txlistmodel.h"


class Address : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString address READ getAddress WRITE setAddress NOTIFY addressChanged FINAL)
    Q_PROPERTY(TxListModel* addressTxListModel READ addressTxListModel NOTIFY addressTxListModelChanged FINAL)

public:
    explicit Address(QObject *parent, const QString& address);

    QString getAddress();
    void setAddress(const QString &new_address);

    TxListModel* addressTxListModel();

signals:
    void addressChanged();
    void addressTxListModelChanged();

private:
    QString address;
    TxListModel* tx_list_model{nullptr};
};
Q_DECLARE_METATYPE(Address);

#endif // ADDRESS_H
