import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Rectangle {
    id: _background
    anchors.centerIn: parent
    border.color: "black"
    radius: 10

    signal signinsubmitClicked()
    signal cancelClicked()
    signal closeClicked()
    signal loginSuccess()
    signal loginFailure()

    Column {
        id: _col
        spacing: 10
        anchors.centerIn: parent

        Text {
            id: _signinText
            text: qsTr("SignIn")
            font.bold: true
            font.pixelSize: 26
            color: "black"
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Text {
            id: userLabel
            text: qsTr("Username")
        }

        TextField {
            id: _userNameedit
            width: _background.width / 2
            height: 50
            placeholderText: "Enter Username"
        }

        Text {
            id: pwdLabel
            text: qsTr("Password")
        }

        TextField {
            id: _passwordedit
            width: _background.width / 2
            height: 50
            placeholderText: "Enter Password"
        }
        Button {
            id: _submitbtn
            text: "Submit"
            width: _background.width / 2
            height: 50
            onClicked:
            {
                signinsubmitClicked()
                var isAuthenticationSuccessfull = studentData.authenticate(_userNameedit.text, _passwordedit.text)
                if (isAuthenticationSuccessfull)
                {
                    loginSuccess()
                }
                else
                {
                    loginFailure()
                }

            }
        }

        Button {
            id: _cancelbtn
            text: "Cancel"
            width: _background.width / 2
            height: 50
            onClicked: cancelClicked()
        }
        Button {
            id: _closebtn
            text: "Close"
            width: _background.width / 2
            height: 50
            anchors.horizontalCenter: _btnrow.horizontalCenter
            onClicked: closeClicked()
        }
    }
}
