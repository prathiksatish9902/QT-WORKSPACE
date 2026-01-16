#include "PointGenerator.h"
#include <QRandomGenerator>
#include <QTime>

PointGenerator::PointGenerator(QObject *parent) : QObject(parent) {}

void PointGenerator::generatePoints() {
    QList<QPointF> points;
    QList<double> zValues;
    QRandomGenerator generator(QTime::currentTime().msecsSinceStartOfDay());

    for (int i = 0; i < 2; ++i) {
        double x = generator.bounded(50, 750);
        double y = generator.bounded(50, 550);
        double z = generator.bounded(0, 100);
        points.append(QPointF(x, y));
        zValues.append(z);
    }
    emit pointsGenerated(points);
}
