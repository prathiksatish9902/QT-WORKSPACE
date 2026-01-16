import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Dialogs 6.2

ApplicationWindow {
    visible: true
    width: 400
    height: 300

    MenuBar {
        Menu {
            title: "File"
            MenuItem {
                text: "Open Font Dialog"
                onTriggered: fontDialog.open()
            }
        }
    }

    FontDialog {
        id: fontDialog
        title: "Choose a Font"
        options: FontDialog.MonospacedFonts
        onAccepted: {
            console.log("Selected font:", selectedFont.family, selectedFont.pointSize)
        }
        onRejected: {
            console.log("Dialog canceled")
        }
    }

    Text {
        anchors.centerIn: parent
        text: "Selected font: " + (fontDialog.selectedFont.family ? fontDialog.selectedFont.family : "None")
        font: fontDialog.selectedFont
    }
}
