#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "LoginCredential.h"
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    LoginCredential loginCredential;
    engine.rootContext()->setContextProperty("Login", &loginCredential);
    const QUrl url(QStringLiteral("qrc:/qml_loginpage/main.qml"));
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

    // LoginCredential *user = new LoginCredential;
    // user->setUserName("admin");
    // user->setPassword("admin");
    // user->checkLoginCredential("admin" , "admin");

    return app.exec();
}
