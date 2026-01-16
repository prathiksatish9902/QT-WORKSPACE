import QtQuick 2.12

Item
{
    id: root

    property alias text: label.text
    property bool checked: false
    property color circleColor: "white"
    property color borderColor: "Black"
    property color textColor: "Black"
    property color dotColor: "Black"
    property int textSize: 16
    property int circleSize: 20
    property string radioButtonText: ""

    implicitWidth: 160
    implicitHeight: 30

    Row
    {
        spacing: 8
        anchors.verticalCenter: parent.verticalCenter

        Rectangle
        {
            id: circle
            width: circleSize
            height: circleSize
            color: circleColor
            border.color: borderColor
            border.width: 2
            radius: width / 2

            Rectangle
            {
                id: dotMark
                width: parent.width * 0.5
                height: parent.height * 0.5
                anchors.centerIn: parent
                radius: width / 2
                color: dotColor
                visible: root.checked
            }
        }
        Text
        {
            id: label
            text: root.radioButtonText
            verticalAlignment: Text.AlignVCenter
            color: textColor
            font.pixelSize: textSize
        }
    }
    MouseArea
    {
        anchors.fill: parent
        onClicked:
        {
            root.checked = !root.checked
        }
    }
}
