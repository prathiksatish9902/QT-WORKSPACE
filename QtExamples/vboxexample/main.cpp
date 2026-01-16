#include <QApplication>
#include "vboxexample.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    VBoxExample window;
    window.show();

    return app.exec();
}
