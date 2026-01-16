#include <QApplication>
#include <QFont>
#include <QFontMetrics>
#include <QElapsedTimer>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont font = a.font();
    QFontMetrics fm(font);
    int len = 1;
    for (int i = 0; i < 9; ++i, len *= 10) {
        QString text(len, QChar('x')); // Create a string of 'x' characters with increasing length
        QElapsedTimer timer;
        timer.start();
        fm.elidedText(text, Qt::ElideRight, 1000); // Elide text to fit 1000 pixels
        qDebug() << i << len << timer.elapsed(); // Measure time taken
    }
}
