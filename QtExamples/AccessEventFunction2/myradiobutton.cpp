#include "myradiobutton.h"

MyRadioButton::MyRadioButton() {
    qDebug()<<"my radio button constructor called";
}

MyRadioButton::~MyRadioButton()
{
    qDebug()<<"my radio button destructor called";

}

bool MyRadioButton::event(QEvent *e)
{
    qDebug()<<"my radio button event function called";
    return QRadioButton::event(e);
}

void MyRadioButton::paintEvent(QPaintEvent *event)
{
    qDebug()<<"my radio button paint event function called";
    QRadioButton::paintEvent(event);

}
