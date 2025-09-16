#ifndef FIRSTCLASS_H
#define FIRSTCLASS_H

#include <QObject>
#include <QDebug>

class FirstClass : public QObject
{
    Q_OBJECT
public:
    explicit FirstClass(QObject *parent = nullptr);
    ~FirstClass();

    QString getapplicationName() const;
    void setApplicationName(const QString &newApplicationName);
signals:
    void signalEmitt();

private:
    QString m_applicationName;
};

#endif // FIRSTCLASS_H
