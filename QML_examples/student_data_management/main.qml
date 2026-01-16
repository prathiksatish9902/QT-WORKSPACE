import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import StudentData 1.0
import "./Authentication"

Window {
    id: root
    width: 550
    height: 1000
    visible: true
    title: qsTr("Student Data Management")

   StudentModel{
       id: std

   }

    Loader {
        id: pageLoader
        width: 600
        height: parent.height
        anchors.centerIn: parent
        source: "Authentication/WelcomePage.qml"

        Connections {
            target: pageLoader.item
            // ignoreUnknownSignals: true

            function onSigninClicked() {
                pageLoader.source = "Authentication/SigninPage.qml"
            }

            function onSignupClicked() {
                pageLoader.source = "Authentication/SignupPage.qml"
            }

            function onSignUpSubmitClicked() {
                // validateInputs()
                pageLoader.source = "Authentication/SigninPage.qml"
                // pageLoader.source = "Authentication/ShowData.qml"
            }

            function onCancelClicked() {
                pageLoader.source = "Authentication/WelcomePage.qml"
            }

            function onSignInSubmitClicked() {
                // pageLoader.source  = "Authentication/WelcomePage.qml"
            }

            function onLoginSuccess()
            {
                // pageLoader.source = "Authentication/WelcomePage.qml"
                console.log("login Success")
                pageLoader.source = "Authentication/ShowData.qml"

            }

            function onLoginFailure()
            {

                pageLoader.source = "Authentication/SignupPage.qml"


            }

            function onCloseClicked() {
                Qt.quit()
            }
        }
    }
}
