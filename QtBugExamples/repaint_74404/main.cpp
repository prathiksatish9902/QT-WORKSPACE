#include <QApplication>
#include <QOpenGLWidget>
#include <QTimer>
#include <QDebug>
#include <thread>

class MyWidget : public QOpenGLWidget {
public:
    void paintGL() override {
        qDebug() << "paintGL called";
    }

    void triggerPaintFromThread() {
        std::thread([this]() {
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate loading
            qDebug() << "Thread: triggering repaint()";
            repaint(); // Expecting immediate paint
        }).detach();
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MyWidget w;
    w.resize(640, 480);
    w.show();

    QTimer::singleShot(1000, [&w]() {
        w.triggerPaintFromThread();
    });

    return app.exec();
}
