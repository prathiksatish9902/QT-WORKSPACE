import QtQuick 6.5
import QtQuick.Controls 6.5
import QtQml.Models 2.15   // Required for ItemSelectionModel

ApplicationWindow {
    visible: true
    width: 400
    height: 400
    title: "ListView with ItemSelectionModel"

    // ListView {
    //     id: listView
    //     width: 200
    //     height: 300
    //     anchors.centerIn: parent

    //     model: ListModel {
    //         id: listModel
    //         ListElement { name: "Alpha" }
    //         ListElement { name: "Beta" }
    //         ListElement { name: "Gamma" }
    //     }

    //     delegate: Rectangle {
    //         width: listView.width
    //         height: 40
    //         color: styleData.selected ? "lightblue" : "white"

    //         border.color: "gray"
    //         Text {
    //             anchors.centerIn: parent
    //             text: name
    //         }

    //         MouseArea {
    //             anchors.fill: parent
    //             onClicked: {
    //                 listView.currentIndex = index
    //                 selectionModel.select(index, ItemSelectionModel.ClearAndSelect)
    //             }
    //         }
    //     }

    //     // Important: This must be outside the delegate
    //     ItemSelectionModel {
    //         id: selectionModel
    //         model: listModel

    //         onCurrentIndexChanged: {
    //             console.log("Current index changed to:", currentIndex)
    //             console.log("Selection indexes:")
    //             for (const i of selection.indexes) {
    //                 console.log("Selected index:", i.row)
    //             }
    //         }
    //     }
    // }

    ListView {
        id: listView
        width: 200; height: 300
        model: ListModel {
            ListElement { name: "Alpha" }
            ListElement { name: "Beta" }
            ListElement { name: "Gamma" }
        }

        delegate: Rectangle {
            width: parent.width; height: 40
            Text { text: name }
        }

        // Selection model
        ItemSelectionModel {
            id: selectionModel
            model: listView.model
        }

        // This is unclear!
        onCurrentIndexChanged: {
            console.log("Current index changed to:", selectionModel.currentIndex)
            console.log("Selection:", selectionModel.selection)  // What is this?
        }
    }

}
