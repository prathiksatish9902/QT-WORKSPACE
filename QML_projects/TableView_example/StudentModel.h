#ifndef STUDENTMODEL_H
#define STUDENTMODEL_H

#include <QAbstractListModel>
#include <QObject>
#include <QList>
#include "Student.h"
class StudentModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(QList<Student> studentList READ getStudentList WRITE setStudentList NOTIFY studentListChanged FINAL)

public:
    StudentModel(QObject *parent = nullptr);
    ~StudentModel();

    QList<Student> getStudentList() const;
    void setStudentList(const QList<Student> &newStudentList);

signals:
    void studentListChanged();

private:
    QList<Student> m_studentList;

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    enum StudentRoles
    {
        NameRole = Qt::UserRole + 1,
        AgeRole,
        GradeRole
    };
};

#endif // STUDENTMODEL_H
