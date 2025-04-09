#include "mycheckbox.h"

MyCheckBox::MyCheckBox() {
    qDebug()<<"my checkbox constructor called";
}

MyCheckBox::~MyCheckBox()
{
    qDebug()<<"my checkbox destructor called";

}

bool MyCheckBox::event(QEvent *e)
{
    qDebug()<<"my checkbox event function called";
    return QCheckBox::event(e);
}

void MyCheckBox::paintEvent(QPaintEvent *event)
{
    qDebug()<<"my checkbox paint event function called";
    QCheckBox::paintEvent(event);
}
