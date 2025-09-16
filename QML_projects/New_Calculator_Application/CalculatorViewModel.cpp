#include "CalculatorViewModel.h"

CalculatorViewModel::CalculatorViewModel(QObject *parent)
    : QAbstractListModel(parent),
    m_resultString("0"),
    m_expressionString("")
{
    QStringList labels = {
        "7", "8", "9", "/",
        "4", "5", "6", "*",
        "1", "2", "3", "-",
        "0", ".", "AC", "+",
        "="
    };
    for (const QString &l : labels) {
        bool op = (l == "+" || l == "-" || l == "*" || l == "/" || l == "=");
        m_buttons.append(CalculatorButton(l, op));
    }
}

QString CalculatorViewModel::resultString() const { return m_resultString; }
QString CalculatorViewModel::expressionString() const { return m_expressionString; }

int CalculatorViewModel::rowCount(const QModelIndex &) const { return m_buttons.size(); }
QVariant CalculatorViewModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() < 0 || index.row() >= m_buttons.size())
        return QVariant();

    const CalculatorButton &btn = m_buttons[index.row()];
    if (role == LabelRole)
        return btn.label();
    if (role == OperatorRole)
        return btn.isOperator();
    return QVariant();
}

QHash<int, QByteArray> CalculatorViewModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[LabelRole] = "label";
    roles[OperatorRole] = "isOperator";
    return roles;
}

void CalculatorViewModel::keyPressed(int index)
{
    QString label = m_buttons[index].label();

    if (label == "AC") {
        clear();
    } else if (label == "=") {
        evaluate();
    } else if (label == "+" || label == "-" || label == "*" || label == "/") {
        processOperator(label);
    } else if (label == ".") {
        processDecimal();
    } else {
        processNumber(label);
    }
    emit resultStringChanged();
    emit expressionStringChanged();
}

void CalculatorViewModel::processNumber(const QString &num)
{
    if (m_awaitOperand) {
        m_currentInput.clear();
        m_awaitOperand = false;
    }
    if (num == "0" && m_currentInput == "0")
        return;
    m_currentInput += num;
    m_resultString = m_currentInput;
    updateExpression(num);
}

void CalculatorViewModel::processDecimal()
{
    if (!m_currentInput.contains('.')) {
        if (m_currentInput.isEmpty())
            m_currentInput = "0";
        m_currentInput += ".";
        m_resultString = m_currentInput;
        updateExpression(".");
    }
}

void CalculatorViewModel::processOperator(const QString &op)
{
    if (!m_currentInput.isEmpty()) {
        m_firstValue = m_currentInput.toDouble();
        m_operator = op;
        m_awaitOperand = true;
        updateExpression(op);
    }
}

void CalculatorViewModel::evaluate()
{
    if (m_operator.isEmpty() || m_currentInput.isEmpty())
        return;

    double secondValue = m_currentInput.toDouble();
    double result = 0;

    if (m_operator == "+")
        result = m_firstValue + secondValue;
    else if (m_operator == "-")
        result = m_firstValue - secondValue;
    else if (m_operator == "*")
        result = m_firstValue * secondValue;
    else if (m_operator == "/")
        result = (secondValue == 0) ? 0 : m_firstValue / secondValue;

    m_resultString = QString::number(result, 'g', 10);
    updateExpression("=" + m_resultString, true);
    m_currentInput = QString::number(result, 'g', 10);
    m_operator.clear();
    m_awaitOperand = true;
}

void CalculatorViewModel::clear()
{
    m_resultString = "0";
    m_expressionString.clear();
    m_currentInput.clear();
    m_operator.clear();
    m_firstValue = 0;
    m_awaitOperand = false;
}

void CalculatorViewModel::updateExpression(const QString &input, bool isEval)
{
    if (isEval) {
        m_expressionString += input;
    } else {
        if (m_expressionString.isEmpty())
            m_expressionString = input;
        else
            m_expressionString += input;
    }
}
