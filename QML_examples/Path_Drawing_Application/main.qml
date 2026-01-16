import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15
import CustomComponents 1.0

Window {
    width: 800
    height: 600
    visible: true
    title: qsTr("Freehand Path Drawing with QQuickPaintedItem")

    PathItem {
        id: pathItem
        anchors.fill: parent
    }

    Button {
        text: "Generate New Path"
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: 20
        onClicked: {
            pointGenerator.generatePoints()
        }
    }

    Connections {
        target: pointGenerator
        function onPointsGenerated(points) {
            pathItem.points = points
        }
    }
}
