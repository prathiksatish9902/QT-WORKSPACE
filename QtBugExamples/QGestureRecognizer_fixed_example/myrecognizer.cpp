#include "myrecognizer.h"



QGesture *MyRecognizer::create(QObject *target) {
    Q_UNUSED(target)
    return new QGesture();
}

void MyRecognizer::reset(QGesture *gesture) {
    Q_UNUSED(gesture)
}

QGestureRecognizer::Result MyRecognizer::recognize(QGesture *gesture, QObject *watched, QEvent *event) {
    Q_UNUSED(gesture)
    Q_UNUSED(watched)
    Q_UNUSED(event)
    return QGestureRecognizer::Ignore;
}

MyRecognizer::~MyRecognizer() {
    qDebug() << "MyRecognizer deleted";
}
