#include "employee.h"

Employee::Employee() : d(new EmployeeData) { }

Employee::Employee(int id, const QString &name)
    : d(new EmployeeData)
{
    setId(id);
    setName(name);
}

void Employee::setId(int id) { d->id = id; }

void Employee::setName(const QString &name) { d->name = name; }

int Employee::id() const { return d->id; }

QString Employee::name() const { return d->name; }
