#include <QApplication>
#include "rectanglewidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    RectangleWidget w;
    w.setRectangle(30, 30, 200, 100);
    w.resize(300, 200);
    w.show();

    return app.exec();
}
