#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "LoginHandler.h"
int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);
    LoginHandler loginhandler;
    QQmlApplicationEngine engine;
    QQmlContext * context = engine.rootContext();
    // context->setProperty("lhandler" , &loginhandler);
    context->setContextProperty("lhandler" , &loginhandler);
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
