import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Rectangle {
    id: offsetRectangle
    anchors.fill: parent
    border.color: "black"
    border.width: 2

    signal callApplicationButtonClicked()
    signal callHistoryApplicationButtonClicked()
    signal whatsappApplicationButtonClicked()

    RowLayout {
        id: applicationRow
        spacing: 80
        anchors.centerIn: parent

        Rectangle {
            id: callApplicationButton
            width: 60
            height: 80
            radius: 30

            Column {
                anchors.centerIn: parent
                spacing: 5

                Image {
                    anchors.horizontalCenter: parent.horizontalCenter
                    source: "qrc:/Images/CallApplicationIcon.png"
                    width: 50
                    height: 50
                }

                Text {
                    text: "Call"
                    font.pixelSize: 14
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    callApplicationButtonClicked()
                }
            }
        }

        Rectangle {
            id: callHistoryApplicationButton
            width: 60
            height: 80
            radius: 30

            Column {
                anchors.centerIn: parent
                spacing: 5

                Image {
                    anchors.horizontalCenter: parent.horizontalCenter
                    source: "qrc:/Images/CallHistoryApplication.png"
                    width: 50
                    height: 50
                }

                Text {
                    text: "Call History"
                    font.pixelSize: 14
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    callHistoryApplicationButtonClicked()
                }
            }
        }

        Rectangle {
            id: whatsappApplicationButton
            width: 60
            height: 80
            radius: 30

            Column {
                anchors.centerIn: parent
                spacing: 5

                Image {
                    anchors.horizontalCenter: parent.horizontalCenter
                    source: "qrc:/Images/WhatsappApplicationIcon.png"
                    width: 50
                    height: 50
                }

                Text {
                    text: "WhatsApp"
                    font.pixelSize: 14
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    whatsappApplicationButtonClicked()
                }
            }
        }
    }
}
