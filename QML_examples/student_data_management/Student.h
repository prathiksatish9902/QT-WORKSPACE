#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>
#include <QDebug>
class Student : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString studentname READ getStudentname WRITE setStudentname NOTIFY StudentnameChanged)
    Q_PROPERTY(QString studentContactNumber READ getStudentContactNumber WRITE setStudentCotactNumber NOTIFY StudentContactNumberChanged)
    Q_PROPERTY(QString fathername READ getFatherName WRITE setFatherName NOTIFY FathernameChanged)
    Q_PROPERTY(QString mailId READ getMailId WRITE setMailId NOTIFY MailIdChanged)
    Q_PROPERTY(QString username READ getUserName WRITE setUserName NOTIFY UsernameChanged)
    Q_PROPERTY(QString password READ getPassword WRITE setPassword NOTIFY PasswordChanged)

public:
    explicit Student(QObject *parent = nullptr);
    Student(const QString &studentName , const QString &mobileNumber , const QString &fatherName , const QString &mailId , const QString &userName , const QString &password , QObject *parent = nullptr);
    ~Student();
    QString getStudentName() const;
    void setStudentName(const QString &newStudentName);

    QString getStudentContactNumber() const;
    void setStudentCotactNumber(const QString &newStudentCotactNumber);

    QString getFatherName() const;
    void setFatherName(const QString &newFatherName);

    QString getMailId() const;
    void setMailId(const QString &newMailId);

    QString getUserName() const;
    void setUserName(const QString &newUserName);

    QString getPassword() const;
    void setPassword(const QString &newPassword);

signals:
    void StudentnameChanged();
    void StudentContactNumberChanged();
    void FathernameChanged();
    void MailIdChanged();
    void UsernameChanged();
    void PasswordChanged();

private:
    QString m_studentName;
    QString m_studentCotactNumber;
    QString m_fatherName;
    QString m_mailId;
    QString m_userName;
    QString m_password;
};

#endif // STUDENT_H
