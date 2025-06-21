#ifndef MYRECOGNIZER_H
#define MYRECOGNIZER_H
#include <QGesture>
#include <QGestureRecognizer>
#include <QDebug>
class MyRecognizer : public QGestureRecognizer
{
public:
    QGesture *create(QObject *target) override;
    void reset(QGesture *gesture) override;
    QGestureRecognizer::Result recognize(QGesture *gesture, QObject *watched, QEvent *event) override ;

    ~MyRecognizer();
};

#endif // MYRECOGNIZER_H
