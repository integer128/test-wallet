#pragma once

#include <QObject>
#include <QGuiApplication>

#include "addresslistmodel.h"
#include "clipboardmodel.h"


class QmlContext : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString title READ getTitle CONSTANT)
    Q_PROPERTY(AddressListModel* addressList READ addressList CONSTANT)
    Q_PROPERTY(ClipboardModel* clipboardModel READ clipboardModel NOTIFY clipboardModelChanged FINAL)
    Q_PROPERTY(TxListModel* concatenateTxList READ concatenateTxList CONSTANT)

public:
    QmlContext(QGuiApplication *parent = nullptr);

    QString getTitle();
    AddressListModel* addressList();

    ClipboardModel* clipboardModel();
    TxListModel* concatenateTxList();

signals:
    void clipboardModelChanged();

private:
    QGuiApplication *application{nullptr};
    AddressListModel *address_list_model{nullptr};
    ClipboardModel *clipboard_model{nullptr};
    TxListModel *concatenate_tx_list{nullptr};
};
