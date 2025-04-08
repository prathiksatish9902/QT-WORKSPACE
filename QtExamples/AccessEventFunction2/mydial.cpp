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
    return true;
}

void MyDial::paintEvent(QPaintEvent *event)
{
    qDebug()<<"my dial paint event function called";

}
