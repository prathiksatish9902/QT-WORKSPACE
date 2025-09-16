#ifndef PATHITEM_H
#define PATHITEM_H

#include <QQuickPaintedItem>
#include <QPointF>
#include <QList>

class PathItem : public QQuickPaintedItem {
    Q_OBJECT
    Q_PROPERTY(QList<QPointF> points READ points WRITE setPoints NOTIFY pointsChanged)

public:
    explicit PathItem(QQuickItem *parent = nullptr);
    void paint(QPainter *painter) override;

    QList<QPointF> points() const;
    void setPoints(const QList<QPointF> &points);

signals:
    void pointsChanged();

private:
    QList<QPointF> m_points;
};

#endif // PATHITEM_H
