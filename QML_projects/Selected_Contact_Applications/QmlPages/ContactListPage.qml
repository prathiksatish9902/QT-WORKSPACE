import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Rectangle {
    id: borderRectangle
    anchors.fill: parent
    border.color: "black"
    border.width: 2

    signal addButtonClicked()
    signal listPageBackButtonClicked()
    signal contactClicked()
    signal dataSendClicked(string name, string phoneNumber, string profileImage)

    property string searchText: ""

    Popup {
        id: callingPopup
        modal: true
        x: (parent.width - width) / 2
        y: (parent.height - height) / 2
        width: 300
        height: 300
        focus: true

        property string popupName: ""
        property string popupNumber: ""
        property string popupProfileImage: ""

        background: Rectangle {
            color: "white"
            border.color: "black"
            border.width: 2
            radius: 10
        }

        Column {
            anchors.centerIn: parent
            spacing: 20

            Rectangle {
                width: 120
                height: 120
                radius: 60
                clip: true
                color: "lightgrey"
                anchors.horizontalCenter: parent.horizontalCenter

                Image {
                    anchors.fill: parent
                    anchors.margins: 5
                    source: callingPopup.popupProfileImage
                    fillMode: Image.PreserveAspectFit
                    smooth: true
                    visible: callingPopup.popupProfileImage !== ""
                }
                Text {
                    anchors.centerIn: parent
                    text: callingPopup.popupName.charAt(0).toUpperCase()
                    font.pixelSize: 48
                    font.bold: true
                    color: "white"
                    visible: callingPopup.popupProfileImage === ""
                }
            }
            Text {
                text: callingPopup.popupName
                font.pixelSize: 24
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
                width: parent.width
                elide: Text.ElideRight
            }

            Text {
                text: callingPopup.popupNumber
                font.pixelSize: 24
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
                width: parent.width
            }

            Rectangle {
                width: 60
                height: 60
                radius: 30
                color: "#cccccc"
                anchors.horizontalCenter: parent.horizontalCenter
                Image {
                    anchors.centerIn: parent
                    source: "qrc:/Images/CallHangIcon.png"
                    width: 40
                    height: 40
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        callingPopup.close()
                    }
                }
            }
        }
    }

    ColumnLayout {
        id: headingColoumn
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
                id: heading
                text: qsTr("Phone Book")
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
            height: borderRectangle.height - headingColoumn.height - 40
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.topMargin: 20
            model: PhoneBookModel
            spacing: 10

            delegate: Rectangle {
                width: contactList.width
                height: 60
                color: "royalblue"
                border.color: "black"
                radius: 15
                anchors.margins: 5

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        dataSendClicked(name, phoneNumber, profileImage)
                    }
                }

                Row {
                    anchors {
                        left: parent.left
                        top: parent.top
                        bottom: parent.bottom
                        right: callButton.left
                        margins: 10
                    }
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
                            source: profileImage
                            fillMode: Image.PreserveAspectCrop
                            smooth: true
                            visible: profileImage !== ""
                        }

                        Text {
                            anchors.centerIn: parent
                            text: name.charAt(0).toUpperCase()
                            font.pixelSize: 24
                            font.bold: true
                            color: "white"
                            visible: profileImage === ""
                        }
                    }

                    Column {
                        anchors.verticalCenter: parent.verticalCenter
                        spacing: 4

                        Text {
                            text: name
                            font.pixelSize: 20
                            font.bold: true
                            elide: Text.ElideRight
                        }

                        Text {
                            text: phoneNumber
                            font.pixelSize: 18
                            color: "black"
                            elide: Text.ElideRight
                        }
                    }
                }

                Image {
                    id: callButton
                    source: "qrc:/Images/CallApplicationIcon.png"
                    width: 40
                    height: 40
                    anchors.right: parent.right
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.rightMargin: 10

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            console.log("Call clicked:", phoneNumber)
                            CallHistoryModel.addOutgoingCall(name, phoneNumber, profileImage) // Add to call history
                            callingPopup.popupName = name
                            callingPopup.popupNumber = phoneNumber
                            callingPopup.popupProfileImage = profileImage
                            callingPopup.open()
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
