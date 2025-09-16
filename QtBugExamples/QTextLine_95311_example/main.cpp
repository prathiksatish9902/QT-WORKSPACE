#include <QApplication>
#include <QFont>
#include <QFontMetricsF>
#include <QTextLayout>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QFont font("Arial", 20);  // Any font with visible leading
    QFontMetricsF fm(font);
    qreal lineSpacing = fm.lineSpacing();

    QTextLayout layout("Hello, world!", font);
    layout.beginLayout();
    QTextLine line = layout.createLine();
    layout.endLayout();

    qreal textLineHeight = line.height();

    qDebug() << "QFontMetricsF::lineSpacing() =" << lineSpacing;
    qDebug() << "QTextLine::height()           =" << textLineHeight;

    return 0;
}
