import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    Column
    {
        spacing: 10
        anchors.centerIn: parent
    CustomCheckBox
    {
        id: termsAndCondition
        text: "I Agree For Terms And Conditions"
        // anchors.centerIn: parent
        function onCheckedChange(checked)
        {
            console.log("checked:" , checked)
        }
    }
    CustomCheckBox
    {
        id: rememberMe
        text: "Remember Me"
        // anchors.centerIn: parent
        function onCheckedChange(checked)
        {
            console.log("checked:" , checked)
        }
    }
    }
}
