import QtQuick
import QtQuick.Controls
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    Item {
        id: item1
        width: 100
        height:100
        visible: true
        x: 200
        y: 50
        Rectangle{
            id: rect1
            width: 100
            height: 100
            color: "red"
        }
    }
    Button{
        id: button1
        text: "submit"
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.margins: 20
    }
Rectangle{
    id: txtip
    width: 100
    height: 80
    anchors.top: button1.bottom
    anchors.left: parent.left
    anchors.margins: 20
    border.color: "black"
    TextInput{
        text: "good morning"
        anchors.fill: parent

    }
}
    Text{
        id: txt1
        text: "hello"
        anchors.top: txtip.bottom
        anchors.left: parent.left
        anchors.margins: 20
        font.bold: text

    }
    Rectangle{
        id: txtedit
        width: 100
        height: 80
        anchors.top: txt1.bottom
        anchors.left: parent.left
        anchors.margins: 20
        border.color: "black"
    TextEdit{
        text: "type here..."
        anchors.fill: parent
    }
    }
    Image {
        id: image1
        source: "data:image/jpeg;base64,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"
        width: 200
        height: 100
        anchors.top: txtedit.bottom
        anchors.left: parent.left
        anchors.margins: 20
        fillMode: Image.PreserveAspectFit

    }
    RadioButton{
        id: rbtn1
        anchors.top: image1.bottom
        anchors.left: parent.left
        anchors.margins: 20
    }

    Slider{
        id: sldr1
        anchors.top: rbtn1.bottom
        anchors.left: parent.left
        anchors.margins: 20
    }

    ProgressBar{
        id: pgbr1
        anchors.top: sldr1.bottom
        anchors.left: parent.left
        anchors.margins: 20
    }
}
