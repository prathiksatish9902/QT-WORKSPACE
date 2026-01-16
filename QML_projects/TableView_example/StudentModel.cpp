#include "StudentModel.h"

StudentModel::StudentModel(QObject *parent)
{
    qDebug()<<Q_FUNC_INFO;
}

StudentModel::~StudentModel()
{
    qDebug()<<Q_FUNC_INFO;
}

QList<Student> StudentModel::getStudentList() const
{
    return m_studentList;
}

void StudentModel::setStudentList(const QList<Student> &newStudentList)
{
    qDebug()<<Q_FUNC_INFO;
    if (m_studentList == newStudentList)
        return;
    m_studentList = newStudentList;
    emit studentListChanged();
}

int StudentModel::rowCount(const QModelIndex &parent) const
{
    qDebug()<<Q_FUNC_INFO;

}
