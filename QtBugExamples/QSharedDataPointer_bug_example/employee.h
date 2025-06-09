#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "employeedata.h"
class Employee
{
public:
    Employee();
    Employee(const Employee &other);
    Employee &operator=(const Employee &other);


    void setName(const QString &n);
    QString getName() const;
private:
    QSharedDataPointer<EmployeeData> d;
};

#endif // EMPLOYEE_H
