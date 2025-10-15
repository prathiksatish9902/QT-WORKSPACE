import QtQuick

Rectangle
{
    id: root
    width: 24
    height: 24
    radius: 4
    border.color: checked ? "#00c853" : "#aaa"
    border.width: 2
    color: checked ? "#00c853" : "transparent"

    property bool checked: false
    signal toggled(bool checked)

    MouseArea
    {
        anchors.fill: parent
        onClicked:
        {
            root.checked = !checked
            root.toggled(root.checked)
        }
    }

    Image
    {
        id: tickIcon
        anchors.centerIn: parent
        source: "qrc:/Images/tickIcon.png"
        visible: root.checked
        width: parent.width * 0.6
        height: parent.height * 0.6
        fillMode: Image.PreserveAspectFit
    }
}
