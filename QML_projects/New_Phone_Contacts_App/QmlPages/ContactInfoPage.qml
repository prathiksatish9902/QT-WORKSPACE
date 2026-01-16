import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
Rectangle
{
    id: borderRectangle
    anchors.fill: parent
    border.color: "black"
    border.width: 2

    signal backButtonClicked()
    signal deleteButtonClicked()

    property string name: ""
    property string phoneNumber: ""

    Popup {
        id: editPopup
        modal: true
        x: (parent.width - width) / 2
        y: (parent.height - height) / 2
        width: 300
        height: 200
        focus: true

        property string editedName: name
        property string editedPhone: phoneNumber

        Column {
            anchors.centerIn: parent
            spacing: 20

            TextField {
                id: nameField
                placeholderText: "Name"
                text: editPopup.editedName
                onTextChanged: editPopup.editedName = text
                validator: RegularExpressionValidator { regularExpression: /[a-zA-Z0-9]+/ }

            }

            TextField {
                id: phoneField
                placeholderText: "Phone"
                text: editPopup.editedPhone
                onTextChanged: editPopup.editedPhone = text
                validator: RegularExpressionValidator { regularExpression: /[0-9]{10}/ }

            }

            Row {
                spacing: 20
                Button {
                    text: "Save"
                    onClicked: {
                        contactModel.updateContactByPhone(phoneNumber, editPopup.editedName, editPopup.editedPhone)
                        name = editPopup.editedName
                        phoneNumber = editPopup.editedPhone
                        editPopup.close()
                    }
                }
                Button {
                    text: "Cancel"
                    onClicked: editPopup.close()
                }
            }
        }
    }

    RowLayout
    {
        id: headingRow
        spacing: 40
        anchors.top: parent.top
        anchors.topMargin: 20
        anchors.left: parent.left
        anchors.leftMargin: 20

        Rectangle {
            id: backButton
            width: 60
            height: 60
            radius: 30
            color: "lightgrey"
            Layout.alignment: Qt.AlignHCenter

            Image {
                anchors.centerIn: parent
                source: "qrc:/Images/BackButtonIcon.png"
                width: 36
                height: 36
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    backButtonClicked()
                }
            }
        }
        Text {
            id: pageHeading
            text: qsTr("Contact")
            font.pixelSize: 32
            font.bold: true
        }

        Rectangle {
            id: optionButton
            width: 60
            height: 60
            radius: 30
            color: "lightgrey"
            Layout.alignment: Qt.AlignHCenter

            Image {
                anchors.centerIn: parent
                source: "qrc:/Images/OptionButtonIcon.png"
                width: 36
                height: 36
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log("optionbutton clicked")
                    optionMenu.open()
                }
            }
        }
        Popup {
            id: optionMenu
            x: optionButton.x
            y: optionButton.y + optionButton.height + 5
            width: 100
            modal: false
            focus: true

            background: Rectangle {
                color: "white"
                border.color: "transparent"
                radius: 8
            }

            ColumnLayout {
                anchors.fill: parent
                spacing: 5

                Button {
                    text: "Edit"
                    onClicked: {
                        editPopup.editedName = name
                        editPopup.editedPhone = phoneNumber
                        editPopup.open()
                        optionMenu.close()
                    }
                }
                Button {
                    text: "Delete"
                    onClicked: {
                        contactModel.deleteContactByPhone(phoneNumber)
                        deleteButtonClicked()
                        optionMenu.close()
                    }
                }
            }
        }
    }
    Column {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        spacing: 15

        Rectangle {
            id: profilePic
            width: 120
            height: 120
            radius: 60
            color: "#cccccc"
            anchors.horizontalCenter: parent.horizontalCenter


            Image {
                anchors.fill: parent
                anchors.margins: 5
                fillMode: Image.PreserveAspectFit
                source: "qrc:/Images/ProfilePicIcon.png"
            }
        }

        Text {
            id: contactName
            text: name
            font.pixelSize: 28
            font.bold: true
            horizontalAlignment: Text.AlignHCenter

        }

        Text {
            id: number
            text: phoneNumber
            color: "grey"
            horizontalAlignment: Text.AlignHCenter
        }
    }
}




