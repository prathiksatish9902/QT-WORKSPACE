import QtQuick 2.15
import QtQuick.Controls 2.15

Button {
    id: button
    property color backgroundColor: "transparent"
    property color buttonBorderColor: "transparent"
    property real borderWidth: 1
    property real radius: 4
    property color pressedColor: "transparent"

    background: Rectangle{
        anchors.fill: parent
        color: button.down ? pressedColor : button.backgroundColor
        border.color: button.buttonBorderColor
        border.width: button.borderWidth
        radius: button.radius
    }
}
