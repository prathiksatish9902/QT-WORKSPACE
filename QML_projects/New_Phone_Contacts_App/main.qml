import QtQuick 2.12
import QtQuick.Window 2.12
import "./QmlPages"
Window {
    width: 360
    height: 640
    visible: true
    title: qsTr("My Contacts")



    Loader
    {
        id: pageLoader
        anchors.fill: parent
        source: "qrc:/QmlPages/ContactListPage.qml"
    }

    Connections
    {
        target: pageLoader.item

        function onAddButtonClicked()
        {
            pageLoader.source = "qrc:/QmlPages/AddContactPage.qml"
        }

        function onContactClicked()
        {
            selectedContactIndex = index
            pageLoader.source = "qrc:/QmlPages/ContactInfoPage.qml"
        }

        function onCancelButtonClicked()
        {
            pageLoader.source = "qrc:/QmlPages/ContactListPage.qml"
        }

        function onSaveButtonClicked() {
            pageLoader.source = "qrc:/QmlPages/ContactListPage.qml"
        }

        function onBackButtonClicked()
        {
            pageLoader.source = "qrc:/QmlPages/ContactListPage.qml"
        }

        function onDeleteButtonClicked()
        {
            pageLoader.source = "qrc:/QmlPages/ContactListPage.qml"
        }

        function onDataSendClicked(name, phoneNumber) {
            pageLoader.setSource("qrc:/QmlPages/ContactInfoPage.qml",
                                 {
                                     "name": name,
                                     "phoneNumber": phoneNumber
                                 }
                                 )
        }
    }

}
