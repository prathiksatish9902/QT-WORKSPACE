#include "drawarea.h"
#include <QPainter>

DrawArea::DrawArea(QWidget *parent) : QWidget(parent), currentShape(ShapeType::None), penWidth(1), penColor(Qt::black), brushColor(Qt::white) {
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

void DrawArea::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setPen(QPen(penColor, penWidth));
    painter.setBrush(QBrush(brushColor));

    QRect rect(100, 100, 200, 200);

    switch (currentShape) {
    case ShapeType::Circle:
        painter.drawEllipse(rect);
        break;
    case ShapeType::Rectangle:
        painter.drawRect(100, 100, 300, 150); // width=300, height=150 for rectangle
        break;
    case ShapeType::Square:
        painter.drawRect(100, 100, 200, 200); // width=200, height=200 for square
        break;
    case ShapeType::Pentagon: {
        QPolygon polygon;
        polygon << QPoint(200, 100) << QPoint(300, 160) << QPoint(260, 260)
                << QPoint(140, 260) << QPoint(100, 160);
        painter.drawPolygon(polygon);
        break;
    }
    case ShapeType::Line:
        painter.drawLine(100, 100, 300, 300);
        break;
    case ShapeType::CurvedLine: {
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
