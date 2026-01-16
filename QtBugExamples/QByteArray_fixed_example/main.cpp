
#include <QCoreApplication>
#include <QByteArray>
#include <QDebug>
#include <cstring>  // for memset

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    // QByteArray buffer(123, Qt::Initialization::Uninitialized);
    QByteArray buffer(123, Qt::Uninitialized);

    // Optional: initialize the contents to 0
    memset(buffer.data(), 0, buffer.size());

    qDebug() << "Buffer size:" << buffer.size();
    qDebug() << "First byte (should be 0):" << static_cast<int>(buffer[0]);

    return 0;
}
