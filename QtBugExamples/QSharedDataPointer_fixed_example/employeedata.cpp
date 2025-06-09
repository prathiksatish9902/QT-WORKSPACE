#include "employeedata.h"

// EmployeeData::EmployeeData() {}

EmployeeData::EmployeeData() : id(-1) { }

EmployeeData::EmployeeData(const EmployeeData &other)
    : QSharedData(other), id(other.id), name(other.name) { }
