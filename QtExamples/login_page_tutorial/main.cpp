#include "LoginPage.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginPage w;
    w.createLoginPage();
    w.show();
    return a.exec();
}
