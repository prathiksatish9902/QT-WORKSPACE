#include "widget.h"
#include "abc.h"
#include "dbc.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create widgets
    Widget w;
    ABC abc;
    DBC dbc;

    // Show the widgets (this will eventually trigger paintEvent)
    w.show();
    abc.show();
    dbc.show();

    // If you want to force an immediate repaint
    w.update();
    abc.update();
    dbc.update();

    // Using QObject pointer to access widgets
    QObject *objectW = &w;
    QObject *objectAbc = &abc;
    QObject *objectDbc = &dbc;

    // To call paintEvent via QObject, you need to cast:
    // This is generally not recommended but can be done
    if (QWidget *widget = static_cast<QWidget*>(objectW)) {
        widget->update(); // This will trigger paintEvent
    }

    if (QWidget *abcWidget = static_cast<QWidget*>(objectAbc)) {
        abcWidget->update(); // This will trigger paintEvent
    }

    if (QWidget *dbcWidget = static_cast<QWidget*>(objectDbc)) {
        dbcWidget->update(); // This will trigger paintEvent
    }

    return a.exec();
}
