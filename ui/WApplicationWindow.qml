import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Material
import QtQuick.Layouts

ApplicationWindow {
    id: base
    width: 640
    height: 480
    visible: true
    title: context.title

    Material.theme: Material.Dark
    Material.accent: Material.Purple

    property int currentIndex: 0

    header: ToolBar {
        RowLayout {
            anchors.fill: parent

            Label {
                Layout.fillWidth: true
                text: qsTr("TEST WALLET")
                elide: Label.ElideRight
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
            }

            TabButton {
                text: qsTr("Addresses")
                checked: base.currentIndex === 0

                onClicked: {
                    base.currentIndex = 0
                }
            }
            TabButton {
                text: qsTr("Transactions")
                checked: base.currentIndex === 1

                onClicked: {
                    base.currentIndex = 1
                }
            }
            ToolButton {
                text: qsTr("⋮")

                onClicked: {
                    _headerMenu.popup()
                }
            }

            Menu {
                id: _headerMenu

                MenuItem {
                    text: qsTr("Settings")

                    onTriggered: {
                        let dialog = _applicationManager.createDialog(
                            "SettingsDialog", {
                            "height" : _applicationWindow.height / 2,
                            "width" : _applicationWindow.width / 2
                        })
                        dialog.open();
                    }
                }
            }
        }
    }

    StackLayout {
        anchors.fill: parent
        currentIndex: base.currentIndex

        AddressListPane {
            Layout.fillWidth: true
            Layout.fillHeight: true

            addressList: context.addressList

            contextMenu: Menu {
                id: _contextMenu
                property var addressObject // AddressModel

                MenuItem {
                    text: qsTr("Copy address")
                    onTriggered: {
                        context.clipboardModel.text = _contextMenu.addressObject.address
                    }
                }
                MenuItem {
                    text: qsTr("Transaction history")
                    onTriggered: {
                        let dialog = _applicationManager.createDialog(
                            "AddressTxDialog", {
                            "addressObject" : _contextMenu.addressObject,
                            "height" : _applicationWindow.height,
                            "width" : _applicationWindow.width / 2
                        })
                        dialog.open();
                    }
                }
            }
        }

        TxListPane {
            Layout.fillWidth: true
            Layout.fillHeight: true

            txList: context.concatenateTxList
        }
    }

    onSceneGraphError: (error, message) => {
        console.error("QML rendering error %1: %2".arg(error).arg(message))
    }
}
