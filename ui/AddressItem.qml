import QtQuick
import QtQuick.Controls.Material
import QtQuick.Layouts

ItemDelegate {
    id: _base

    property var addressObject
    property Menu contextMenu

    contentItem: RowLayout {

        Label {
            Layout.fillWidth: true
            text: addressObject.address
        }

        ToolButton {
           text: qsTr("⋮")
           onClicked: {
               _base.contextMenu.addressObject = addressObject
               contextMenu.popup()
           }
       }
    }

    MouseArea {
        anchors.fill: _base
        acceptedButtons: Qt.RightButton

        onClicked: (mouse) => {
            if (mouse.button === Qt.RightButton) {
                _base.contextMenu.addressObject = addressObject
                _base.contextMenu.popup()
            }
        }
        onPressAndHold: (mouse) => {
            if (mouse.source === Qt.MouseEventNotSynthesized) {
                _base.contextMenu.address = addressObject
                contextMenu.popup()
            }
        }
    }
}
