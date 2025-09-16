#include "PathItem.h"
#include <QPainter>
#include <QPen>

PathItem::PathItem(QQuickItem *parent) : QQuickPaintedItem(parent) {}

void PathItem::paint(QPainter *painter) {
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(QPen(Qt::blue, 2));
    if (m_points.size() < 2) return;

    for (int i = 0; i < m_points.size() - 1; ++i) {
        painter->drawLine(m_points[i], m_points[i + 1]);
    }
}

QList<QPointF> PathItem::points() const {
    return m_points;
}

void PathItem::setPoints(const QList<QPointF> &points) {
    m_points = points;
    emit pointsChanged();
    update();
}
