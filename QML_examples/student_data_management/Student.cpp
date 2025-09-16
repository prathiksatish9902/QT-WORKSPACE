#include "Student.h"

Student::Student(QObject *parent)
{

}

Student::Student(const QString &studentName, const QString &mobileNumber, const QString &fatherName, const QString &mailId, const QString &userName, const QString &password, QObject *parent)
{
    m_studentName = studentName;
    m_studentCotactNumber = mobileNumber;
    m_fatherName = fatherName;
    m_mailId = mailId;
    m_userName = userName;
    m_password = password;
}

Student::~Student()
{

}

QString Student::getStudentName() const
{
    return m_studentName;
}

void Student::setStudentName(const QString &newStudentName)
{
    m_studentName = newStudentName;
}

QString Student::getStudentContactNumber() const
{
    return m_studentCotactNumber;
}

void Student::setStudentCotactNumber(const QString &newStudentCotactNumber)
{
    m_studentCotactNumber = newStudentCotactNumber;
}

QString Student::getFatherName() const
{
    return m_fatherName;
}

void Student::setFatherName(const QString &newFatherName)
{
    m_fatherName = newFatherName;
}

QString Student::getMailId() const
{
    return m_mailId;
}

void Student::setMailId(const QString &newMailId)
{
    m_mailId = newMailId;
}

QString Student::getUserName() const
{
    return m_userName;
}

void Student::setUserName(const QString &newUserName)
{
    m_userName = newUserName;
}

QString Student::getPassword() const
{
    return m_password;
}

void Student::setPassword(const QString &newPassword)
{
    m_password = newPassword;
}
