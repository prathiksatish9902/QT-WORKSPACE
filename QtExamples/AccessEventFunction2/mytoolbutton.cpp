#include "mytoolbutton.h"

MyToolButton::MyToolButton() {
    qDebug()<<"my tool button constructor called";
}

MyToolButton::~MyToolButton()
{
    qDebug()<<"my tool button destructor called";

}

bool MyToolButton::event(QEvent *e)
{
    qDebug()<<"my tool button event function called";
    return true;

}

void MyToolButton::paintEvent(QPaintEvent *event)
{
    qDebug()<<"my tool button paintevent function called";

}
