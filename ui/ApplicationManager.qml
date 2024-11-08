import QtQuick

QtObject {
    property var openedDialogs: ({})

    function createObject(parent, filePath, properties) {
        let component = Qt.createComponent(filePath)
        if (component.status === Component.Error) {
            console.error(component.errorString())
            return null
        }

        let object = component.createObject(parent, properties)
        object.Component.onDestruction.connect(function () {
            console.debug("~" + filePath)
        })
        return object
    }

    function createDialog(name, properties) {
        let dialog = createObject(
                _applicationWindow,
                "dialogs/" + name + ".qml",
                Object.assign({}, properties, { "dynamicallyCreated": true }))

        dialog.onOpened.connect(function () {
            let oldDialog = openedDialogs[name]
            openedDialogs[name] = dialog
            if (oldDialog !== undefined) {
                oldDialog.close()
            }
        })

        dialog.onClosed.connect(function () {
            try {
                if (openedDialogs[name] === dialog) {
                    delete openedDialogs[name]
                }
            } catch (e) {}
        })

        return dialog
    }

    function imagePath(path) {
        return Qt.resolvedUrl("images/" + path)
    }
}
