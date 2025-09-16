import QtQuick 2.12
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

Rectangle
{
    width: parent.width/2
    height: parent.height/2

    signal backButtonClicked()

    property var nameList: []
    property var numberList: []

    ListView
    {
        id: myListView
        width: parent.width
        height: parent.height -100
        model: nameList.length
        clip: true
        delegate: mydelegate

        Component
        {
            id: mydelegate

            Column
            {
                width: myListView.width
                height: myListView.height
                // anchors.centerIn: parent
                spacing: 15

                // Repeater{
                //     width: parent.width
                //     height: parent.height
                //     model: nameList

                Text {
                    id: name
                    text: "name: "+nameList[index].contactName
                    height: 30
                }
                // }
                // Repeater{
                //     width: parent.width
                //     height: parent.height
                //     model: numberList
                Text {
                    id: number
                    text: "number: "+nameList[index].contactNumber
                    height: 30
                }
                // }

            }
        }
    }
    Row{
        spacing: 5
        width: parent.width
        height: 40
        anchors.top: myListView.bottom
        Button
        {
            id: backButton
            // width: parent.width
            // height: 40
            // anchors.top: myListView.bottom
            text: "back"
            onClicked:
            {
                backButtonClicked()
            }
        }
        Button
        {
            id: dataButton
            // width: parent.width
            // height: 40
            // anchors.top: myListView.bottom
            text: "addNumber"
            onClicked:
            {
                ContactModel.addNumberButtonClicked()
            }
        }
    }

}
