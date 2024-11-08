import QtQuick
import QtQuick.Controls.Material
import QtQuick.Layouts

ItemDelegate {
    property var txModel

    contentItem: RowLayout {

        Image {
            sourceSize.width: 16
            sourceSize.height: 16
            source: modelObject.txType === 0 ? "qrc:/ui/images/arrowup.png"
                                             : "qrc:/ui/images/arrowdown.png"
        }

        ColumnLayout {

            Label {
                Layout.fillWidth: true
                elide: Label.ElideRight
                text: txModel.txId
            }

            RowLayout {
                Layout.fillWidth: true

                Label {
                    Layout.fillWidth: true
                    text: "Coins: %1".arg(modelObject.amount)
                }

                Label {
                    text: txModel.dt
                }
            }
        }
    }
}
