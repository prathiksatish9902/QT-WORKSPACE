import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    width: 500
    height: 750
    visible: true
    title: "Contacts"

    property int selectedContactIndex: -1

    Loader {
        id: pageLoader
        anchors.fill: parent
        source: "ContactList.qml"

        onLoaded: {
            if (item && source.toString().includes("ContactList.qml")) {
                item.showContact.connect(function(idx) {
                    selectedContactIndex = idx
                    pageLoader.setSource("ContactInfo.qml", { contactIndex: idx, editMode: false })
                })
                item.editContact.connect(function(idx) {
                    selectedContactIndex = idx
                    pageLoader.setSource("ContactInfo.qml", { contactIndex: idx, editMode: true })
                })
            }
            if (item && source.toString().includes("ContactInfo.qml")) {
                item.backToList.connect(function() {
                    pageLoader.setSource("ContactList.qml")
                })
            }
        }
    }
}
