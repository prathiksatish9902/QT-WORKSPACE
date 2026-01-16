#include "rectanglewidget.h"
#include <QPainter>

RectangleWidget::RectangleWidget(QWidget *parent)
    : QWidget(parent)
{
    rectangleToDraw = QRect(50, 50, 100, 80);
}

void RectangleWidget::setRectangle(int x, int y, int width, int height)
{
    rectangleToDraw = QRect(x, y, width, height);
    update();
}

void RectangleWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setPen(Qt::white);
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(rectangleToDraw);
}
