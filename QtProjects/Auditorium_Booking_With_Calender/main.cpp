#include "MainWindow.h"
#include "calendermanager.h"
#include <QApplication>
#include <QDate>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Create and display the main window
    MainWindow mainWindow;
    mainWindow.show();

    // Get current date
    QDate currentDate = QDate::currentDate();

    // Display calendar information in console
    qDebug().noquote() << "\n========== Auditorium Booking System ==========";
    qDebug().noquote() << "Welcome to the Auditorium Booking System";
    qDebug().noquote() << "Today's Date:" << currentDate.toString("MMMM d, yyyy");
    qDebug().noquote() << "===========================================";
    qDebug().noquote() << "Initial Calendar View:";

    return app.exec();
}
