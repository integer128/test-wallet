import QtQuick
import QtQuick.Controls.Material

import "../"

WDialog {
    id: _base

    title: qsTr("Transaction List")

    property bool dynamicallyCreated: false
    property var context: null
    property var addressObject


    contentItem: AddressTxListView {
        model: addressObject.addressTxListModel
    }
}
