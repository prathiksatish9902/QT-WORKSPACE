#ifndef LOGINCREDENTIAL_H
#define LOGINCREDENTIAL_H
#include <iostream>
#include <QObject>
#include <QString>
#include <QDebug>
#include <qqml.h>

using namespace std;

class LoginCredential : public QObject
{
    Q_OBJECT
    // QML_NAMED_ELEMENT(Login)

public:
    explicit LoginCredential(QObject *parent = nullptr);
    LoginCredential(QString userName , QString password);
    ~LoginCredential();

    QString getUserName();
    QString getPassword();

    void setUserName(QString userName);
    void setPassword(QString password);

   Q_INVOKABLE void checkLoginCredential(QString userName, QString password);

signals:
   void loginResult(QString);

private:
    QString m_userName;
    QString m_password;
};

#endif // LOGINCREDENTIAL_H
