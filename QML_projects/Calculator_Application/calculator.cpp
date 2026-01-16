#include "calculator.h"
#include <QJSEngine>

Calculator::Calculator(QObject *parent) : QObject(parent), m_expression("")
{
}

QString Calculator::display() const
{
    return m_expression;
}

void Calculator::append(const QString &value)
{
    m_expression += value;
    emit displayChanged();
}

void Calculator::clear()
{
    m_expression = "";
    emit displayChanged();
}

void Calculator::evaluate()
{
    QJSEngine engine;
    QJSValue result = engine.evaluate(m_expression);
    if (result.isError()) {
        m_expression = "Error";
    } else {
        m_expression = result.toString();
    }
    emit displayChanged();
}
