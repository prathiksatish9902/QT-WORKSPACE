import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
    id: root
    property int contactIndex: -1
    property bool editMode: false
    signal backToList()
    anchors.fill: parent
    color: "Black"

    property string editedName: ""
    property string editedPhone: ""

    Component.onCompleted: {
        if (contactIndex >= 0) {
            var contact = contactModel.get(contactIndex)
            editedName = contact.name
            editedPhone = contact.phone
        }
    }

    Column {
        anchors.centerIn: parent
        spacing: 20
        width: parent.width * 0.8


        TextField {
            id: nameField
            visible: root.editMode
            text: editedName
            placeholderText: "Name"
            onTextChanged: editedName = text
            width: parent.width
            font.bold: true
            validator: RegularExpressionValidator { regularExpression: /.+/ }
            height: 50


            background: Rectangle {
                anchors.fill: parent
                radius: 10
                color: "royalblue"
            }
        }
        TextField {
            id: phoneField
            visible: root.editMode
            text: editedPhone
            placeholderText: "Phone (e.g., 1234567890)"
            onTextChanged: editedPhone = text
            width: parent.width
            font.bold: true
            validator: RegularExpressionValidator { regularExpression: /[0-9]{10}/ }
            height: 50


            background: Rectangle {
                anchors.fill: parent
                radius: 10
                color: "royalblue"
            }
        }

        TextField {
            visible: !root.editMode
            text: "Name: " + editedName
            font.pixelSize: 16
            width: parent.width
            wrapMode: Text.Wrap
            color: "white"
            height: 50
            font.bold: true

            background: Rectangle {
                anchors.fill: parent
                radius: 10
                color: "royalblue"
            }

        }
        TextField {
            visible: !root.editMode
            text: "Phone: " + editedPhone
            font.pixelSize: 16
            width: parent.width
            wrapMode: Text.Wrap
            color: "white"
            font.bold: true
            height: 50

            background: Rectangle {
                anchors.fill: parent
                radius: 10
                color: "royalblue"
            }

        }

        Row {
            spacing: 10
            anchors.horizontalCenter: parent.horizontalCenter

            Button {
                text: "Back"
                width: 100
                height: 50
                onClicked: root.backToList()

                background: Rectangle {
                    anchors.fill: parent
                    radius: 10
                    color: "royalBlue"
                }

            }
            Button {
                visible: root.editMode
                text: "Save"
                width: 100
                height: 50
                enabled: nameField.acceptableInput && phoneField.acceptableInput
                onClicked: {
                    if (editedName.length > 0 && editedPhone.length > 0) {
                        contactModel.editContact(contactIndex, editedName, editedPhone)
                        root.backToList()
                    } else {
                        errorLabel.text = "Please enter a valid name and phone number."
                    }
                }

                background: Rectangle {
                    anchors.fill: parent
                    radius: 10
                    color: "royalblue"
                }
            }
        }

        Text {
            id: errorLabel
            color: "red"
            visible: text.length > 0
            width: parent.width
            wrapMode: Text.Wrap
        }
    }
}
