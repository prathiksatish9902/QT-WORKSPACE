#ifndef TESTCALCULATOR_H
#define TESTCALCULATOR_H
#include "calculator.h"
#include <QtTest/QTest>
class TestCalculator : public QObject
{
    Q_OBJECT
public:
    // explicit TestCalculator(QObject *parent = nullptr);
    // TestCalculator();
    // ~TestCalculator();

signals:
private slots:
    void testAdd();
    void testSubtract();
    void testMultiply();
    void testDivide();
    void testDivideByZero();
};
#endif // TESTCALCULATOR_H
