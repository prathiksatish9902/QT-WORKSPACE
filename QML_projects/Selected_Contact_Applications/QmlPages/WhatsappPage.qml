import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Rectangle {
    id: borderRectangle
    anchors.fill: parent
    border.color: "black"
    border.width: 2

    signal listPageBackButtonClicked()

    property string searchText: ""

    Component.onCompleted: {
        console.log("WhatsappPage loaded")
    }

    ColumnLayout {
        id: whatsappHeadingColoumn
        spacing: 15
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 20

        RowLayout {
            spacing: 10
            Rectangle {
                id: listPageBackButton
                width: 60
                height: 60
                radius: 30
                anchors.leftMargin: 20
                Image {
                    anchors.centerIn: parent
                    source: "qrc:/Images/BackButtonIcon.png"
                    width: 50
                    height: 50
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        listPageBackButtonClicked()
                    }
                }
            }
            Text {
                id: whatsappHeading
                text: qsTr("Whatsapp")
                font.pixelSize: 32
                font.bold: true
            }
        }

        Item {
            width: borderRectangle.width - 20
            height: 60

            Rectangle {
                anchors.fill: parent
                radius: 20
                color: "white"
                border.color: "black"
            }

            Image {
                id: searchIcon
                source: "qrc:/Images/SearchIcon.png"
                width: 28
                height: 28
                anchors.left: parent.left
                anchors.leftMargin: 10
                anchors.verticalCenter: parent.verticalCenter
            }

            TextField {
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

        ListView {
            id: contactList
            width: borderRectangle.width - 20
            height: borderRectangle.height - whatsappHeadingColoumn.height - 40
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.topMargin: 20
            model: WhatsappModel
            spacing: 10

            delegate: Rectangle {
                width: contactList.width
                height: 60
                color: "royalblue"
                border.color: "black"
                radius: 15
                anchors.margins: 5

                Component.onCompleted: {
                    console.log("Whatsapp delegate: name=", name, "phoneNumber=", phoneNumber, "profileImage=", profileImage, "isEmpty=", profileImage === "")
                }

                Row {
                    anchors.fill: parent
                    anchors.margins: 10
                    spacing: 15

                    Rectangle {
                        width: 50
                        height: 50
                        radius: width / 2
                        clip: false
                        color: profileImage !== "" ? "lightgray" : "#555555"

                        Image {
                            anchors.fill: parent
                            source: profileImage
                            fillMode: Image.PreserveAspectCrop
                            smooth: true
                            visible: profileImage !== ""
                            onStatusChanged: {
                                if (status === Image.Error) {
                                    console.log("Image load error for", profileImage)
                                }
                            }
                        }

                        Text {
                            anchors.centerIn: parent
                            text: name.charAt(0).toUpperCase()
                            font.pixelSize: 28
                            font.bold: true
                            color: "white"
                            visible: profileImage === ""
                        }
                    }

                    Text {
                        text: name
                        font.pixelSize: 20
                        font.bold: true
                        anchors.verticalCenter: parent.verticalCenter
                        width: contactList.width - 50 - 40
                        elide: Text.ElideRight
                    }
                }
            }
        }
    }
}
