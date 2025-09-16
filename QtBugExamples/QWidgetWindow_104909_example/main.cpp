// #include <QApplication>
// #include <QWindow>
// #include <QExposeEvent>
// #include <QDebug>

// class MyWindow : public QWindow {
// protected:
//     void exposeEvent(QExposeEvent *event) override {
//         QRegion exposed = event->region();  // Warning in Qt 6+
//         qDebug() << "Exposed region:" << exposed;
//     }
// };

// int main(int argc, char **argv) {
//     QApplication app(argc, argv);
//     MyWindow window;
//     window.resize(300, 200);
//     window.show();
//     return app.exec();
// }





#include <QApplication>
#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QDebug>

class MyWidget : public QWidget {
protected:
    void paintEvent(QPaintEvent *event) override {
        QRegion exposed = event->region();
        QPainter painter(this);
        painter.fillRect(rect(), Qt::green);
        qDebug() << "Painted region:" << exposed;
    }
};

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    MyWidget widget;
    widget.resize(300, 200);
    widget.show();
    return app.exec();
}






















// #include <QApplication>
// #include <QWidget>
// #include <QPainter>
// #include <QPaintEvent>
// #include <QDebug>

// class MyWidget : public QWidget {
// public:
//     MyWidget() {
//         setWindowTitle("Bug Demo");
//         resize(400, 300);
//     }

// protected:
//     void paintEvent(QPaintEvent *event) override {
//         QPainter painter(this);
//         painter.fillRect(event->rect(), Qt::blue);
//         qDebug() << "Widget painting rect:" << event->rect() << "Region:" << event->region();
//     }
// };

// int main(int argc, char *argv[]) {
//     QApplication app(argc, argv);
//     MyWidget widget;
//     widget.show();
//     return app.exec();
// }
