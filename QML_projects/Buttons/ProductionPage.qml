import QtQuick 2.15
import QtQuick.Layouts
import QtQuick.Controls

Rectangle {
    id: productionPage
    color: "lightgrey"

    property var activeButton: null

    function handleClick(button) {
        if (activeButton && activeButton !== button) {
            activeButton.isPressed = false
        }
        button.isPressed = true
        activeButton = button
        console.log(button.text+ " Clicked")
    }

    GridLayout {
        id: rowLayoutProductionPage
        anchors.fill: parent
        // anchors.right: parent.right
        // anchors.rightMargin: 10
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

