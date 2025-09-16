import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15


Rectangle {
    id: _background
    anchors.centerIn: parent
    border.color: "black"
    radius: 10

    signal signUpSubmitClicked()
    signal cancelClicked()
    signal closeClicked()



    function validateInputs() {
            if (_studentNameEdit.text === "" ||
                _mobileNumberEdit.text === "" ||
                _fatherNameEdit.text === "" ||
                _EmailidEdit.text === "" ||
                _signupuserNameedit.text === "" ||
                _signuppasswordedit.text === "") {
                console.log("All fields are required")
                return false
            }
            if (!_studentNameEdit.acceptableInput) {
                console.log("Student name must contain only letters")
                return false
            }
            if (!_fatherNameEdit.acceptableInput) {
                console.log("Father name must contain only letters")

                return false
            }
            if (!_mobileNumberEdit.acceptableInput) {
                console.log("Mobile number must be 10 digits")
                return false
            }
            if (!_EmailidEdit.acceptableInput) {
                console.log("Email must contain @ symbol")
                return false
            }
            if (_signuppasswordedit.text.length < 8) {
                console.log("Password must be at least 8 characters")
                return false
            }
            return true
        }

    Column {
        id: _col
        spacing: 10
        anchors.centerIn: parent

        Text {
            id: _signinText
            text: qsTr("SignUp")
            font.bold: true
            font.pixelSize: 26
            color: "black"
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Text {
            id: _studentName
            text: qsTr("Student Name")
        }

        TextField {
            id: _studentNameEdit
            width: _background.width / 1.5
            height: _background.height / 14
            placeholderText: "Enter Student Name"
            validator: RegularExpressionValidator { regularExpression: /^[a-zA-Z]+$/ }
        }

        Text {
            id: _mobileNumber
            text: qsTr("Mobile Number")
        }

        TextField {
            id: _mobileNumberEdit
            width: _background.width / 1.5
            height: _background.height / 14
            placeholderText: "Enter Mobile Number"
            validator: RegularExpressionValidator { regularExpression: /^[0-9]{10}+$/ }
        }

        Text {
            id: _fatherName
            text: qsTr("Father Name")
        }

        TextField {
            id: _fatherNameEdit
            width: _background.width / 1.5
            height: _background.height / 14
            placeholderText: "Enter Father Name"
            validator: RegularExpressionValidator { regularExpression: /^[a-zA-Z]+$/ }
        }

        Text {
            id: _email
            text: qsTr("Email-id")
        }

        TextField {
            id: _EmailidEdit
            width: _background.width / 1.5
            height: _background.height / 14
            placeholderText: "Enter Email-id"
            validator: RegularExpressionValidator { regularExpression: /^[^\s@]+@[^\s@]+\.[^\s@]+$/ }
        }

        Text {
            id: signupuserLabel
            text: qsTr("Username")
        }

        TextField {
            id: _signupuserNameedit
            width: _background.width / 1.5
            height: _background.height / 14
            placeholderText: "Enter Username"
        }

        Text {
            id: signuppwdLabel
            text: qsTr("Password")
        }

        TextField {
            id: _signuppasswordedit
            width: _background.width / 1.5
            height: _background.height / 14
            placeholderText: "Enter Password"
            echoMode: TextInput.Password
        }


        Row {
            id: _btnrow
            spacing: 10
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.margins: 30

            Button {
                id: _signupsubmitbtn
                text: "Submit"
                width: _background.width / 4
                height: _background.height / 16
                onClicked:
                {
                    if (validateInputs())
                    {
                    studentData.addStudent(_studentNameEdit.text , _mobileNumberEdit.text , _fatherNameEdit.text , _EmailidEdit.text , _signupuserNameedit.text , _signuppasswordedit.text)
                    // studentData.addStudent( , _mobileNumberEdit.text , _fatherNameEdit.text , _EmailidEdit.text , _signupuserNameedit.text , _signuppasswordedit.text)
                    signUpSubmitClicked()
                    }
                }
            }

            Button {
                id: _signupcancelbtn
                text: "Cancel"
                width: _background.width / 4
                height: _background.height / 16
                onClicked: cancelClicked()
            }
        }

        Button {
            id: _signupclosebtn
            text: "Close"
            width: _background.width / 4
            height: _background.height / 16
            anchors.horizontalCenter: _btnrow.horizontalCenter
            onClicked: closeClicked()
        }
    }
}
