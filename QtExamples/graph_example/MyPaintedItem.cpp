#include "MyPaintedItem.h"
#include<QPainter>
#include<QPen>
#include<QPointF>
MyPaintedItem::MyPaintedItem() {
    qDebug()<<Q_FUNC_INFO;
    // m_mypen->setWidth(5);
}

MyPaintedItem::~MyPaintedItem()
{
    qDebug()<<Q_FUNC_INFO;
    delete m_mypen;

}

void MyPaintedItem::paint(QPainter *painter)
{
    qDebug()<<Q_FUNC_INFO;
    // m_mypen = new QPen();
    QPen pen("red");
    // m_mypen->setColor(Qt::red);
    painter->setPen(pen);
    painter->drawLine(100,50, 100, 300);
    // update();
}
