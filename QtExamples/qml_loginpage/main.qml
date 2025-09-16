import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    Rectangle{
        id: _mainRectangle
        width: 500
        height: 500
        border.color: "black"
        anchors.centerIn: parent
        Text{
            id: _welcometxt
            text: "welcome to login page"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 30
            font.bold: text
        }
        Rectangle{
            id: _username
            width: 300
            height: 30
            border.color: "black"
            anchors.top: parent.verticalCenter
            anchors.centerIn: parent
            TextInput{
                text: "username :"
                color: "black"
                anchors.left: parent.verticalCenter
                anchors.margins: 5
                anchors.fill: parent
            }
        }
        Rectangle{
            id: _password
            width: 300
            height: 30
            border.color: "black"
            anchors.top: _username.bottom
            anchors.left: _username.left
            anchors.margins: 5
            TextInput{
                text: "password :"
                color: "black"
                anchors.left: parent.verticalCenter
                anchors.margins: 5
                anchors.fill: parent
            }
        }
    }
}
