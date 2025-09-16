// Example: Multi-threaded translation usage
#include <QCoreApplication>
#include <QTranslator>
#include <QThread>
#include <QDebug>

QTranslator translator;

void translateInThread() {
    QString result = translator.translate("context", "hello");
    qDebug() << "Translated string in thread:" << result;
}

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    translator.load("app_en.qm");

    QThread t1, t2;
    QObject::connect(&t1, &QThread::started, translateInThread);
    QObject::connect(&t2, &QThread::started, translateInThread);

    t1.start();
    t2.start();

    t1.wait();
    t2.wait();

    return 0;
}
