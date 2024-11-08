import QtQuick.Controls.Material

Dialog {
    id: _base
    x: Math.round((parent.width - width) / 2)
    y: Math.round((parent.height - height) / 2)
    parent: Overlay.overlay
    modal: true
    dim: true
    standardButtons: Dialog.Cancel
}
