import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
import Calculator 1.0

Window {
    width: 320
    height: 480
    visible: true
    title: qsTr("Calculator")

    Calculator {
        id: calculator
        onDisplayChanged: display.text = calculator.display
    }

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 10
        spacing: 10

        TextField {
            id: display
            Layout.fillWidth: true
            text: calculator.display
            font.pixelSize: 30
            horizontalAlignment: Text.AlignRight
            readOnly: true
        }

        GridLayout {
            columns: 4
            rowSpacing: 10
            columnSpacing: 10
            Layout.fillWidth: true
            Layout.fillHeight: true

            Button {
                text: "C"
                onClicked: calculator.clear()
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.columnSpan: 4
            }

            Button {
                text: "7"
                onClicked: calculator.append("7")
                Layout.fillWidth: true
                Layout.fillHeight: true
            }
            Button {
                text: "8"
                onClicked: calculator.append("8")
                Layout.fillWidth: true
                Layout.fillHeight: true
            }
            Button {
                text: "9"
                onClicked: calculator.append("9")
                Layout.fillWidth: true
                Layout.fillHeight: true
            }
            Button {
                text: "/"
                onClicked: calculator.append("/")
                Layout.fillWidth: true
                Layout.fillHeight: true
            }
            Button {
                text: "4"
                onClicked: calculator.append("4")
                Layout.fillWidth: true
                Layout.fillHeight: true
            }
            Button {
                text: "5"
                onClicked: calculator.append("5")
                Layout.fillWidth: true
                Layout.fillHeight: true
            }
            Button {
                text: "6"
                onClicked: calculator.append("6")
                Layout.fillWidth: true
                Layout.fillHeight: true
            }
            Button {
                text: "*"
                onClicked: calculator.append("*")
                Layout.fillWidth: true
                Layout.fillHeight: true
            }
            Button {
                text: "1"
                onClicked: calculator.append("1")
                Layout.fillWidth: true
                Layout.fillHeight: true
            }
            Button {
                text: "2"
                onClicked: calculator.append("2")
                Layout.fillWidth: true
                Layout.fillHeight: true
            }
            Button {
                text: "3"
                onClicked: calculator.append("3")
                Layout.fillWidth: true
                Layout.fillHeight: true
            }
            Button {
                text: "-"
                onClicked: calculator.append("-")
                Layout.fillWidth: true
                Layout.fillHeight: true
            }
            Button {
                text: "0"
                onClicked: calculator.append("0")
                Layout.fillWidth: true
                Layout.fillHeight: true
            }
            Button {
                text: "."
                onClicked: calculator.append(".")
                Layout.fillWidth: true
                Layout.fillHeight: true
            }
            Button {
                text: "="
                onClicked: calculator.evaluate()
                Layout.fillWidth: true
                Layout.fillHeight: true
            }
            Button {
                text: "+"
                onClicked: calculator.append("+")
                Layout.fillWidth: true
                Layout.fillHeight: true
            }
        }
    }
}
