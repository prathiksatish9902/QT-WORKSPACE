#include <QCoreApplication>
#include <QThread>
#include <QObject>
#include <QDebug>

class Worker : public QObject {
    Q_OBJECT
public:
    ~Worker() {
        qDebug() << "Worker destroyed";
    }
};

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    QThread* thread = new QThread;
    Worker* worker = new Worker;

    worker->moveToThread(thread);

    // ❌ MISGUIDED: Connecting destroyed instead of finished
    // QObject::connect(thread, &QThread::destroyed, worker, &QObject::deleteLater);
    QObject::connect(thread, &QThread::finished, worker, &QObject::deleteLater);

    thread->start();
    thread->quit();
    thread->wait();

    delete thread;

    return 0; // ❌ Worker is never deleted!
}

#include "main.moc"
