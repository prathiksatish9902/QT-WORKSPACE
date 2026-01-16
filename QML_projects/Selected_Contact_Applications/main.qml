import QtQuick 2.12
import QtQuick.Window 2.12
import "./QmlPages"

Window {
    width: 360
    height: 640
    visible: true
    title: qsTr("My Contacts")

    Loader {
        id: pageLoader
        anchors.fill: parent
        source: "qrc:/QmlPages/ApplicationSelectionPage.qml"
    }

    Connections {
        target: pageLoader.item

        function onCallApplicationButtonClicked() {
            pageLoader.source = "qrc:/QmlPages/ContactListPage.qml"
        }

        function onCallHistoryApplicationButtonClicked() {
            pageLoader.source = "qrc:/QmlPages/CallHistoryListPage.qml"
        }

        function onWhatsappApplicationButtonClicked() {
            pageLoader.source = "qrc:/QmlPages/WhatsappPage.qml"
        }

        function onAddButtonClicked() {
            pageLoader.source = "qrc:/QmlPages/AddContactPage.qml"
        }

        function onContactClicked() {
            selectedContactIndex = index
            pageLoader.source = "qrc:/QmlPages/ContactInfoPage.qml"
        }

        function onCancelButtonClicked() {
            pageLoader.source = "qrc:/QmlPages/ContactListPage.qml"
        }

        function onSaveButtonClicked() {
            pageLoader.source = "qrc:/QmlPages/ContactListPage.qml"
        }

        function onBackButtonClicked() {
            pageLoader.source = "qrc:/QmlPages/ContactListPage.qml"
        }

        function onListPageBackButtonClicked() {
            pageLoader.source = "qrc:/QmlPages/ApplicationSelectionPage.qml"
        }

        function onDeleteButtonClicked() {
            pageLoader.source = "qrc:/QmlPages/ContactListPage.qml"
        }

        function onDataSendClicked(name, phoneNumber, profileImage) {
            pageLoader.setSource("qrc:/QmlPages/ContactInfoPage.qml",
                                 {
                                     "name": name,
                                     "phoneNumber": phoneNumber,
                                     "profileImage": profileImage
                                 })
        }
    }
}
