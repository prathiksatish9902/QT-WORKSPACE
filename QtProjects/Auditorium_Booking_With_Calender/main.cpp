#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.setGeometry(100, 100, 300, 300); // Set the window size and position
    mainWindow.setWindowTitle("Auditorium Booking System");
    mainWindow.show();

    return app.exec();
}
