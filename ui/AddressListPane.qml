import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material

Pane {
    id: _base

    property var addressList //AddressListModel
    property Menu contextMenu

    ScrollView {
        anchors.fill: parent

        ListView {
            id: _listView
            model: _base.addressList

            header: RowLayout {
                width: parent.width

                Label {
                    Layout.alignment: Qt.AlignLeft
                    text: qsTr("Wallet Addresses")
                }

                RoundButton {
                    Layout.alignment: Qt.AlignRight
                    text: qsTr("Create Address")

                    onClicked: {
                        _base.addressList.generateNewAddress()
                    }
                }
            }

            delegate: AddressItem {
                id: _addressItem
                width: _listView.width
                addressObject: modelObject
                contextMenu: _base.contextMenu
                required property var modelObject
            }
        }
    }
}
