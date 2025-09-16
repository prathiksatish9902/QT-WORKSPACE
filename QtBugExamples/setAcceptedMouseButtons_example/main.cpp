#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QGraphicsScene scene;
    QGraphicsView view(&scene);

    // Create a rectangle item
    QGraphicsRectItem *item = new QGraphicsRectItem(0, 0, 100, 100);
    item->setBrush(Qt::blue);

    // ❌ Deprecated usage — will trigger warning in Qt Creator or with clang-tidy
    // item->setAcceptedMouseButtons(0);
    item->setAcceptedMouseButtons(Qt::NoButton);

    scene.addItem(item);
    view.show();

    return app.exec();
}
