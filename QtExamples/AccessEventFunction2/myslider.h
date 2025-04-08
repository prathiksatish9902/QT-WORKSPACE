#ifndef MYSLIDER_H
#define MYSLIDER_H

#include <QSlider>
#include <QEvent>
#include <QPaintEvent>
class MySlider : public QSlider
{
public:
    MySlider();
    ~MySlider();

    bool event(QEvent *e) override;
    void paintEvent(QPaintEvent *event) override;


};

#endif // MYSLIDER_H
