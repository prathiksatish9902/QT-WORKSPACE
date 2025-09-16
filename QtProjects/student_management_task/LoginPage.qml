import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle{
    id: loginPage
    radius: 10
    color: "lightgrey"

    Column{
        id: loginColumnLayout
        spacing: 10
        anchors.verticalCenter: loginPage.verticalCenter
        anchors.horizontalCenter: loginPage.horizontalCenter

        Text {
            id: userName
            text: qsTr("User Name")
            color: "Black"
            font.pixelSize: 18
        }
        TextField{
            id: userNametext
            width: loginPage.width / 4
            height: 50
            placeholderText: "Enter User Name"
            placeholderTextColor: "Black"
            font.pixelSize: 14
            color: "Black"
        }


        Text {
            id: password
            text: qsTr("Password")
            color: "Black"
            font.pixelSize: 18
        }
        TextField{
            id: passwordNametext
            width: loginPage.width / 4
            height: 50
            placeholderText: "Enter Password"
            placeholderTextColor: "Black"
            font.pixelSize: 14
            color: "Black"
        }

        Button{
            id: signIn
            width: loginPage.width / 4
            height: 50

            Text {
                id: cancel
                text: qsTr("SignIn")
                anchors.centerIn: parent
                font.bold: true
                font.pixelSize: 14
                color: "Black"
            }

            onClicked: {
                console.log("SignIn Button Cicked")
            }
        }

        Button{
            id: signUp
            width: loginPage.width / 4
            height: 50

            Text {
                id: clear
                text: qsTr("SignUp")
                anchors.centerIn: parent
                font.bold: true
                font.pixelSize: 14
                color: "Black"
            }

            onClicked: {
                console.log("SignUp Button Cicked")
            }
        }
    }
}
