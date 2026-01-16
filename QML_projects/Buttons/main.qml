import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls
import QtQuick.Layouts

Window {
    id: window
    width: 1000
    height: 600
    visible: true
    color: "lightgrey"
    title: qsTr("HolzherApplication")

    ColumnLayout {
        anchors.fill: parent
        spacing: 10

        Rectangle {
            id: rectangle1
            Layout.fillWidth: true
            Layout.preferredHeight: 60
            color: "red"
            radius: 10
            Layout.margins: 10
        }

        Rectangle {
            id: rectangle2
            Layout.fillWidth: true
            Layout.preferredHeight: 60
            color: "grey"
            radius: 10
            Layout.margins: 10
        }

        RowLayout {
            id: rowLayout
            Layout.margins: 10
            Layout.fillWidth: true
            Layout.fillHeight: true

            Loader {
                id: contentLoader
                // Layout.margins: 10
                Layout.fillWidth: true
                Layout.fillHeight: true
            }

            ApplicationMenuPage {
                id: menuPage
                // anchors.right: parent.right
                // anchors.rightMargin: 50
                Layout.preferredWidth: window.width / 10
                Layout.fillHeight: true

                onProductionButtonClicked: {
                    contentLoader.source = "ProductionPage.qml"
                }

                onSetUpButtonClicked: {
                    contentLoader.source = "SetUpPage.qml"
                }

                onSupportButtonClicked: {
                    contentLoader.source = "SupportPage.qml"
                }

                onToolsButtonClicked: {
                    contentLoader.source = "ToolsPage.qml"
                }

                onFavouriteButtonClicked: {
                    contentLoader.source = "FavouritePage.qml"
                }
            }
        }

        Rectangle {
            id: rectangle3
            Layout.fillWidth: true
            Layout.preferredHeight: 60
            color: "grey"
            radius: 10
            Layout.margins: 10
        }
    }
}


