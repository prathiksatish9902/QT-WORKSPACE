import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Shapes 1.10

Item
{
    id: root
    width: 250
    height: 250
    property int batteryLevel: 30
    property color activeColor: "#00CFFF"
    property color backgroundColor: "#222222"

    Shape
    {
        id: backgroundShape
        anchors.centerIn: parent
        width: parent.width
        height: parent.height

        ShapePath
        {
            id: backgroudShapePath
            strokeColor: root.backgroundColor
            strokeWidth: 14
            fillColor: "transparent"
            capStyle: ShapePath.RoundCap

            startX: backgroundShape.width / 2
            startY: 0

            PathArc
            {
                id: backgroundPathArc
                x: backgroundShape.width / 2
                y: backgroundShape.height
                radiusX: backgroundShape.width / 2 - 7
                radiusY: backgroundShape.height / 2 - 7
                useLargeArc: true
            }

            PathArc
            {
                x: backgroundShape.width / 2
                y: 0
                radiusX: backgroundShape.width / 2 - 7
                radiusY: backgroundShape.height / 2 - 7
                useLargeArc: false
            }
        }
    }

    Shape
    {
        id: foregroundShape
        anchors.centerIn: parent
        width: parent.width
        height: parent.height

        ShapePath
        {
            id: foregroundShapePath
            strokeColor: root.activeColor
            strokeWidth: 14
            fillColor: "transparent"
            capStyle: ShapePath.RoundCap

            PathAngleArc
            {
                id: foregroundPathArc
                centerX: foregroundShape.width / 2
                centerY: foregroundShape.height / 2
                radiusX: foregroundShape.width / 2 - 7
                radiusY: foregroundShape.height / 2 - 7
                startAngle: -90
                sweepAngle: (360 * root.batteryLevel) / 100
            }
        }
    }

    Text {
        text: root.batteryLevel + "%"
        anchors.centerIn: parent
        font.bold: true
        font.pixelSize: 40
        color: "black"
    }

    Text {
        text: "Battery"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.verticalCenter
        anchors.topMargin: 40
        font.pixelSize: 20
        color: "#888"
    }
}
