// #include <QGuiApplication>
// #include <QQuickView>

// int main(int argc, char **argv) {
//     QGuiApplication app(argc, argv);

//     QQuickView view;
//     view.setResizeMode(QQuickView::SizeRootObjectToView);

//     view.setInitialProperties({{"parent", QVariant::fromValue(view.contentItem())}});
//     view.setSource(QUrl("qrc:/main.qml"));
//     view.show();

//     return app.exec();
// }




// #include <QGuiApplication>
// #include <QQuickView>
// #include <QQmlEngine>  // For potential debugging

// int main(int argc, char *argv[]) {
//     QGuiApplication app(argc, argv);
//     QQuickView view;
//     view.setSource(QUrl("qrc:/main.qml"));  // Use resource path
//     view.show();
//     return app.exec();
// }





#include <QGuiApplication>
#include <QQuickView>
#include <QQuickItem>  // Required for QQuickItem meta-type
#include <QQmlEngine>  // For potential debugging
#include <QVariantMap>

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    QQuickView view;

    // Ensure QQuickItem is registered with the meta-type system
    qRegisterMetaType<QQuickItem*>();

    // Workaround: Set the parent property before loading QML
    QVariantMap initialProps;
    initialProps.insert("parent", QVariant::fromValue(view.contentItem()));
    view.setInitialProperties(initialProps);

    // Load QML file (use resource path to avoid file not found errors)
    view.setSource(QUrl("qrc:/main.qml"));  // Requires qml.qrc
    view.show();
    return app.exec();
}
