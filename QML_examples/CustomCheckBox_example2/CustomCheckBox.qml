import QtQuick 2.12

Rectangle
{
    id: root
    width: 160
    height: 30
    color: "transparent"

    property alias text: label.text
    property bool checked: false
    property color boxColor: "white"
    property color borderColor: "black"
    property real boxSize: 20
    property url tickMarkSource: "qrc:/Images/tickIcon.png"

    signal checkedChange(bool checked)

    Row
    {
        spacing: 8
        anchors.verticalCenter: parent.verticalCenter

        Rectangle
        {
            id: box
            width: boxSize
            height: boxSize
            color: boxColor
            border.color: borderColor
            border.width: 2
            radius: 4

            Image
            {
                id: tick
                width: parent.width * 0.7
                height: parent.height * 0.7
                anchors.centerIn: parent
                source: tickMarkSource
                visible: root.checked
                fillMode: Image.PreserveAspectFit
            }
        }

        Text {
            id: label
            text: "Label"
            verticalAlignment: Text.AlignVCenter
            color: "Black"
            font.pixelSize: 16
        }
    }

    MouseArea
    {
        anchors.fill: parent
        onClicked:
        {
            root.checked = !root.checked
            root.checkedChange(root.checked)
        }
    }
}
