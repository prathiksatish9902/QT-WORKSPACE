#ifndef STUDENT_H
#define STUDENT_H
#include <QDebug>
#include <QString>
class Student
{
public:
    Student(QString studentName , int studentAge , QString studentGrade);
    ~Student();

    QString getStudentName() const;
    void setStudentName(const QString &newStudentName);

    int getStudentAge() const;
    void setStudentAge(int newStudentAge);

    QString getStudentGrade() const;
    void setStudentGrade(const QString &newStudentGrade);

    bool operator== (const Student &other) const;

private:
    QString m_studentName;
    int m_studentAge;
    QString m_studentGrade;
};

#endif // STUDENT_H
