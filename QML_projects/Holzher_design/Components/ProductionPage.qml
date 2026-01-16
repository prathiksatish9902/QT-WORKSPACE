import QtQuick 2.15
import QtQuick.Layouts
import QtQuick.Controls

Rectangle {
    id: productionPage
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
        id: rowLayoutProductionPage
        anchors.fill: parent
        anchors.left: parent.left
        anchors.leftMargin: 120
        columns: 3
        columnSpacing: 40
        rowSpacing: 40

        MenuButton {
            id: ncCutting
            text: "NC Cutting"
            Layout.preferredWidth: 300
            Layout.preferredHeight: 150
            onClicked: handleClick(ncCutting)
        }

        MenuButton {
            id: directCutting
            text: "Direct Cutting"
            Layout.preferredWidth: 300
            Layout.preferredHeight: 150
            onClicked: handleClick(directCutting)
        }

        MenuButton {
            id: easyCutting
            text: "Easy Cutting"
            Layout.preferredWidth: 300
            Layout.preferredHeight: 150
            onClicked: handleClick(easyCutting)
        }

        MenuButton {
            id: optiCutting
            text: "Opti Cutting"
            Layout.preferredWidth: 300
            Layout.preferredHeight: 150
            onClicked: handleClick(optiCutting)
        }

        MenuButton {
            id: jobManagement
            text: "Job Management"
            Layout.preferredWidth: 300
            Layout.preferredHeight: 150
            onClicked: handleClick(jobManagement)
        }
    }
}
