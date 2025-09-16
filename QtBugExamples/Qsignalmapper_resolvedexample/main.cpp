#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QDebug>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QWidget window;
    QVBoxLayout *layout = new QVBoxLayout(&window);

    QStringList texts = {"One", "Two", "Three"};

    for (int i = 0; i < texts.size(); ++i) {
        QPushButton *button = new QPushButton(texts[i]);
        layout->addWidget(button);

        QObject::connect(button, &QPushButton::clicked, [=]() {
            qDebug() << "Button clicked:" << texts[i];
        });
    }

    window.show();
    return app.exec();
}
