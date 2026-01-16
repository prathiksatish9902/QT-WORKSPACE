#ifndef CALCULATORBUTTON_H
#define CALCULATORBUTTON_H
#include <QString>

class CalculatorButton
{
public:
    CalculatorButton(const QString &label = "", bool isOperator = false);

    QString label() const;
    bool isOperator() const;

private:
    QString m_label;
    bool m_isOperator;
};

#endif // CALCULATORBUTTON_H
