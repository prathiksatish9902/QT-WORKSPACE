#include <QGuiApplication>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QDebug>

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    QQmlEngine engine;

    engine.addImportPath("/home/prathik/Qt-SrcCode/qt-bugfix/qml/QtQuick");
    engine.addImportPath("/home/prathik/Qt-SrcCode/qt-bugfix/qml/QtQuick/Dialogs");

    QQmlComponent component(&engine, "main.qml");
    if (component.isError()) {
        const auto errors = component.errors();
        for (const auto &err : errors)
            qWarning() << err;
        return -1;
    }
    QObject *obj = component.create();
    if (!obj) {
        qWarning() << "Failed to create component instance.";
        const auto errors = component.errors();
        for (const auto &err : errors)
            qWarning() << err;
        return -1;
    }

    return app.exec();
}
