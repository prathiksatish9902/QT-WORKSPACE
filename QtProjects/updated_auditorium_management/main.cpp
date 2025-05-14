#include <QApplication>
#include <QDebug>
#include "calendarwidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qDebug() << "Starting Calendar Application";

    CalendarWidget* calendarWidget = new CalendarWidget();
    calendarWidget->show();

    return app.exec();
}
