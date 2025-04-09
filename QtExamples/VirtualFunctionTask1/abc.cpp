#include "abc.h"
#include <QDebug>
#include <QPaintEvent>

ABC::ABC(QWidget *parent)
    : QWidget{parent}
{
    qDebug() << "abc constructor called";
}

ABC::~ABC()
{
    qDebug() << "abc destructor called";
}

void ABC::paintEvent(QPaintEvent *event)
{
    qDebug() << "abc paint event function called";
    QWidget::paintEvent(event);
}
