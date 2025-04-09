#include "myscrollbar.h"

MyScrollBar::MyScrollBar() {
    qDebug()<<"my scroll bar constructor called";
}

MyScrollBar::~MyScrollBar()
{
    qDebug()<<"my scroll bar destructor called";

}

bool MyScrollBar::event(QEvent *e)
{
    qDebug()<<"my scroll bar event function called";
    return QScrollBar::event(e);
}

void MyScrollBar::paintEvent(QPaintEvent *event)
{
    qDebug()<<"my scroll bar paint event function called";
    QScrollBar::paintEvent(event);

}
