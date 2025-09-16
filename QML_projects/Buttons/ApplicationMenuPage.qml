import QtQuick 2.15
import QtQuick.Layouts
import QtQuick.Controls

Rectangle {
    id: applicationMenuPage
    color: "lightgrey"

    signal productionButtonClicked()
    signal setUpButtonClicked()
    signal supportButtonClicked()
    signal toolsButtonClicked()
    signal favouriteButtonClicked()

    property var activeButton: null

    function handleClick(button) {
        if (activeButton && activeButton !== button) {
            activeButton.isPressed = false
        }
        button.isPressed = true
        activeButton = button
        console.log(button.text+ " Clicked")
    }

    ColumnLayout {
        id: menuPageColumnLayout
        anchors.fill: parent
        anchors.centerIn: parent.horizontalCenter
        spacing: 10

        MenuButton {
            id: productionButton
            text: "Production"
            Layout.fillWidth: true
            Layout.fillHeight: true
            onClicked: {
                handleClick(productionButton)
                productionButtonClicked()
            }
        }

        MenuButton {
            id: setUpButton
            text: "Setup"
            Layout.fillWidth: true
            Layout.fillHeight: true
            onClicked: {
                handleClick(setUpButton)
                setUpButtonClicked()
            }
        }

        MenuButton {
            id: supportButton
            text: "Support"
            Layout.fillWidth: true
            Layout.fillHeight: true
            onClicked: {
                handleClick(supportButton)
                supportButtonClicked()
            }
        }

        MenuButton {
            id: toolsButton
            text: "Tools"
            Layout.fillWidth: true
            Layout.fillHeight: true
            onClicked: {
                handleClick(toolsButton)
                toolsButtonClicked()
            }
        }

        MenuButton {
            id: favouriteButton
            text: "Favourite"
            Layout.fillWidth: true
            Layout.fillHeight: true
            onClicked: {
                handleClick(favouriteButton)
                favouriteButtonClicked()
            }
        }
    }
}
