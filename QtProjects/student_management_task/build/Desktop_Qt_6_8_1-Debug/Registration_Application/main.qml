import QtQuick
import QtQuick.Controls
import QtQuick.Layouts


Window {
    id: mainWindow
    width: 640
    height: 480
    visible: true
    title: qsTr("Registraction Aplication")


    Loader {
        id: pageLoader
        height: mainWindow.height / 1
        width: mainWindow.width / 3
        anchors.centerIn: parent
        // source: "RegisterPage.qml"
        source: "LoginPage.qml"
    }
}


