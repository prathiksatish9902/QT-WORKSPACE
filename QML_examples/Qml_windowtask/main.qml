import QtQuick
import QtQuick.Controls
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    Loader{
        id: _loader
        source: "Page1.qml"
        anchors.fill: parent
    }
    Connections{
        target: _loader.item

        function onPage1NextButton(){
            _loader.source = "Page2.qml"
        }
        function onPage2NextButton(){
            _loader.source = "Page3.qml"
        }
        function onPage2PreviousButton(){
            _loader.source = "Page1.qml"
        }
        function onPage3NextButton(){
            _loader.source = "Page4.qml"
        }
        function onPage3PreviousButton(){
            _loader.source = "Page2.qml"
        }
        function onPage4NextButton(){
            _loader.source = "Page5.qml"
        }
        function onPage4PreviousButton(){
            _loader.source = "Page3.qml"
        }
        function onPage5PreviousButton(){
            _loader.source = "Page4.qml"
        }
    }
}
