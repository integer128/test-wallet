#include "qmlcontext.h"
#include "version.h"

QmlContext::QmlContext(QGuiApplication *parent)
    : application(parent)
{
    address_list_model = new AddressListModel(this);

    clipboard_model = new ClipboardModel(parent);

    connect(clipboard_model, &ClipboardModel::textChanged, this, &QmlContext::clipboardModelChanged);

    concatenate_tx_list = new TxListModel(this);
}

QString QmlContext::getTitle()
{
    return QString("%1 %2").arg(Product::NAME, Product::VERSION);
}

AddressListModel *QmlContext::addressList()
{
    return address_list_model;
}

ClipboardModel *QmlContext::clipboardModel()
{
    return clipboard_model;
}

TxListModel *QmlContext::concatenateTxList()
{
    return concatenate_tx_list;
}
