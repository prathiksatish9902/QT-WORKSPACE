import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Column{
        spacing: 10
        anchors.centerIn: parent

        CustomRadioButton{
            id: first
            radioButtonText: "first"
            dotColor: "red"
            onCheckedChanged: {
                second.checked = !checked
            }
        }

        CustomRadioButton{
            id: second
            radioButtonText: "second"
            onCheckedChanged: {
                first.checked = !checked
            }
        }
    }
}

