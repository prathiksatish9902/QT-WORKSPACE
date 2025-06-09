#include "employee.h"

Employee::Employee():d(new EmployeeData) {
    std::cout<<"employee constructor 1 "<<std::endl;
}

Employee::Employee(const Employee &other)
    :d(other.d)
{
    std::cout<<"employee copy constructor 1 "<<std::endl;

}

Employee &Employee::operator=(const Employee &other)
{
    std::cout<<"employee copy assignment "<<std::endl;
    // return other;
}

void Employee::setName(const QString &n)
{
    d->m_name = n;
}

QString Employee::getName() const
{
    return d->m_name;
}
