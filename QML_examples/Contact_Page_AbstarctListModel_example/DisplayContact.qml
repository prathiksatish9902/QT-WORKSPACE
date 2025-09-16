import QtQuick 2.12
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
Rectangle
{
    width: parent.width/2
    height: parent.height/2

    signal backButtonClicked()


    ListView
    {
        id: myListView
        width: parent.width
        height: parent.height -100
        model:ContactModel //10
        clip: true
        delegate: mydelegate

        Component
        {
            id: mydelegate

            Column
            {
                width: myListView.width
                height: myListView.height/5
                spacing: 15
                Text {
                    id: name
                    text: "name: "+contactName
                    height: 30
                }

                Text {
                    id: number
                    text: "number: "+contactNumber
                    height: 30
                }

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
            text: "back"
            onClicked:
            {
                backButtonClicked()
            }
        }
        Button
        {
            id: dataButton
            text: "addNumber"
            onClicked:
            {
                ContactModel.addNumberButtonClicked()
            }
        }
    }

}
