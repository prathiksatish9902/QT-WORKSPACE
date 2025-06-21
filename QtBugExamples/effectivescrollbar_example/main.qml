import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts
Window {
    visible: true
    width: 300
    height: 250
    title: "ScrollView effective size"
    color: "black"

    ScrollView {
        id: scrollView
        anchors.fill: parent
        clip: true
        // Set content width to account for wide content
        contentWidth: column.width
        // Let contentHeight be driven by Column's implicit height
        contentHeight: column.implicitHeight + (horizontalScroller.visible ? horizontalScroller.height : 0)

        ScrollBar.horizontal: ScrollBar {
            id: horizontalScroller
            policy: ScrollBar.AlwaysOn
            y: scrollView.height - height
            width: scrollView.availableWidth
            implicitHeight: 40

            contentItem: Rectangle {
                implicitHeight: 40
                radius: height / 2
                color: "#cccccc"
            }
            background: Rectangle {
                implicitHeight: 6
                radius: height / 2
                color: "transparent"
            }
        }

        ScrollBar.vertical: ScrollBar {
            id: scroller
            policy: ScrollBar.AlwaysOn
            x: scrollView.width - width
            height: scrollView.availableHeight

            contentItem: Rectangle {
                implicitWidth: 40
                radius: width / 2
                color: "#cccccc"
            }
            background: Rectangle {
                implicitWidth: 6
                radius: width / 2
                color: "transparent"
            }
        }

        Column {
            id: column
            // Set width larger than ScrollView to enable horizontal scrolling
            width: scrollView.width + (scrollView.width / 2)// Wider than ScrollView to trigger horizontal scrollbar
            spacing: 2

            Repeater {
                model: 30

                delegate: ItemDelegate {
                    width: parent.width // Match Column's wider width
                    text: "Item " + index
                    anchors.left: parent.left
                    anchors.leftMargin: 20
                }
            }
        }

        Component.onCompleted: {
            console.log("Initial effectiveScrollBarHeight:", scrollView.effectiveScrollBarHeight)
            console.log("Initial effectiveScrollBarWidth:", scrollView.effectiveScrollBarWidth)
            console.log("ScrollView availableWidth:", scrollView.availableWidth)
        }

        onEffectiveScrollBarHeightChanged: console.log("effectiveScrollBarHeight changed:", effectiveScrollBarHeight)
        onEffectiveScrollBarWidthChanged: console.log("effectiveScrollBarWidth changed:", effectiveScrollBarWidth)
    }
}


