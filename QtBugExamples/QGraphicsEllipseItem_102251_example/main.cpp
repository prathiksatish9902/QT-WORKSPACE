#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QPen>
#include <QDebug>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Create a scene and view
    QGraphicsScene scene;
    QGraphicsView view(&scene);
    view.setSceneRect(-10, -10, 20, 20);

    // Create an ellipse with a cosmetic pen
    QPen pen(QColor(93, 109, 194), 5);
    pen.setCosmetic(true);
    QGraphicsEllipseItem *ellipse = new QGraphicsEllipseItem(-0.2, -0.2, 0.4, 0.4);
    ellipse->setPen(pen);
    scene.addItem(ellipse);

    // Print the bounding rectangle
    QRectF boundingRect = ellipse->boundingRect();
    qDebug() << "Bounding Rect: x =" << boundingRect.x()
             << ", y =" << boundingRect.y()
             << ", width =" << boundingRect.width()
             << ", height =" << boundingRect.height();

    view.show();
    return app.exec();
}
