import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Rectangle {
    id: root
    color: "Black"
    signal showContact(int contactIndex)
    signal editContact(int contactIndex)
    anchors.fill: parent

    property bool showAddForm: false
    property string newName: ""
    property string newPhone: ""
    property string searchText: ""

    Column {
        anchors.fill: parent
        spacing: 10
        width: root.width

        Row {
            width: root.width

            spacing: 10
            TextField {
                id: searchField
                width: root.width * 0.8
                height: 50
                placeholderText: "Search contacts..."
                color: "Black"
                font.pixelSize: 20
                text: root.searchText
                onTextChanged: root.searchText = text

                background: Rectangle {
                    radius: 10
                    anchors.fill: parent
                    color: "white"
                }
            }
            Button {
                text: "Clear"
                width: 80
                height: 50
                visible: root.searchText.length > 0
                onClicked: {
                    root.searchText = ""
                    searchField.text = ""
                }

                background: Rectangle {
                    id:background
                    color: "royalBlue"
                    radius: 10
                }
            }
        }

        ListView {
            id: listView
            anchors.horizontalCenter: parent.horizontalCenter
            width: root.width
            height: root.height - addButton.height - 160
            model: contactModel
            spacing: 10


            delegate: ItemDelegate {
                width: root.width
                height: 60
                visible: root.searchText.length === 0 || name.toLowerCase().indexOf(root.searchText.toLowerCase()) !== -1
                contentItem: RowLayout {
                    spacing: 10
                    Rectangle {
                        Layout.preferredWidth: 40
                        Layout.preferredHeight: 40
                        radius: 20
                        color: "#6200EE"
                        Layout.alignment: Qt.AlignVCenter
                        Text {
                            anchors.centerIn: parent
                            text: name.charAt(0).toUpperCase()
                            color: "white"
                            font.pixelSize: 18
                            font.bold: true
                        }
                    }
                    Text {
                        text: name
                        font.pixelSize: 16
                        color: "white"
                        Layout.fillWidth: true
                        Layout.alignment: Qt.AlignVCenter
                        elide: Text.ElideRight
                    }
                    Button {
                        text: "View"
                        onClicked: root.showContact(index)
                    }
                    Button {
                        text: "Edit"
                        onClicked: root.editContact(index)
                    }
                    Button {
                        text: "Delete"
                        onClicked: {
                            confirmDialog.deleteIndex = index
                            confirmDialog.open()
                        }
                    }
                }
            }
        }

        Button {
            id: addButton
            text: showAddForm ? "Cancel" : "Add Contact"
            anchors.horizontalCenter: parent.horizontalCenter
            width: 100
            height: 40
            onClicked: showAddForm = !showAddForm

            background: Rectangle {
                anchors.fill: parent
                radius: 10
                color: "royalBlue"
            }
        }

        Column {
            visible: showAddForm
            spacing: 10
            anchors.horizontalCenter: parent.horizontalCenter
            width: root.width * 0.8

            TextField {
                id: newNameField
                placeholderText: "Name (alphanumeric only)"
                text: newName
                onTextChanged: newName = text
                width: parent.width
                height: 25
                color: "Black"
                validator: RegularExpressionValidator { regularExpression: /[a-zA-Z0-9]+/ }


                background: Rectangle {
                    anchors.fill: parent
                    radius: 10
                    color: "lightgrey"
                }
            }
            TextField {
                id: newPhoneField
                placeholderText: "Phone (e.g., 1234567890)"
                text: newPhone
                onTextChanged: newPhone = text
                width: parent.width
                height: 25
                color: "Black"
                validator: RegularExpressionValidator { regularExpression: /[0-9]{10}/ }


                background: Rectangle {
                    anchors.fill: parent
                    radius: 10
                    color: "lightgrey"
                }
            }
            Text {
                id: errorLabel
                color: "red"
                visible: text.length > 0
                width: parent.width
                wrapMode: Text.Wrap
            }
            Button {
                text: "Save"
                width: 100
                height: 40
                anchors.horizontalCenter: parent.horizontalCenter
                enabled: newNameField.acceptableInput && newPhoneField.acceptableInput
                onClicked: {
                    if (newName.length > 0 && newPhone.length > 0) {
                        contactModel.addContact(newName, newPhone)
                        newName = ""
                        newPhone = ""
                        showAddForm = false
                    } else {
                        errorLabel.text = "Please enter a valid alphanumeric name and 10-digit phone number."
                    }
                }

                background: Rectangle {
                    anchors.fill: parent
                    radius: 10
                    color: "royalblue"
                }
            }
        }
    }

    Dialog {
        id: confirmDialog
        title: "Delete Contact"
        standardButtons: Dialog.Yes | Dialog.No
        anchors.centerIn: parent
        Text { text: "Are you sure you want to delete this contact?" }
        property int deleteIndex: -1
        onAccepted: contactModel.deleteContact(deleteIndex)
    }
}
