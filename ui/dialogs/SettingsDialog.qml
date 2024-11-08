import QtQuick
import QtQuick.Controls.Material

import "../"

WDialog {
    id: _base
    title: qsTr("Settings")
    standardButtons: Dialog.Ok | Dialog.Cancel

    property bool dynamicallyCreated: false
}
