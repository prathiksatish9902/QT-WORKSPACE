import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    Rectangle{
        id: rect1
        width: 100
        height: 100
        color: "red"
    }
    Rectangle{
        id: rect2
        width: 100
        height: 100
        color: "blue"
        anchors.top: rect1.bottom
        anchors.left: rect1.right
    }

    Rectangle{
        id: rect3
        width: 100
        height: 100
        color: "green"
        anchors.top: rect2.bottom
        anchors.left: rect2.right
    }

    Rectangle{
        id: rect4
        width: 100
        height: 100
        color: "green"
        anchors.top: rect3.bottom
        anchors.left: rect3.right
    }
}

