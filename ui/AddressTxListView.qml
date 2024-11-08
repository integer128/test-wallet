import QtQuick
import QtQuick.Controls.Material
import QtQuick.Layouts

Control {
    id: _base
    property alias model: _listView.model

    contentItem: ListView {
        id: _listView

        delegate: TxItem {
            width: _listView.width
            txModel: modelObject
        }
    }
}
