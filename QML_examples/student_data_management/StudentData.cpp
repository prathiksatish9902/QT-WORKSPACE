#include "StudentData.h"

// StudentData::StudentData(QObject *parent)
//     : QObject{parent}
// {
//     // m_loginAttempts = 0;
// }

StudentData::StudentData()
{

}

StudentData::~StudentData()
{

}

void StudentData::addStudent(const QString &studentName, const QString &mobileNumber, const QString &fatherName, const QString &mailId, const QString &userName, const QString &password)
{
    Student *student = new Student(studentName , mobileNumber , fatherName , mailId , userName , password , this);
    m_studentDataList.append(student);
    qDebug() << "Student added:" <<studentName<< userName << password;

}

bool StudentData::isEmpty()
{
    return m_studentDataList.empty();
}

bool StudentData::authenticate(const QString &userName, const QString &password)
{
    if (m_studentDataList.isEmpty())
    {
        emit redirectToSignup();
        return false;
    }

    for (auto &student : m_studentDataList)
    {
        if (student->getUserName() == userName && student->getPassword() == password)
        {
            emit loginSuccess();
            qDebug() << "Login successful. Student data is stored.";
            return true;
        }
        else
        {
            emit loginFailed();

        }
    }
    return false;
}

int StudentData::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_studentDataList.size();
}

QVariant StudentData::data(const QModelIndex &index, int role) const
{
    const Student* student = m_studentDataList.at(index.row());

    switch(role)
    {
    case STUDENT_NAME:
        return student->getStudentName();

    case STUDENT_CONTACT_NUMBER:
        return student->getStudentContactNumber();

    case FATHER_NAME:
        return student->getFatherName();

    case MAIL_ID:
        return student->getMailId();

    case USERNAME:
        return student->getUserName();

    case PASSWORD:
        return student->getPassword();

    default:
        return QVariant();
    }
    return QVariant();
}

QHash<int, QByteArray> StudentData::roleNames() const
{
    QHash<int , QByteArray> l_roleNames;
    l_roleNames.insert(STUDENT_NAME , "studentName");
    l_roleNames.insert(STUDENT_CONTACT_NUMBER , "contactNumber");
    l_roleNames.insert(FATHER_NAME , "fatherName");
    l_roleNames.insert(MAIL_ID , "mailId");
    l_roleNames.insert(USERNAME , "userName");
    l_roleNames.insert(PASSWORD , "password");
    return l_roleNames;
}
