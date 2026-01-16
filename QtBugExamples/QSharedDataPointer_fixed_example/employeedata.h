#ifndef EMPLOYEEDATA_H
#define EMPLOYEEDATA_H
#include <QSharedData>
#include <QSharedDataPointer>
#include <QString>

class EmployeeData : public QSharedData
{
public:
    EmployeeData();

    EmployeeData(const EmployeeData &other);

    ~EmployeeData() = default;  // Modern way to define trivial destructor

    int id;
    QString name;
};

#endif // EMPLOYEEDATA_H
