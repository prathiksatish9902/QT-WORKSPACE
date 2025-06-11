import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQml.Models 2.15

ApplicationWindow {
    width: 300
    height: 400
    visible: true

    ListModel {
        id: nameModel
        ListElement { name: "Apple" }
        ListElement { name: "Banana" }
        ListElement { name: "Cherry" }
    }

    ItemSelectionModel {
        id: selectionModel
        model: nameModel
    }

    ListView {
        id: listView
        anchors.fill: parent
        model: nameModel
        // selection: selectionModel

        delegate: ItemDelegate {
            width: parent.width
            text: model.name
            checkable: true
            checked: selectionModel.isSelected(nameModel.index(index, 0))

            onClicked: {
                var idx = nameModel.index(index, 0)
                if (selectionModel.isSelected(idx)) {
                    selectionModel.select(idx, ItemSelectionModel.Deselect)
                } else {
                    selectionModel.select(idx, ItemSelectionModel.Select)
                }
            }
        }

}

    // Display current selection when it changes
    Component.onCompleted: {
        selectionModel.selectionChanged.connect(function() {
            console.log("Selection changed")
            for (var i = 0; i < nameModel.count; ++i) {
                if (selectionModel.isSelected(i)) {
                    console.log("Selected:", nameModel.get(i).name)
                }
            }
        })
    }
}
//136231
//132788
//129844
//123165
