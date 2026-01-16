import QtQuick 2.12
import QtQuick.Window 2.12
import "./Components"
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Holzher")

   HomePage
   {
        id: mainpage
        anchors.fill: parent
   }
}
