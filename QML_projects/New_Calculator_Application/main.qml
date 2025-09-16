import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    width: 340
    height: 520
    visible: true
    title: qsTr("Model Calculator")

    Rectangle {
        anchors.fill: parent
    }

    Column {
        anchors.centerIn: parent
        spacing: 18

        Rectangle {
            width: 290
            height: 40
            color: "#15243b"
            radius: 8
            border.color: "#2a3e6e"
            border.width: 1
            Text {
                anchors.right: parent.right
                anchors.rightMargin: 14
                anchors.verticalCenter: parent.verticalCenter
                text: viewModel.expressionString
                color: "#7ddcff"
                font.pixelSize: 18
                horizontalAlignment: Text.AlignRight
                width: parent.width - 18
                elide: Text.ElideLeft
            }
        }

        Rectangle {
            width: 290
            height: 58
            color: "#0c1728"
            radius: 12
            border.color: "#2a3e6e"
            border.width: 1
            Text {
                anchors.right: parent.right
                anchors.rightMargin: 14
                anchors.verticalCenter: parent.verticalCenter
                text: viewModel.resultString
                color: "#fff"
                font.pixelSize: 36
                horizontalAlignment: Text.AlignRight
                width: parent.width - 18
                elide: Text.ElideLeft
            }
        }

        GridView {
            id: gridView
            width: 290
            height: 380
            cellWidth: 70
            cellHeight: 65
            anchors.horizontalCenter: parent.horizontalCenter
            model: viewModel
            delegate: Rectangle {
                width: 60;
                height: 60
                radius: 32
                color: pressed ? (isOperator ? "#3fc7ff" : "#2a5298")
                               : (isOperator ? "#0093e9" : "#243b55")
                border.color: isOperator ? "#7ddcff" : "#294a6d"
                border.width: 1.5
                property bool pressed: false
                property bool isOperator: model.isOperator
                MouseArea {
                    anchors.fill: parent
                    onPressed: parent.pressed = true
                    onReleased: {
                        parent.pressed = false
                        viewModel.keyPressed(index)
                    }
                    onCanceled: parent.pressed = false
                }
                Text {
                    anchors.centerIn: parent
                    text: model.label
                    color: isOperator ? "#fff" : "#7ddcff"
                    font.pixelSize: 26
                    font.bold: isOperator
                }
            }
        }
    }
}
