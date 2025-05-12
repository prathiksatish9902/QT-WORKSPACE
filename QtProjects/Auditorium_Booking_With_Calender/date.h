#ifndef DATE_H
#define DATE_H

#include <QString>

class Date
{
public:
    Date();
    Date(int day, int month, int year);
    ~Date();

    void SetDay(int day);
    int GetDay() const;

    void SetMonth(int month);
    int GetMonth() const;

    void SetYear(int year);
    int GetYear() const;

    QString ToString() const;

private:
    int m_day;
    int m_month;
    int m_year;
};

#endif // DATE_H
