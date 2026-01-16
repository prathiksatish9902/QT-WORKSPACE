import QtQuick
import QtQuick.Controls

    Rectangle{
        id: _page3
        width: 150
        height: 100
        color: "green"
        border.color: "black"
        anchors.centerIn: parent
        signal page3NextButton()
        signal page3PreviousButton()
        Button{
            id: _nextbutton
            width: 80
            height: 60
            text: "N"
            anchors.rightMargin: 5
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            onClicked:{
                page3NextButton()
            }
        }
        Button{
            id: _previousbutton
            width: 80
            height: 60
            text: "P"
            anchors.leftMargin: 5
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            onClicked:{
                page3PreviousButton()
            }
        }
    }

