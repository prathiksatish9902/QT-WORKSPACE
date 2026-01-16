#ifndef STUDENTDATA_H
#define STUDENTDATA_H

#include <QObject>
#include <QAbstractListModel>
#include <QVariant>
#include <QDebug>
#include <QList>
#include "Student.h"
class StudentData : public QAbstractListModel
{
    Q_OBJECT
public:
    // explicit StudentData(QObject *parent = nullptr);
    StudentData();
    ~StudentData();

    Q_INVOKABLE void addStudent(const QString &studentName , const QString &mobileNumber , const QString &fatherName , const QString &mailId , const QString &userName , const QString &password);
    Q_INVOKABLE bool isEmpty();
    Q_INVOKABLE bool authenticate(const QString &userName , const QString &password);

signals:

    void loginSuccess();
    void loginFailed();
    // void loginAttemptsExceeded();
    void redirectToSignup();

private:
    QList <Student *> m_studentDataList;

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;


    enum StudentDataModel
    {
        STUDENT_NAME = 1,
        STUDENT_CONTACT_NUMBER,
        FATHER_NAME,
        MAIL_ID,
        USERNAME,
        PASSWORD
    };
};

#endif // STUDENTDATA_H
