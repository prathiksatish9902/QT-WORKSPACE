import QtQuick 2.15
import QtQuick.Layouts
Item {
    ColumnLayout {
        id: _buttonLayout
        anchors.right: parent.right
        anchors.rightMargin: 50
        anchors.top: parent.top
        anchors.topMargin: 150
        spacing: 25


        OperationalButton {
            id: _productionButton
            backgroundColor: "#4a4a4a"
            buttonBorderColor: "#4a4a4a"
            pressedColor: "#F5F5F5"
            radius: 8

            Layout.preferredWidth: 160
            Layout.preferredHeight: 60

            contentItem: Column {
                spacing: 8
                anchors.centerIn: parent

                Image {
                    id: _wrench
                    source: "qrc:/Icons/wrench.png"
                    width: 24
                    height: 24
                    fillMode: Image.PreserveAspectFit
                    anchors.horizontalCenter: parent.horizontalCenter
                }

                Text {
                    id: _productionText
                    text: qsTr("Production")
                    color: "white"
                    font.pixelSize: 18
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
        }

        OperationalButton {
            id: _setUpButton
            backgroundColor: "#4a4a4a"
            buttonBorderColor: "#4a4a4a"
            pressedColor: "#F5F5F5"
            radius: 8

            Layout.preferredWidth: 160
            Layout.preferredHeight: 60

            contentItem: Column {
                spacing: 8
                anchors.centerIn: parent

                Image {
                    id: _settings
                    source: "qrc:/Icons/setup.png"
                    width: 24
                    height: 24
                    fillMode: Image.PreserveAspectFit
                    anchors.horizontalCenter: parent.horizontalCenter
                }

                Text {
                    id: _setUpText
                    text: qsTr("Setup")
                    color: "white"
                    font.pixelSize: 18
                    anchors.horizontalCenter: parent.horizontalCenter

                }
            }
        }

        OperationalButton {
            id: _supportButton
            backgroundColor: "#4a4a4a"
            buttonBorderColor: "#4a4a4a"
            pressedColor: "#F5F5F5"
            radius: 8

            Layout.preferredWidth: 160
            Layout.preferredHeight: 60

            contentItem: Column {
                spacing: 8
                anchors.centerIn: parent

                Image {
                    id: _support
                    source: "qrc:/Icons/support.png"
                    width: 24
                    height: 24
                    fillMode: Image.PreserveAspectFit
                    anchors.horizontalCenter: parent.horizontalCenter
                }

                Text {
                    id: _supportText
                    text: qsTr("Support")
                    color: "white"
                    font.pixelSize: 18
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
        }

        OperationalButton {
            id: _toolsButton
            backgroundColor: "#4a4a4a"
            buttonBorderColor: "#4a4a4a"
            pressedColor: "#F5F5F5"
            radius: 8

            Layout.preferredWidth: 160
            Layout.preferredHeight: 60

            contentItem: Column {
                spacing: 8
                anchors.centerIn: parent

                Image {
                    id: _tools
                    source: "qrc:/Icons/tools.png"
                    width: 24
                    height: 24
                    fillMode: Image.PreserveAspectFit
                    anchors.horizontalCenter: parent.horizontalCenter
                }

                Text {
                    id: _toolsText
                    text: qsTr("Tools")
                    color: "white"
                    font.pixelSize: 18
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
        }

        OperationalButton {
            id: _favouriteButton
            backgroundColor: "#4a4a4a"
            buttonBorderColor: "#4a4a4a"
            pressedColor: "#F5F5F5"
            radius: 8

            Layout.preferredWidth: 160
            Layout.preferredHeight: 60

            contentItem: Column {
                spacing: 8
                anchors.centerIn: parent

                Image {
                    id: _star
                    source: "qrc:/Icons/favourite.png"
                    width: 24
                    height: 24
                    fillMode: Image.PreserveAspectFit
                    anchors.horizontalCenter: parent.horizontalCenter
                }

                Text {
                    id: _favouriteText
                    text: qsTr("Favourite")
                    color: "white"
                    font.pixelSize: 18
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
        }

    }

}
