#include "widget.h"
#include"abc.h"
#include"dbc.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    w.show();
    w.paintEvent();

    ABC abc;
    abc.paintEvent();

    DBC dbc;
    dbc.paintEvent();

    QObject *object = new Widget;
    // object->paintEvent();
    object->p

    // QPaintDevice * device = new Widget;
    // device->paintEvent();
    return a.exec();
}
