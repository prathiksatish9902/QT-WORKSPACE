#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QBrush>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Create a scene
    QGraphicsScene scene;

    // Add two overlapping rectangles
    QGraphicsRectItem* red = scene.addRect(0, 0, 100, 100, QPen(), QBrush(Qt::red));
    QGraphicsRectItem* blue = scene.addRect(25, 25, 100, 100, QPen(), QBrush(Qt::blue));

    // Stack red BEFORE blue (i.e., below blue in the stacking order)
    red->stackBefore(blue);
    // blue->stackBefore(red);

    // Create a view to visualize the scene
    QGraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);
    view.setWindowTitle("QGraphicsItem::stackBefore() Demo");
    view.resize(300, 300);
    view.show();

    return app.exec();
}
/*!
    Stacks this item before \a sibling in the stacking order, which means this item will be drawn behind the sibling item.
    In other words, the sibling item will visually appear on top of this item.

    The two items must be siblings (i.e., they must share the same parent item or both be toplevel items).
    The sibling must have the same Z value as this item; otherwise, calling this function will have no effect.

    By default, all sibling items are stacked by insertion order (i.e., the first item you add is drawn behind the next item you add).
    If two items have different Z values, the item with the higher Z value appears on top.
    When Z values are the same, stacking order is determined by insertion or calls to this function.
*/
