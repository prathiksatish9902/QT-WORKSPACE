#include <QApplication>
#include "hboxexample.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    HBoxExample window;
    window.show();

    return app.exec();
}
