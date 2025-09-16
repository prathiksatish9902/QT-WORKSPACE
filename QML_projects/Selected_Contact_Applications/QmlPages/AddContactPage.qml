import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
Rectangle
{
    id: borderRectangle
    anchors.fill: parent
    border.color: "black"
    border.width: 2
    objectName: "AddContactPage"

    signal cancelButtonClicked()
    signal saveButtonClicked()

    RowLayout
    {
        id: headingRow
        spacing: 150
        anchors.top: parent.top
        anchors.topMargin: 20
        anchors.left: parent.left
        anchors.leftMargin: 20

        Button {
            text: "Cancel"
            onClicked: {
                cancelButtonClicked()
            }
        }

        Button {
            text: "Save"
            onClicked: {
                PhoneBookModel.addContact(contactName.text, phoneNumber.text, profileImage.text)
                saveButtonClicked()
            }
        }
    }
    Column {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        spacing: 15
        width: profilePic.width * 2

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
                source: profileImage.text
                visible: profileImage.text !== ""
            }
            Text {
                anchors.centerIn: parent
                text: contactName.text.charAt(0).toUpperCase()
                font.pixelSize: 48
                font.bold: true
                color: "white"
                visible: profileImage.text === ""
            }
        }

        TextField {
            id: contactName
            width: parent.width
            height: 40
            placeholderText: "Enter Contact Name"
            font.pixelSize: 16
            horizontalAlignment: Text.AlignHCenter
            validator: RegularExpressionValidator { regularExpression: /[a-zA-Z0-9]+/ }
        }

        TextField {
            id: phoneNumber
            width: parent.width
            height: 40
            placeholderText: "Enter Contact Number"
            font.pixelSize: 16
            color: "grey"
            horizontalAlignment: Text.AlignHCenter
            validator: RegularExpressionValidator { regularExpression: /[0-9]{10}/ }
        }

        TextField {
            id: profileImage
            width: parent.width
            height: 40
            placeholderText: "Enter Profile Image URL (optional)"
            font.pixelSize: 16
            color: "grey"
            horizontalAlignment: Text.AlignHCenter
        }
    }
}
