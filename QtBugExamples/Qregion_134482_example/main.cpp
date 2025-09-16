#include <QApplication>
#include <QRegion>
#include <QRect>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QRegion region(QRect(0, 0, 100, 100)); // Region: a 100x100 square
    QRect rect(90, 90, 50, 50);            // Rectangle partly outside region

    qDebug() << "Expected full containment? No.";
    qDebug() << "QRegion::contains(rect):" << region.contains(rect); // BUG: prints true!

    return 0;
}
