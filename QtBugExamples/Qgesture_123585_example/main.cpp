#include <QApplication>
#include <QGestureRecognizer>
#include <QGesture>
#include <QDebug>

class DummyRecognizer : public QGestureRecognizer {
public:
    DummyRecognizer() { qDebug() << "DummyRecognizer created"; }
    ~DummyRecognizer() override { qDebug() << "DummyRecognizer destroyed"; }

    QGesture* create(QObject* target) override { return new QGesture(target); }
    QGestureRecognizer::Result recognize(QGesture*, QObject*, QEvent*) override { return Ignore; }
    void reset(QGesture*) override {}
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Qt::GestureType type = QGestureRecognizer::registerRecognizer(new DummyRecognizer);

    Qt::GestureType mytype = QGestureRecognizer::registerRecognizer(new DummyRecognizer);
    QGestureRecognizer::unregisterRecognizer(mytype);
    QGestureRecognizer::unregisterRecognizer(type);
    QGestureRecognizer::unregisterRecognizer(type);


    qDebug() << "Recognizer unregistered";

    return 0;
}
