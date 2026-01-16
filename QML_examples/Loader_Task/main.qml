import QtQuick 2.12
import QtQuick.Window 2.12
Window {
     width: 640
     height: 480
     visible: true
     title: qsTr("Hello World")
     Loader
     {
          id: pageLoader
          anchors.fill: parent
          source: "qrc:/Page1.qml"
          Component.onCompleted: {
               console.log("loader called")
          }
     }

     Connections
     {
          target: pageLoader.item

          function onPage1ButtonClicked()
          {
               pageLoader.source = "qrc:/Page2.qml"
               console.log("signal handler called")
          }
     }

}
