import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts

Rectangle {
    id: menuButton
    property alias text: label.text
    property alias iconSource: icon.source
    property color normalColor: "#4D4D4D"
    property color pressedColor: "#A6A6A6"
    property int radiusValue: 10
    property bool isPressed: false
    signal clicked(MenuButton button)

    radius: radiusValue
    color: isPressed ? pressedColor : normalColor
    border.color: "#A6A6A6"

    Text {
        id: label
        color: isPressed ? normalColor : pressedColor
        font.bold: true
        anchors.centerIn: parent
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        onClicked: menuButton.clicked(menuButton)
    }
}
