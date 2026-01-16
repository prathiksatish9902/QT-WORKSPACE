import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15



Rectangle {
    id: _welcomeRectangle
    anchors.centerIn: parent
    border.color: "black"

    signal signinClicked()
    signal signupClicked()

    ColumnLayout {
        spacing: 50
        anchors.centerIn: parent

        Text {
            id: _welcomeText
            text: qsTr("WELCOME")
            font.bold: true
            font.pixelSize: 26
            color: "red"
        }

        Button {
            id: _signinButton
            text: "Signin"
            Layout.alignment: Qt.AlignHCenter
            background: Rectangle {
                implicitWidth: 120
                implicitHeight: 40
                radius: 6
                border.color: "blue"
                border.width: 2
                color: _signinButton.down ? "lightblue" : "transparent"
            }
            contentItem: Text {
                text: parent.text
                anchors.centerIn: parent
                color: "red"
                font.pixelSize: 16
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
            onClicked: signinClicked()
        }

        Button {
            id: _signupButton
            text: "Signup"
            Layout.alignment: Qt.AlignHCenter
            background: Rectangle {
                implicitWidth: 120
                implicitHeight: 40
                radius: 6
                border.color: "blue"
                border.width: 2
                color: _signupButton.down ? "lightblue" : "transparent"
            }
            contentItem: Text {
                text: parent.text
                anchors.centerIn: parent
                color: "red"
                font.pixelSize: 16
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
            onClicked: signupClicked()
        }
    }
}

