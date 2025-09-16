import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Item {
    id: root
    property alias iconSource: icon.source
    property alias label: labelItem.text
    property color backgroundColor: "#d97706"
    property real radius: 12
    property int iconWidth: 48
    property int iconHeight: 48
    property int tileWidth: 120
    property int tileHeight: 90
    property real hoverScale: 1.1
    property color textColor: "black"
    property int textSize: 16

    width: tileWidth
    height: tileHeight + textSize + 8

    ColumnLayout {
        anchors.fill: parent
        spacing: 6
        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

        Rectangle {
            id: iconContainer
            width: tileWidth
            height: tileHeight
            radius: root.radius
            color: root.backgroundColor
            transformOrigin: Item.Center

            Image {
                id: icon
                anchors.centerIn: parent
                width: root.iconWidth
                height: root.iconHeight
                fillMode: Image.PreserveAspectFit
                smooth: true
            }

            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onEntered: scaleUp.start()
                onExited: scaleDown.start()
            }

            NumberAnimation {
                id: scaleUp
                target: iconContainer
                property: "scale"
                to: root.hoverScale
                duration: 150
                easing.type: Easing.OutQuad
            }
            NumberAnimation {
                id: scaleDown
                target: iconContainer
                property: "scale"
                to: 1.0
                duration: 150
                easing.type: Easing.OutQuad
            }
        }

        Text {
            id: labelItem
            text: ""
            font.pixelSize: root.textSize
            color: root.textColor
            horizontalAlignment: Text.AlignHCenter
            Layout.alignment: Qt.AlignHCenter
        }
    }
}
