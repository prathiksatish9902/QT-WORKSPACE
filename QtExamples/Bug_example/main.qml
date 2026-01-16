import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Dialogs 6.9

ApplicationWindow {
    visible: true
    width: 400
    height: 300
    title: "Test MessageDialog"

    Button {
        text: "Open Message Dialog"
        anchors.centerIn: parent
        onClicked: {
            messageDialog.open()
        }
    }

    MessageDialog {
        id: messageDialog
        title: "Test Dialog"
        text: "This is a test message dialog."
        onAccepted: {
            console.log("Dialog accepted")
        }
        onRejected: {
            console.log("Dialog rejected")
        }
    }
}
