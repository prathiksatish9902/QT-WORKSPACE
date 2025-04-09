#include "mydial.h"

MyDial::MyDial() {
    qDebug()<<"my dial constructor called";
}

MyDial::~MyDial()
{
    qDebug()<<"my dial destructor called";

}

bool MyDial::event(QEvent *e)
{
    qDebug()<<"my dial event function called";
    return QDial::event(e);
;
}

void MyDial::paintEvent(QPaintEvent *event)
{
    qDebug()<<"my dial paint event function called";
    QDial::paintEvent(event);

}
