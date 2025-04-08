#include "myspinbox.h"

MySpinBox::MySpinBox() {
    qDebug()<<"my spin box constructor called";

}

MySpinBox::~MySpinBox()
{
    qDebug()<<"my spin box destructor called";

}

bool MySpinBox::event(QEvent *e)
{
    qDebug()<<"my spinbox event function called";
    return true;
}

void MySpinBox::paintEvent(QPaintEvent *event)
{
    qDebug()<<"my slider paint event function called";

}
