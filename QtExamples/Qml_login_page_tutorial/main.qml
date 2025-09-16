import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    // signal
    Rectangle
    {
        id: _background
        width: parent.width / 2
        height: parent.height / 2
        anchors.centerIn: parent
        border.color: "black"
        radius: 10

        Column
        {
            id: _col
            spacing: 10
            anchors.centerIn: parent

            Text {
                id: userLabel
                text: qsTr("Username")
            }

            TextField
            {
                id: _userNameedit
                width: _background.width / 1.5
                height: _background.height / 6
                placeholderText: "Enter Username"
            }

            Text {
                id: pwdLabel
                text: qsTr("Username")
            }

            TextField
            {
                id: _passwordedit
                width: _background.width / 1.5
                height: _background.height / 6
                placeholderText: "Enter Password"
            }

            Row
            {
                id: _btnrow
                spacing: 10
                anchors.horizontalCenter: parent.horizontalCenter

                Button
                {
                    id: _submitbtn
                    text: "Submit"
                    width: _background.width / 4
                    height: _background.height / 8
                    onClicked:
                    {
                        submitButtonClicked()
                    }
                }

                Button
                {
                    id: _cancelbtn
                    text: "Cancel"
                    width: _background.width / 4
                    height: _background.height / 8
                    onClicked:
                    {
                        cancelButtonClicked()
                    }
                }
            }
        }
    }
    function submitButtonClicked()
    {
        console.log("submit button clicked"+_userNameedit.displayText)
        lhandler.username = _userNameedit.displayText
        lhandler.password = _passwordedit.displayText

    }
    function cancelButtonClicked()
    {
        console.log("cancel button clicked")

    }
}
