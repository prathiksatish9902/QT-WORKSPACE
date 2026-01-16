#ifndef LOGINHANDLER_H
#define LOGINHANDLER_H
#include <QObject>
#include <QDebug>
class LoginHandler : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString username READ getUsername WRITE setUsername NOTIFY usernameChanged FINAL)
    Q_PROPERTY(QString password READ getPassword WRITE setPassword NOTIFY passwordChanged FINAL)


public:
    explicit LoginHandler(QObject *parent = nullptr);
    ~LoginHandler();

    QString getUsername() const;
    void setUsername(const QString &newUsername);

    QString getPassword() const;
    void setPassword(const QString &newPassword);

public slots:
    void onUserNameChanged();
    void onPasswordChanged();

signals:

    void usernameChanged();

    void passwordChanged();

private:
    QString m_username;
    QString m_password;
};

#endif // LOGINHANDLER_H
