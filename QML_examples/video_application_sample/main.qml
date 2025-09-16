import QtQuick 2.15
import QtQuick.Controls 2.15
import QtMultimedia 5.15

ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: "Video Player Example"

    Rectangle {
        anchors.fill: parent
        color: "black"

        // Container that enforces 16:9 ratio
        Item {
            id: videoContainer
            anchors.centerIn: parent
            width: Math.min(parent.width, parent.height * 16/9)
            height: width * 9/16

            Video {
                id: videoPlayer
                anchors.fill: parent
                source: "file:///home/prathik/Downloads/NO%20TIME%20TO%20DIE%20_%20LAND%20ROVER%20NEW%20DEFENDER.mp4"
                autoPlay: true
                loops: MediaPlayer.Infinite
            }
        }

        Row {
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 10
            padding: 10

            Button {
                text: videoPlayer.playbackState === MediaPlayer.PlayingState ? "Pause" : "Play"
                onClicked: {
                    if (videoPlayer.playbackState === MediaPlayer.PlayingState)
                        videoPlayer.pause()
                    else
                        videoPlayer.play()
                }
            }

            Button {
                text: "Stop"
                onClicked: videoPlayer.stop()
            }
        }
    }
}
