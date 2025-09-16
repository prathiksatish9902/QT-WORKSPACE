#include "CalculatorButton.h"


CalculatorButton::CalculatorButton(const QString &label, bool isOperator)
    : m_label(label), m_isOperator(isOperator) {}

QString CalculatorButton::label() const { return m_label; }

bool CalculatorButton::isOperator() const { return m_isOperator; }
