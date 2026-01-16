#ifndef CALCULATORVIEWMODEL_H
#define CALCULATORVIEWMODEL_H
#include <QAbstractListModel>
#include <QVector>
#include <QString>
#include "CalculatorButton.h"

class CalculatorViewModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(QString resultString READ resultString NOTIFY resultStringChanged)
    Q_PROPERTY(QString expressionString READ expressionString NOTIFY expressionStringChanged)
public:
    enum Roles {
        LabelRole = Qt::UserRole + 1,
        OperatorRole
    };

    explicit CalculatorViewModel(QObject *parent = nullptr);

    QString resultString() const;
    QString expressionString() const;

    // QAbstractListModel interface
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void keyPressed(int index);

signals:
    void resultStringChanged();
    void expressionStringChanged();

private:
    QString m_resultString;
    QString m_expressionString;
    QString m_currentInput;
    QString m_operator;
    double m_firstValue = 0;
    bool m_awaitOperand = false;

    QVector<CalculatorButton> m_buttons;

    void processNumber(const QString &num);
    void processOperator(const QString &op);
    void evaluate();
    void clear();
    void updateExpression(const QString &input = QString(), bool isEval = false);
    void processDecimal();
};

#endif // CALCULATORVIEWMODEL_H
