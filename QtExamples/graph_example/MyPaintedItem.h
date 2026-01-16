#ifndef MYPAINTEDITEM_H
#define MYPAINTEDITEM_H

#include <QQuickPaintedItem>
#include <QPen>
class MyPaintedItem : public QQuickPaintedItem
{
public:
    MyPaintedItem();
    ~MyPaintedItem();
protected:
    void paint(QPainter *painter);
private:
    QPen *m_mypen;
};

#endif // MYPAINTEDITEM_H
