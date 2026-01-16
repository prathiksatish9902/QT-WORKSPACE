import QtQuick

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    x: 200
    Rectangle
    {
        id: rect1
        width: 300
        height: 400
        color: "blue"
        x: 200
        Rectangle
        {
            id: rect2
            width: rect1.width / 3
            height: rect1.height / 3
            color: "red"
            // x: 200
        }
        Rectangle
        {
            id: rect3
            width: rect2.width / 3
            height: rect2.height / 3
            color: "yellow"
            // x: 200
        }
    }
}
/*positioning
  anchors
  layouts

  anchors are dynamically algning visual item types
  positioning (x , y)
  anchors -> 6lines(top , bottom , left , right , horizantal center , vertical center)
  */
