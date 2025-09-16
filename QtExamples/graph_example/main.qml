import QtQuick 2.12
import QtQuick.Window 2.12
import CustomComponents 1.0
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    MyPaintedItem
    {
        id: _myItem
        anchors.fill: parent
    }
}
