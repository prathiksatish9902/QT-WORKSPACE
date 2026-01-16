#include <QApplication>
#include "mywidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MyWidget w; // Widget containing the vboxlayout and buttons
    w.show();

    return app.exec();
}
