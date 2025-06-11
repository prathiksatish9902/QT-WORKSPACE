
#include <QCoreApplication>
#include <QByteArray>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    // ❌ BUG: Incorrect usage of Qt::Initialization
    // This line will cause a compilation error
    QByteArray buffer(123, Qt::Initialization);  //QByteArray(int size, char fillChar); compiler is trying to match to this constructor


    qDebug() << "Buffer size:" << buffer.size();

    return 0;
}
