import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material

Pane {
    id: _base

    property var txList //ConcatenateTxListModel

    ScrollView {
        anchors.fill: parent

        ListView {
            id: _listView
            model: _base.txList

            header: RowLayout {
                width: parent.width

                Label {
                    Layout.alignment: Qt.AlignHCenter
                    text: qsTr("Transactions")
                }
            }

            delegate: TxItem {
                width: _listView.width
                txModel: modelObject
            }
        }
    }
}
