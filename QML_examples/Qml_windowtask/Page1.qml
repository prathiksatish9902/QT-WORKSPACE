import QtQuick
import QtQuick.Controls
    Rectangle{
        id: _page1
        width: 150
        height: 100
        color: "red"
        border.color: "black"
        anchors.centerIn: parent
        signal page1NextButton()
        signal page1PreviousButton()
        Button{
            id: _nextbutton
            width: 80
            height: 60
            text: "N"
            anchors.rightMargin: 5
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            onClicked:{
                page1NextButton()
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
        }


    }

