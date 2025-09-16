#include "testcalculator.h"

// TestCalculator::TestCalculator(QObject *parent)
//     : QObject{parent}
// {}

// TestCalculator::TestCalculator()
// {

// }

// TestCalculator::~TestCalculator()
// {

// }

void TestCalculator::testAdd()
{
    Calculator calc;
    calc.add(5,5);

    QCOMPARE(c,10.0);
}

void TestCalculator::testSubtract()
{
    Calculator calc;
    QCOMPARE(calc.subtract(5,3),10.0);
}

void TestCalculator::testMultiply()
{
    Calculator calc;
    QCOMPARE(calc.multiply(5,3),15.0);
}

void TestCalculator::testDivide()
{
    Calculator calc;
    QCOMPARE(calc.divide(6,3),2.0);
}

void TestCalculator::testDivideByZero()
{
    Calculator calc;
    QCOMPARE(calc.divide(6,0),1);
}

QTEST_MAIN(TestCalculator)
// #include "testcalculator.moc"
