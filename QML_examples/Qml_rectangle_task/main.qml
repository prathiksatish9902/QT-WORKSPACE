import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    Rectangle{
        id: _parentrectangle
        width: 1500
        height: 600
        color: "grey"
        border.color: "black"
        x: 100
        y: 100
        Rectangle{
            id: _rectangle1
            width: 150
            height: 150
            radius: 360
            color: "yellow"
            border.color: "black"
            anchors.horizontalCenter: parent.left
            anchors.verticalCenter: parent.top
            anchors.centerIn: parent.left
        }
        Rectangle{
            id: _rectangle2
            width: 150
            height: 150
            radius: 360
            color: "red"
            border.color: "black"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.top
        }
        Rectangle{
            id: _rectangle3
            width: 150
            height: 150
            radius: 360
            color: "green"
            border.color: "black"
            anchors.left: _rectangle5.right
            anchors.top: parent.top
        }
        Rectangle{
            id: _rectangle4
            width: 150
            height: 150
            radius: 360
            color:"blue"
            border.color: "black"
            anchors.right: parent.right
            anchors.bottom: parent.bottom
        }
        Rectangle{
            id: _rectangle5
            width: 150
            height: 150
            radius: 360
            color: "orange"
            border.color: "black"

            anchors.left: _rectangle2.horizontalCenter
            anchors.top: parent.top
        }
        Rectangle{
            id: _rectangle6
            width: 150
            height: 150
            radius: 360
            color: "pink"
            border.color: "black"
            anchors.top: parent.bottom
            anchors.horizontalCenter: parent.right
        }
    }
}


// import QtQuick
// import QtQuick.Controls
// import QtQuick.Layouts

// ApplicationWindow {
//     width: 300
//     height: 200
//     visible: true

//     Pane {
//         width: parent.width
//         height: parent.height
//         // padding: 120
//         // topPadding: 120
//         // leftPadding: 50

//         Text {
//             text: "Hello with padding"
//             color: "white"
//             anchors.left: parent.left
//             anchors.leftMargin: 120
//         }
//     }
// }




// import QtQuick.Layouts
// import QtQuick
// Window {
//     width: 640
//     height: 480
//     visible: true
//     title: qsTr("Hello World")
// // Row{
// //     spacing: 2
// //     Rectangle { color: "red"; width: 50; height: 50 }
// //     Rectangle { color: "green"; width: 20; height: 50 }
// //     Rectangle { color: "blue"; width: 50; height: 20 }
// // }
//     function print(txt){
//         // console.log("hello world", txt)
//         return "hello"
//     }



//     RowLayout {
//         id: layout
//         anchors.fill: parent
//         spacing: 6
//         Rectangle {
//             color: 'teal'
//             Layout.fillWidth: true
//             Layout.minimumWidth: 50
//             Layout.preferredWidth: 100
//             Layout.maximumWidth: 300
//             Layout.minimumHeight: 150
//             Text {
//                 id: textid
//                 anchors.centerIn: parent
//                 text: parent.width + 'x' + parent.height
//             }

//             MouseArea{
//                 anchors.fill: parent
//                 onClicked: {
//                     // console.log("rectangle click started")
//                     var val = print(textid.text)
//                     console.log("rectangle click ended", val)

//                 }
//             }
//         }

//         Rectangle {
//             color: 'plum'
//             Layout.fillWidth: true
//             Layout.minimumWidth: 100
//             Layout.preferredWidth: 200
//             Layout.preferredHeight: 100
//             Text {
//                 anchors.centerIn: parent
//                 text: parent.width + 'x' + parent.height
//             }
//         }
//     }

// }
