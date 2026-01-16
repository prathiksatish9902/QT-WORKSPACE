#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QObject>

class Calculator : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString display READ display NOTIFY displayChanged)

public:
    explicit Calculator(QObject *parent = nullptr);
    QString display() const;

public slots:
    void append(const QString &value);
    void clear();
    void evaluate();

signals:
    void displayChanged();

private:
    QString m_expression;
};

#endif // CALCULATOR_H
