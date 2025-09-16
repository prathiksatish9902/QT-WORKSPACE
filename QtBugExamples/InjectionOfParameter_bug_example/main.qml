// main.qml
import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 400
    height: 300
    visible: true
    title: qsTr("Deprecated Wheel Event Example")

    Rectangle {
        anchors.fill: parent
        color: "lightblue"

        MouseArea {
            anchors.fill: parent

            onWheel: {
                if (wheel.modifiers & Qt.ControlModifier) {
                    console.log("Zoom:", wheel.angleDelta.y)
                }
            }
        }
    }
}
