#include "widget.h"
#include "abc.h"
#include "dbc.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget w;
    ABC abc;
    DBC dbc;

    w.show();
    abc.show();
    dbc.show();

    w.update();
    abc.update();
    dbc.update();

    QObject *objectW = &w;
    QObject *objectAbc = &abc;
    QObject *objectDbc = &dbc;


    if (QWidget *widget = static_cast<QWidget*>(objectW)) {
        widget->update();
    }

    if (QWidget *abcWidget = static_cast<QWidget*>(objectAbc)) {
        abcWidget->update();
    }

    if (QWidget *dbcWidget = static_cast<QWidget*>(objectDbc)) {
        dbcWidget->update();
    }

    return a.exec();
}
