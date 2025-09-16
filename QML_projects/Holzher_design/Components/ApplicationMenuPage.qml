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
        property url iconSource

        signal clicked

        ColumnLayout {
            anchors.centerIn: parent
            spacing: 5

            Image {
                id: buttonImage
                source: iconSource
                fillMode: Image.PreserveAspectFit
                Layout.maximumWidth: parent.width * 0.7
                Layout.maximumHeight: parent.height * 0.6
                Layout.alignment: Qt.AlignHCenter
            }

            Text {
                id: buttonText
                color: "white"
                font.pixelSize: 16
                horizontalAlignment: Text.AlignHCenter
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter
            }
        }

        MouseArea {
            id: mouseArea
            anchors.fill: parent
            hoverEnabled: true
            onClicked: parent.clicked()
        }
    }

    ColumnLayout {
        id: menuPageColumnLayout
        anchors.fill: parent
        spacing: 10

        MenuButton {
            id: productionButton
            text: "Production"
            iconSource: "qrc:/Image/Production.png"
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
            iconSource: "qrc:/Image/SetUp.png"
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
            iconSource: "qrc:/Image/Support.png"
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
            iconSource: "qrc:/Image/Tools.png"
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
            iconSource: "qrc:/Image/Favourite.png"
            Layout.fillWidth: true
            Layout.fillHeight: true
            onClicked: {
                handleClick(favouriteButton)
                favouriteButtonClicked()
            }
        }
    }
}
