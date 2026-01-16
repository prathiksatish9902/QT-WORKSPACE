#ifndef LOGINHANDLER_H
#define LOGINHANDLER_H

#include <qobject.h>

class LoginHandler: public QObject
{
    Q_OBJECT

public:
    LoginHandler();
    ~LoginHandler();

private:
    QString m_userName;
    QString m_fatherName;
    QString m_password;
    QString m_email;
    int m_mobileNumber;
};

#endif // LOGINHANDLER_H
