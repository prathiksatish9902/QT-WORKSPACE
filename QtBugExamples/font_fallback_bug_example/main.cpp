#include <QApplication>
#include <QFontDatabase>
#include "fontfallbackwidget.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Add a fallback font that supports CJK characters
    QFontDatabase::addApplicationFont("/path/to/NotoSansCJKsc-Regular.ttf");

    FontFallbackWidget widget;
    widget.setWindowTitle("Font Fallback Bug Example");
    widget.resize(300, 100);
    widget.show();

    return app.exec();
}
