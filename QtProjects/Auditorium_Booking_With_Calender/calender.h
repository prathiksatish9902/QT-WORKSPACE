#ifndef CALENDER_H
#define CALENDER_H

#include <QList>
#include "year.h"

class Calender
{
public:
    Calender();
    ~Calender();

    void AddYear();
    Year* GetCurrentYear();

private:
    QList<Year*> m_yearList;
    Year *year;
};

#endif // CALENDER_H
