import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls
import QtQuick.Layouts
import "./Components"

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
                    contentLoader.source = "qrc:/Components/ProductionPage.qml"
                }

                onSetUpButtonClicked: {
                    contentLoader.source = "qrc:/Components/SetUpPage.qml"
                }

                onSupportButtonClicked: {
                    contentLoader.source = "qrc:/Components/SupportPage.qml"
                }

                onToolsButtonClicked: {
                    contentLoader.source = "qrc:/Components/ToolsPage.qml"
                }

                onFavouriteButtonClicked: {
                    contentLoader.source = "qrc:/Components/FavouritePage.qml"
                }
            }
        }
    }
}


