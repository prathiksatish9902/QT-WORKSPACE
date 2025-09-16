import QtQuick 2.12
import QtQuick.Window 2.12
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    CustomButton {
            id: btn1
            // width: 200
            // height:140
            border.width: 3
            anchors.centerIn: parent
            text: "Click Me"
            textColor: "black"
            fontBold: true
            backgroundColor: "lightblue"
            pressedColor: "blue"
            onClicked: console.log("Custom Button clicked!")
            onDoubleClicked: console.log("clicked twice")
            onPressAndHold: console.log("pressAndHold")
        }

}
