#include <QApplication>
#include <QPushButton>
#include <QSignalMapper>
#include <QVBoxLayout>
#include <QWidget>
#include"myclass.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QWidget window;
    QVBoxLayout *layout = new QVBoxLayout(&window);
    QSignalMapper *signalMapper = new QSignalMapper(&window);
    MyClass c;
    QStringList texts = {"One", "Two", "Three"};

    for (int i = 0; i < texts.size(); ++i) {
        QPushButton *button = new QPushButton(texts[i]);
        layout->addWidget(button);

        // ❌ This line causes a compile error!
        // QObject::connect(button, &QPushButton::clicked, &c, &MyClass::print);
        QObject::connect(button, &QPushButton::clicked, &c, qOverload<>(&MyClass::print));

        signalMapper->setMapping(button, i);
    }

    window.show();
    return app.exec();
}
