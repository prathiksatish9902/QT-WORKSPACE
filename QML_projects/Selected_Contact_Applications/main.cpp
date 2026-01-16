#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "ContactDataModel.h"
#include "CallHistory.h"
#include "Phonebook.h"
#include "Whatsapp.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    ContactDataModel *phoneBookContactModel = new Phonebook;
    engine.rootContext()->setContextProperty("PhoneBookModel", phoneBookContactModel);
    ContactDataModel *callHistoryContactModel = new CallHistory;
    engine.rootContext()->setContextProperty("CallHistoryModel", callHistoryContactModel);
    ContactDataModel *whatsappContactModel = new Whatsapp;
    engine.rootContext()->setContextProperty("WhatsappModel", whatsappContactModel);
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
