#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "PathItem.h"
#include "PointGenerator.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    qmlRegisterType<PathItem>("CustomComponents", 1, 0, "PathItem");

    QQmlApplicationEngine engine;
    PointGenerator pointGenerator;
    engine.rootContext()->setContextProperty("pointGenerator", &pointGenerator);
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
