import QtWayland.Compositor 1.15
import QtQuick 2.15
import QtQuick.Window 2.15

WaylandCompositor {
    id: compositor
    width: 1280
    height: 720

    WaylandOutput {
        id: output1
        position: Qt.point(0, 0)
        physicalSize: Qt.size(600, 340)
        scaleFactor: 1
        sizeFollowsWindow: true

        // Set manufacturer and model explicitly
        manufacturer: "Dell"
        model: "Dell U2419H"

        window: Window {
            width: 1280
            height: 720
            visible: true
            title: output1.manufacturer + " - " + output1.model
        }
    }
}

//output: Dell - Dell U2419H
