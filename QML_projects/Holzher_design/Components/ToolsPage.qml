import QtQuick 2.15
import QtQuick.Layouts
import QtQuick.Controls

Rectangle {
    id: toolsPage
    color: "white"

    property var activeButton: null

    function handleClick(button) {
        if (activeButton && activeButton !== button) {
            activeButton.isPressed = false
        }
        button.isPressed = true
        activeButton = button
        console.log(button.text + " Clicked")
    }

    component MenuButton: Rectangle {
        id: button
        color: isPressed ? "#555555" : "#333333"
        border.color: "#ffffff"
        border.width: 2
        radius: 10

        property bool isPressed: false
        property alias text: buttonText.text

        signal clicked

        Text {
            id: buttonText
            anchors.centerIn: parent
            color: "white"
            font.pixelSize: 20
        }

        MouseArea {
            id: mouseArea
            anchors.fill: parent
            hoverEnabled: true
            onClicked: parent.clicked()
            onEntered: {
                scaleAnimation.start()
            }
            onExited: {
                scaleAnimation.stop()
                button.scale = 1.0
            }
        }

        PropertyAnimation {
            id: scaleAnimation
            target: button
            property: "scale"
            to: 1.1
            duration: 200
            easing.type: Easing.InOutQuad
        }
    }

    GridLayout {
        id: rowLayouttoolsPage
        anchors.fill: parent
        anchors.left: parent.left
        anchors.leftMargin: 120
        columns: 2
        columnSpacing: 40
        rowSpacing: 40

        MenuButton {
            id: calculator
            text: "Calculator"
            Layout.preferredWidth: 300
            Layout.preferredHeight: 150
            onClicked: handleClick(calculator)
        }

        MenuButton {
            id: editor
            text: "Editor"
            Layout.preferredWidth: 300
            Layout.preferredHeight: 150
            onClicked: handleClick(editor)
        }

        MenuButton {
            id: manual
            text: "Manual"
            Layout.preferredWidth: 300
            Layout.preferredHeight: 150
            onClicked: handleClick(manual)
        }

        MenuButton {
            id: circuitDiagram
            text: "Circuit Diagram"
            Layout.preferredWidth: 300
            Layout.preferredHeight: 150
            onClicked: handleClick(circuitDiagram)
        }
    }
}

