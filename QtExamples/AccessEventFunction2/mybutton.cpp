#include "mybutton.h"
#include <QDebug>
MyButton::MyButton() {
    qDebug()<<"my button constructor called";
}


MyButton::~MyButton()
{
    qDebug()<<"my button destructor called";

}

bool MyButton::event(QEvent *e)
{
    qDebug()<<"my button event function called";
    return QPushButton::event(e);
}

void MyButton::paintEvent(QPaintEvent *event)
{
    qDebug()<<"my button paint event function called";
    QPushButton::paintEvent(event);
}

