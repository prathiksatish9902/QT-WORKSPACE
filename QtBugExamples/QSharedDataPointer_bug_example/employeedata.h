#ifndef EMPLOYEEDATA_H
#define EMPLOYEEDATA_H
#include <QSharedDataPointer>
#include <QString>
#include <iostream>
class EmployeeData : public QSharedData
{
public:
    EmployeeData();
    QString m_name;
};

#endif // EMPLOYEEDATA_H
