#ifndef BOOKINGDATE_H
#define BOOKINGDATE_H

#include <QString>

class BookingDate
{
public:
    BookingDate(int day, int month, int year);
    ~BookingDate();

    void SetDay(int day);
    int GetDay() const;

    void SetMonth(int month);
    int GetMonth() const;

    void SetYear(int year);
    int GetYear() const;

    QString ToString() const;

    bool operator<(const BookingDate &other) const;
    bool operator==(const BookingDate &other) const;

private:
    int m_day;
    int m_month;
    int m_year;
};

#endif // BOOKINGDATE_H
