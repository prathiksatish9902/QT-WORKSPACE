#ifndef YEAR_H
#define YEAR_H

#include <map>
#include <string>
#include "month.h"

class Year
{
public:
    Year();
    Year(int year);
    ~Year();

    void SetYear(int year);
    int GetYear() const;

    void AddMonths();

    Month* GetCurrentMonth(int key) const;

private:
    int m_year;
    std::map<int, Month*> m_monthMap;
};

#endif // YEAR_H
