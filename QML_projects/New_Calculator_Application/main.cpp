#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "CalculatorViewModel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    CalculatorViewModel viewModel;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("viewModel", &viewModel);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
