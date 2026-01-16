// #include <QApplication>
// #include <QPushButton>
// #include <QDebug>

// int main(int argc, char *argv[])
// {
//     QApplication app(argc, argv);

//     QWidget window;
//     window.setWindowTitle("Active Window Bug Demo");

//     QPushButton btn("Hide and Show", &window);
//     QObject::connect(&btn, &QPushButton::clicked, [&]() {
//         qDebug() << "Before hide:" << QApplication::activeWindow();
//         window.hide();
//         qDebug() << "After hide:" << QApplication::activeWindow();
//         window.show();
//         qDebug() << "After show:" << QApplication::activeWindow();
//     });

//     window.show();
//     return app.exec();
// }






#include <QApplication>
#include <QWindow>
#include <QPushButton>
#include <QDebug>
#include <QVBoxLayout>

class FixedWindow : public QWidget {
public:
    using QWidget::QWidget;
protected:
    void showEvent(QShowEvent *event) override {
        QWidget::showEvent(event);
        if (isWindow()) {
            QWindow *win = windowHandle();
            if (win && win->isActive())
                QApplication::setActiveWindow(this);
        }
    }
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Main window
    FixedWindow window;
    window.setWindowTitle("Main Window");

    QPushButton btn("Hide and Show", &window);
    QVBoxLayout layout(&window);
    layout.addWidget(&btn);

    // Second independent window
    QPushButton btn2("Second Window");
    btn2.setWindowTitle("Second Window");
    btn2.show();

    // Test sequence
    QObject::connect(&btn, &QPushButton::clicked, [&]() {
        qDebug() << "Before hide:" << QApplication::activeWindow();
        window.hide();
        qDebug() << "After hide:" << QApplication::activeWindow();
        btn2.raise(); // bring second window to front
        btn2.activateWindow();
        qDebug() << "After activating second:" << QApplication::activeWindow();
        window.show();
        qDebug() << "After show:" << QApplication::activeWindow();
    });

    window.show();
    return app.exec();
}
