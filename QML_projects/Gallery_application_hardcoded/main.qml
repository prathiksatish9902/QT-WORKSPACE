import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Text {
        id: heading
        text: "Gallery Application"
        font.bold: true
        font.pixelSize: 32
        anchors.bottom: photoGrid.top
        anchors.bottomMargin: 30
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Grid {
        id: photoGrid
        anchors.centerIn: parent
        columns: 4
        rows: 3
        spacing: 5
        z: 1

        Repeater {
            id: imageRepeater
            model: 10
            Item {
                id: imageContainer
                width: 150
                height: 100

                Image {
                    id: image
                    width: parent.width
                    height: parent.height
                    fillMode: Image.PreserveAspectFit
                    source: "qrc:/Images/AddButtonIcon.png"
                    anchors.centerIn: parent

                    states: [
                        State {
                            name: "expanded"
                            PropertyChanges {
                                target: image
                                width: photoGrid.width * 2
                                height: photoGrid.height * 2
                                x: photoGrid.x - imageContainer.x
                                y: photoGrid.y - imageContainer.y
                                z: 10
                            }
                        },
                        State {
                            name: "normal"
                            PropertyChanges {
                                target: image
                                width: 150
                                height: 100
                                x: 0
                                y: 0
                                z: 1
                            }
                        }
                    ]

                    transitions: [
                        Transition {
                            from: "normal"
                            to: "expanded"
                            reversible: true
                            NumberAnimation {
                                properties: "width,height,x,y"
                                duration: 300
                                easing.type: Easing.InOutQuad
                            }
                        }
                    ]

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            if (image.state === "expanded") {
                                image.state = "normal"
                            } else {
                                for (var i = 0; i < imageRepeater.count; i++) {
                                    imageRepeater.itemAt(i).children[0].state = "normal"
                                }
                                image.state = "expanded"
                            }
                        }
                    }
                }
            }
        }
    }
}
