import QtQuick
// import QtQuick.Layouts
// import "./CustomCheckBox.qml"
import CustomCheckBox_example1 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    CustomCheckBox
    {
        id: box1
        anchors.centerIn: parent
    }
}
