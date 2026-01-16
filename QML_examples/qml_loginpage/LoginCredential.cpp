#include "LoginCredential.h"

LoginCredential::LoginCredential(QObject *parent)
    : QObject{parent}
{
    m_userName = "1";
    m_password = "1";
}

LoginCredential::LoginCredential(QString userName, QString password)
{
    m_userName = "1";
    m_password = "1";
}

LoginCredential::~LoginCredential()
{

}

QString LoginCredential::getUserName()
{
    return m_userName;
}

QString LoginCredential::getPassword()
{
    return m_password;
}

void LoginCredential::setUserName(QString userName)
{
    m_userName = userName;
}

void LoginCredential::setPassword(QString password)
{
    m_password = password;
}

void LoginCredential::checkLoginCredential(QString userName,QString password)
{
    qDebug()<<Q_FUNC_INFO;
    qDebug()<<userName<<password<<"\n"<<m_userName<<m_password;

    if("username :1" == userName && "password :1" == password)
    {
        qDebug()<<"Login success";
        emit loginResult("Login success");
    }
    else
    {
        qDebug()<<"Login not success";
        emit loginResult("Invalid Credential");
    }
}
