import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    id: registerPage
    width: parent.width
    height: parent.height
    color: "Black"

    Column{
        id: columnLayout
        spacing:  10
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: parent.height / 4

        Text {
            id: studentName
            text: qsTr("Student Name")
            color: "White"
            font.pixelSize: 18
        }
        TextField{
            id: studentNametext
            width: registerPage.width / 4
            height: 50
            placeholderText: "Enter Student Name"
            placeholderTextColor: "White"
            font.pixelSize: 14
            color: "White"
        }


        Text {
            id: phoneNumber
            text: qsTr("Phone Number")
            color: "White"
            font.pixelSize: 18
        }
        TextField{
            id: phoneNumbertext
            width: registerPage.width / 4
            height: 50
            placeholderText: "Enter Phone Number"
            placeholderTextColor: "White"
            font.pixelSize: 14
            color: "White"
        }



        Text {
            id: fatherName
            text: qsTr("Father Name")
            color: "White"
            font.pixelSize: 18
        }
        TextField{
            id: fathereNameText
            width: registerPage.width / 4
            height: 50
            placeholderText: "Enter Father Name"
            placeholderTextColor: "White"
            font.pixelSize: 14
            color: "White"
        }


        Text {
            id: email
            text: qsTr("Email Id")
            color: "White"
            font.pixelSize: 18
        }
        TextField{
            id: emailText
            width: registerPage.width / 4
            height: 50
            placeholderText: "Enter Email Id"
            placeholderTextColor: "White"
            font.pixelSize: 14
            color: "White"
        }



        Text {
            id: password
            text: qsTr("Password")
            color: "White"
            font.pixelSize: 18
        }
        TextField{
            id: passwordText
            width: registerPage.width / 4
            height: 50
            placeholderText: "Enter Password"
            placeholderTextColor: "White"
            font.pixelSize: 14
            color: "White"
        }

        Row{
            id: rowLayout
            // spacing: 5

            Button{
                id: cancelButton
                width: registerPage.width / 8
                height: 50

                Text {
                    id: cancel
                    text: qsTr("Cancel")
                    anchors.centerIn: parent
                    font.bold: true
                    font.pixelSize: 14
                    color: "White"
                }

                onClicked: {
                    console.log("Cancel Button Cicked")
                }
            }

            Button{
                id: clearButton
                width: registerPage.width / 8
                height: 50

                Text {
                    id: clear
                    text: qsTr("Clear")
                    anchors.centerIn: parent
                    font.bold: true
                    font.pixelSize: 14
                    color: "White"
                }

                onClicked: {
                    console.log("Clear Button Cicked")
                }
            }
        }
        Button{
            id: submitButton
            width: registerPage.width / 8
            height: 50
            anchors.horizontalCenter: parent.horizontalCenter

            Text {
                id: submit
                text: qsTr("Submit")
                anchors.centerIn: parent
                font.bold: true
                font.pixelSize: 14
                color: "White"
            }

            onClicked: {
                console.log("Submit Button Cicked")
            }
        }
    }
}
