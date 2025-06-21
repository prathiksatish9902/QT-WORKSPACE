#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QFile file("example.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Cannot open file for reading";
        return -1;
    }

    QTextStream in(&file);

    // This works in Qt 5
    in.setCodec("UTF-8");

    while (!in.atEnd()) {
        QString line = in.readLine();
        qDebug() << line;
    }
    file.close();
    return 0;
}
