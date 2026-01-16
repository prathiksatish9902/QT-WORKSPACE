import QtQuick 2.15
import QtQuick.Window 2.15
import "canvasStack.js" as CanvasUtils

Window {
    visible: true
    width: 400
    height: 400

    Component.onCompleted: {
        let stack = new CanvasUtils.CanvasStack();
        let circle = new CanvasUtils.Shape("circle", "red", 20, 20);
        let square = new CanvasUtils.Shape("square", "blue", 30, 30);

        stack.elements.push(circle, square);
        stack.stackBefore(circle, square);

        console.log("Rendering stack:");

        // Declare fillStyle explicitly
        let context = {
            fillStyle: "",
            fillRect: function(x, y, w, h) {
                console.log("Drawing " + this.fillStyle + " shape at (" + x + ", " + y + ")");
            }
        };

        stack.render(context);
    }
}
