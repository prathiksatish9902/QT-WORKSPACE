import QtQuick 2.15

Rectangle {
    id: root
    width: 120
    height: 40
    radius: 8
    color: backgroundColor
    border.color: borderColor
    border.width: 1

    property alias text: label.text
    property color backgroundColor: "#2196F3"
    property color pressedColor: "#1976D2"
    property color textColor: "white"
    property color borderColor: "transparent"
    property int fontSize: 16
    property bool fontBold: false

    signal clicked()
    signal doubleClicked()
    signal pressAndHold()

    Text {
        id: label
        anchors.centerIn: parent
        color: root.textColor
        font.pixelSize: root.fontSize
        font.bold: root.fontBold
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        onPressed: root.color = pressedColor
        onReleased: root.color = backgroundColor
        onClicked: root.clicked()
        onDoubleClicked: root.doubleClicked()
        onPressAndHold: root.pressAndHold()
    }
}
