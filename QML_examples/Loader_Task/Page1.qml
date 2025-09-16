import QtQuick 2.12
import QtQuick.Controls

Rectangle
{
    signal page1ButtonClicked()
     id: mainRect
     width: 300
     height: 300
     color: "red"
     anchors.centerIn: parent
     border.color: "black"
     border.width: 3

     Button{
          id: btn
          width: 80
          height: 50
          text: "page2"
          anchors.centerIn: parent
          onClicked:{
               page1ButtonClicked()
          }
     }
}
