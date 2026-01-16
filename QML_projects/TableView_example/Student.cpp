#include "Student.h"

Student::Student(QString studentName, int studentAge, QString studentGrade)
{
    qDebug()<<Q_FUNC_INFO;
    m_studentName = studentName;
    m_studentAge = studentAge;
    m_studentGrade = studentGrade;
}

Student::~Student()
{
    qDebug()<<Q_FUNC_INFO;
}

QString Student::getStudentName() const
{
    return m_studentName;
}

void Student::setStudentName(const QString &newStudentName)
{
    qDebug()<<Q_FUNC_INFO;
    m_studentName = newStudentName;
}

int Student::getStudentAge() const
{
    return m_studentAge;
}

void Student::setStudentAge(int newStudentAge)
{
    qDebug()<<Q_FUNC_INFO;
    m_studentAge = newStudentAge;
}

QString Student::getStudentGrade() const
{
    return m_studentGrade;
}

void Student::setStudentGrade(const QString &newStudentGrade)
{
    qDebug()<<Q_FUNC_INFO;
    m_studentGrade = newStudentGrade;
}

bool Student::operator==(const Student &other) const
{
    qDebug()<<Q_FUNC_INFO;
    return m_studentName == other.m_studentName &&
           m_studentAge == other.m_studentAge &&
           m_studentGrade == other.m_studentGrade;
}
