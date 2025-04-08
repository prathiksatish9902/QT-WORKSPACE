#include "myslider.h"

MySlider::MySlider() {
    qDebug()<<"my slider constructor called";
}

MySlider::~MySlider()
{
    qDebug()<<"my slider destructor called";

}

bool MySlider::event(QEvent *e)
{
    qDebug()<<"my slider event function called";
    return true;
}

void MySlider::paintEvent(QPaintEvent *event)
{
    qDebug()<<"my slider paint event function called";

}
