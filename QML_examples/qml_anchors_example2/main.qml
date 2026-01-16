import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    Rectangle{
        id: rect1
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: 30
        height: parent.height * 0.4
        color:"red"
        radius: 10
        Rectangle{
            id: rect2
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.margins: 30
            width: parent.width * 0.4
            height: parent.height * 0.4
            color:"blue"
            radius: 4
        }
        Rectangle{
            id: rect3
            anchors.top: parent.top
            anchors.right: parent.right
            anchors.margins: 30
            width: parent.width * 0.4
            height: parent.height * 0.4
            color:"blue"
            radius: 4
        }
    }
    Rectangle{
        id: rect4
        anchors.top: rect2.bottom - 200
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        anchors.margins: 40
        width: parent.width * 0.4
        height: parent.height * 0.4
        color:"green"
        radius: 4
    }
    Rectangle{
        id: rect5
        anchors.top: rect3.bottom - 200
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.margins: 40
        width: parent.width * 0.4
        height: parent.height * 0.4
        color:"green"
        radius: 4

        Rectangle{
            id: rect6
            anchors.top: parent.top
            anchors.right: parent.right
            anchors.margins: 30
            width: parent.width * 0.3
            height: parent.height * 0.5
            color:"blue"
            radius: 4
        }
        Rectangle{
            id: rect7
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.margins: 30
            width: parent.width * 0.3
            height: parent.height * 0.5
            color:"blue"
            radius: 4
        }
    }
}
