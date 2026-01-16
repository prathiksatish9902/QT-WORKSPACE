import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
Rectangle
{
    id: borderRectangle
    anchors.fill: parent
    border.color: "black"
    border.width: 2

    signal addButtonClicked()
    signal contactClicked()
    signal dataSendClicked(string name, string phoneNumber)

    ColumnLayout
    {
        id: headingColoumn
        spacing: 15
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 20
        Text
        {
            id: mainHeading
            text: qsTr("My Contacts")
            font.pixelSize: 32
            font.bold: true
        }

        Item
        {
            width: borderRectangle.width - 20
            height: 60

            Rectangle
            {
                anchors.fill: parent
                radius: 20
                color: "white"
                border.color: "black"
            }

            Image
            {
                id: searchIcon
                source: "qrc:/Images/SearchIcon.png"
                width: 28
                height: 28
                anchors.left: parent.left
                anchors.leftMargin: 10
                anchors.verticalCenter: parent.verticalCenter

            }

            TextField
            {
                id: searchBar
                anchors.fill: parent
                anchors.leftMargin: 45
                font.pixelSize: 20
                placeholderText: "Search by name or number"
                background: null
                text: borderRectangle.searchText
                onTextChanged: borderRectangle.searchText = text
            }
        }
        ListView
        {
            id: contactList
            width: borderRectangle.width - 20
            height: borderRectangle.height - headingColoumn.height - 40
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.topMargin: 20
            model: contactModel
            spacing: 10

            delegate: Rectangle
            {
                width: contactList.width
                height: 60
                color: "royalblue"
                border.color: "black"
                radius: 15
                anchors.margins: 5

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        console.log("hi" + name + phoneNumber)
                        dataSendClicked(name,phoneNumber)
                    }
                }

                Row {
                    anchors.fill: parent
                    anchors.margins: 10
                    spacing: 15

                    Rectangle {
                        width: 50
                        height: 50
                        radius: width / 2
                        clip: true
                        color: "lightgray"
                        Image {
                            id: profilePic
                            anchors.fill: parent
                            source: "qrc:/Images/ProfilePicIcon.png"
                            fillMode: Image.PreserveAspectCrop
                            smooth: true
                        }
                    }

                    Column {
                        anchors.verticalCenter: parent.verticalCenter
                        spacing: 4

                        Text {
                            text: name
                            font.pixelSize: 20
                            font.bold: true
                            width: contactList.width - profilePic.width - 40
                            elide: Text.ElideRight
                        }

                        Text {
                            text: phoneNumber
                            font.pixelSize: 18
                            color: "black"
                            width: contactList.width - profilePic.width - 40
                            elide: Text.ElideRight
                        }
                    }
                }
            }
        }
    }
    Rectangle {
        id: addButton
        width: 60
        height: 60
        radius: 30
        color: "#2196F3"
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.rightMargin: 20
        anchors.bottomMargin: 20

        Image {
            anchors.centerIn: parent
            source: "qrc:/Images/AddButtonIcon.png"
            width: 36
            height: 36
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                addButtonClicked()
            }
        }
    }
}


