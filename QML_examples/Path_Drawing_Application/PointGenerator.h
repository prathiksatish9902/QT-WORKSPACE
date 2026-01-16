#ifndef POINTGENERATOR_H
#define POINTGENERATOR_H

#include <QObject>
#include <QPointF>
#include <QList>

class PointGenerator : public QObject {
    Q_OBJECT
public:
    explicit PointGenerator(QObject *parent = nullptr);

public slots:
    void generatePoints();

signals:
    void pointsGenerated(const QList<QPointF> &points);
};

#endif // POINTGENERATOR_H
