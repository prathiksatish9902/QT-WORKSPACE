#include "drawarea.h"
#include <QPainter>

DrawArea::DrawArea(QWidget *parent) : QWidget(parent), currentShape(None), penWidth(1), penColor(Qt::black), brushColor(Qt::white) {
    setMinimumSize(400, 400);
}

void DrawArea::setShape(ShapeType shape) {
    currentShape = shape;
    update();
}

void DrawArea::setPenWidth(int width) {
    penWidth = width;
    update();
}

void DrawArea::setPenColor(const QColor &color) {
    penColor = color;
    update();
}

void DrawArea::setBrushColor(const QColor &color) {
    brushColor = color;
    update();
}

DrawArea::ShapeType DrawArea::currentShapeType() const
{
    return currentShape;
}

void DrawArea::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setPen(QPen(penColor, penWidth));
    painter.setBrush(QBrush(brushColor));

    QRect rect(100, 100, 200, 200);

    switch (currentShape) {
    case Circle:
        painter.drawEllipse(rect);
        break;
    case Rectangle:
        painter.drawRect(100, 100, 300, 150);
        break;
    case Square:
        painter.drawRect(100, 100, 200, 200);
        break;
    case Pentagon: {
        QPolygon polygon;
        polygon << QPoint(200, 100) << QPoint(300, 160) << QPoint(260, 260)
                << QPoint(140, 260) << QPoint(100, 160);
        painter.drawPolygon(polygon);
        break;
    }
    case Line:
        painter.drawLine(100, 100, 300, 300);
        break;
    case CurvedLine: {
        QPainterPath path;
        path.moveTo(100, 200);
        path.cubicTo(150, 100, 250, 300, 300, 200);
        painter.drawPath(path);
        break;
    }
    default:
        break;
    }
}
