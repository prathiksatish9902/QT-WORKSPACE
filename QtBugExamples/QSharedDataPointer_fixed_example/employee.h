#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "employeedata.h"
class Employee
{
public:
    Employee();

    Employee(int id, const QString &name);

    // Use = default for copy/move constructor & assignment operators
    Employee(const Employee &other) = default;
    Employee &operator=(const Employee &other) = default;

    Employee(Employee &&other) = default;
    Employee &operator=(Employee &&other) = default;

    ~Employee() = default;

    void setId(int id);
    void setName(const QString &name);

    int id() const;
    QString name() const;

private:
    QSharedDataPointer<EmployeeData> d;
};


#endif // EMPLOYEE_H
