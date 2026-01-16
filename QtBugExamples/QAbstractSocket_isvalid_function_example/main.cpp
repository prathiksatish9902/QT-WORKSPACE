#include "widget.h"
#include <QCoreApplication>
#include <QTcpSocket>
#include <QDebug>

int main(int argc, char *argv[])
{



    QCoreApplication app(argc, argv);

    QTcpSocket socket;

    socket.connectToHost("example.com", 80);

    if (socket.waitForConnected(3000)) {
        qDebug() << "Connected.";
    } else {
        qDebug() << "Failed to connect:" << socket.errorString();
        return -1;
    }

    socket.disconnectFromHost();

    if (socket.state() != QAbstractSocket::UnconnectedState) {
        socket.waitForDisconnected(3000);
    }

    qDebug() << "\nAfter disconnect:";
    qDebug() << "isValid:" << socket.isValid();
    qDebug() << "state:" << socket.state();

    return 0;
    // return app.exec();
}
