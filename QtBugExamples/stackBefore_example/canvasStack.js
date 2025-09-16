function Shape(type, color, x, y) {
    this.type = type;
    this.color = color;
    this.x = x;
    this.y = y;
}

function CanvasStack() {
    this.elements = [];
}

/**
 * Moves the given bottomShape to be visually below topShape in the stacking order.
 *
 * "stackBefore(bottomShape, topShape)" means:
 *      - Place bottomShape below topShape in the visual stack.
 *      - After this call, bottomShape will be rendered before (under) topShape.
 *
 * Note for non-native English speakers:
 *      - "before" here means "under" or "below" in the visual stacking order.
 *      - The lower an item is in the array, the earlier (and thus further back) it is drawn.
 */
CanvasStack.prototype.stackBefore = function (bottomShape, topShape) {
    const indexBottom = this.elements.indexOf(bottomShape);
    const indexTop = this.elements.indexOf(topShape);
    if (indexBottom !== -1 && indexTop !== -1 && indexBottom > indexTop) {
        this.elements.splice(indexBottom, 1);
        this.elements.splice(indexTop, 0, bottomShape);
    }
};

CanvasStack.prototype.render = function (context) {
    for (var i = 0; i < this.elements.length; i++) {
        var shape = this.elements[i];
        context.fillStyle = shape.color;
        context.fillRect(shape.x, shape.y, 10, 10);
    }
};
