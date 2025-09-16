import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    Rectangle{
        id: _footer
        width: parent.width
        height: 50
        border.color: "black"
        color: "yellow"
        anchors.bottom: parent.bottom
        RowLayout{
            spacing: 40
            anchors.centerIn: parent
            anchors.fill: parent
            Button{
                id: _btn1
                text: "1"
                Layout.fillWidth: true
                Layout.fillHeight: true
                onClicked: {
                    _loader.source = "Page1.qml"
                }
            }
            Button{
                id: _btn2
                text: "2"
                Layout.fillWidth: true
                Layout.fillHeight: true
                onClicked: {
                    _loader.source = "Page2.qml"
                }
            }
            Button{
                id: _btn3
                text: "3"
                Layout.fillWidth: true
                Layout.fillHeight: true
                onClicked: {
                    _loader.source = "Page3.qml"
                }
            }
            Button{
                id: _btn4
                text: "4"
                Layout.fillWidth: true
                Layout.fillHeight: true
                onClicked: {
                    _loader.source = "Page4.qml"
                }
            }
            Button{
                id: _btn5
                text: "5"
                Layout.fillWidth: true
                Layout.fillHeight: true
                onClicked: {
                    _loader.source = "Page5.qml"
                }
            }
        }
    }
    Loader{
        id: _loader
        width: parent.width
        height: parent.height - _footer.height
        anchors.top: parent.top
    }
}
