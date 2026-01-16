#include "LoginHandler.h"

LoginHandler::LoginHandler(QObject *parent)
    : QObject{parent}
{
    qDebug()<<Q_FUNC_INFO;
    connect(this , &LoginHandler::usernameChanged , this , &LoginHandler::onUserNameChanged);
    connect(this , &LoginHandler::passwordChanged , this , &LoginHandler::onPasswordChanged);

}

LoginHandler::~LoginHandler()
{
    qDebug()<<Q_FUNC_INFO;

}

QString LoginHandler::getUsername() const
{
    return m_username;
}

void LoginHandler::setUsername(const QString &newUsername)
{
    if (m_username == newUsername)
        return;
    m_username = newUsername;
    emit usernameChanged();
}

QString LoginHandler::getPassword() const
{
    return m_password;
}

void LoginHandler::setPassword(const QString &newPassword)
{
    if (m_password == newPassword)
        return;
    m_password = newPassword;
    emit passwordChanged();
}

void LoginHandler::onUserNameChanged()
{
    qDebug()<<"userName :"<< m_username;
}

void LoginHandler::onPasswordChanged()
{
    qDebug()<<"password :"<< m_password;

}
