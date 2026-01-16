// import QtQuick 2.15
// import QtQuick.Controls 2.15
// import QtCharts 2.15

// ApplicationWindow {
//     visible: true
//     width: 800
//     height: 480
//     title: "Peak Power Chart"
//     color: "black"

//     Column {
//         anchors.fill: parent
//         anchors.margins: 20
//         spacing: 10

//         // Title
//         Text {
//             text: "Peak Power Delivered"
//             color: "#00AEEF"            // Cyan blue
//             font.pixelSize: 24
//             font.bold: true
//             horizontalAlignment: Text.AlignHCenter
//             anchors.horizontalCenter: parent.horizontalCenter
//         }

//         // Value
//         Text {
//             text: "111.00 kW"
//             color: "white"
//             font.pixelSize: 36
//             font.bold: true
//             horizontalAlignment: Text.AlignHCenter
//             anchors.horizontalCenter: parent.horizontalCenter
//         }

//         // Chart
//         ChartView {
//             id: chart
//             anchors.horizontalCenter: parent.horizontalCenter
//             width: parent.width
//             height: parent.height - 120
//             backgroundColor: "transparent"
//             legend.visible: false
//             antialiasing: true

//             ValueAxis {
//                 id: xAxis
//                 min: 0
//                 max: 100
//                 labelsColor: "white"
//                 gridVisible: false
//                 titleText: "SOC (%)"
//                 titleBrush: "white"
//             }

//             ValueAxis {
//                 id: yAxis
//                 min: 0
//                 max: 300
//                 labelsColor: "white"
//                 gridVisible: false
//                 titleText: "Power (kW)"
//                 titleBrush: "white"
//             }

//             LineSeries {
//                 id: series
//                 name: "Power curve"
//                 color: "#00AEEF"
//                 width: 2
//                 axisX: xAxis
//                 axisY: yAxis

//                 // Sample data points
//                 XYPoint { x: 20; y: 120 }
//                 XYPoint { x: 40; y: 150 }
//                 XYPoint { x: 50; y: 160 }
//                 XYPoint { x: 60; y: 170 }
//                 XYPoint { x: 80; y: 280 }
//             }
//         }
//     }
// }


import QtQuick 2.15
import QtQuick.Controls 2.15
import QtCharts 2.15

Window {
    width: 800

    height: 480
    visible: true
    title: "Chart Example"
    color: "white"

    ChartView
    {
        anchors.fill: parent
    }

    // ChartView {
        // anchors.fill: parent
        // legend.visible: false
        // antialiasing: true
        // backgroundColor: "transparent"

        // ValueAxis {
        //     id: xAxis
        //     min: 0
        //     max: 100
        //     labelsColor: "white"
        // }

        // ValueAxis {
        //     id: yAxis
        //     min: 0
        //     max: 300
        //     labelsColor: "white"
        // }

        // LineSeries {
        //     id: series
        //     axisX: xAxis
        //     axisY: yAxis
        //     color: "#00AEEF"
        //     width: 2

        //     XYPoint { x: 20; y: 120 }
        //     XYPoint { x: 40; y: 150 }
        //     XYPoint { x: 60; y: 170 }
        //     XYPoint { x: 80; y: 280 }
        // }
    // }
}
