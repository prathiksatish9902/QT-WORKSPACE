#include <QApplication>
#include "TextEdit.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    TextEdit window;
    window.resize(400, 300);
    window.show();
    return app.exec();
}
