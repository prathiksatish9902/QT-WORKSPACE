import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    // signal submitButtonClicked()
    property var contactNameList: ContactModel.contactList
    // property var contactNumberList: []

    // Rectangle
    // {
    //     // anchors.fill: parent
    //     width: parent.width
    //     height: parent.height
    //     color:"red"
    //     Column
    //     {
    //         // anchors.horizontalCenter: parent.horizontalCenter
    //         // anchors.verticalCenter: parent.verticalCenter
    //         anchors.centerIn: parent
    //         width: parent.width / 2
    //         height: parent.height / 2
    //         spacing: 15

    //         TextField
    //         {
    //             id: contactName
    //             width: parent.width
    //             height: 40
    //             placeholderText: "Enter Contact Name"
    //             font.pixelSize: 16
    //             horizontalAlignment: Text.AlignHCenter
    //             // validator: RegularExpressionValidator { regularExpression: /[a-zA-Z0-9]+/ }
    //         }

    //         TextField
    //         {
    //             id: contactNumber
    //             width: parent.width
    //             height: 40
    //             placeholderText: "Enter Contact Number"
    //             font.pixelSize: 16
    //             horizontalAlignment: Text.AlignHCenter
    //         }

    //         Button
    //         {
    //             id: submitButton
    //             width: parent.width
    //             height: 40
    //             text: "Submit"
    //             onClicked:
    //             {

    //                 onSubmitButtonClicked()
    //             }
    //         }
    //     }
    // }

    // function onSubmitButtonClicked()
    // {
    //     contactNameList.push(contactName.displayText)
    //     contactNumberList.push(contactNumber.displayText)
    //     console.log("name"+contactNameList)
    //     console.log("number"+contactNumberList)
    //     // loader.setSource("DisplayContact.qml",
    //     //                  {
    //     //                      nameList: contactNameList,
    //     //                      numberList: contactNumberList
    //     //                  })
    //     displayContact.nameList = contactNameList
    //     displayContact.numberList = contactNumberList
    //     displayContact.visible = true
    // }

    // Loader
    // {
    //     id: loader
    //     anchors.fill: parent
    //     source: "main.qml"
    // }

    DisplayContact
    {
        id: displayContact
        width: parent.width
        height: parent.height
        visible: true
        nameList: contactNameList
    }

    // Connections
    // {
    //     target: displayContact
    //     function onBackButtonClicked()
    //     {
    //         displayContact.visible = false
    //     }

    // }
}
