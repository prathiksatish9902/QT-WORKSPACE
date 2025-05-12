#include "bookingdate.h"

BookingDate::BookingDate(int day, int month, int year) : m_day(day), m_month(month), m_year(year) {
}

BookingDate::~BookingDate() {
}

void BookingDate::SetDay(int day) {
    m_day = day;
}

int BookingDate::GetDay() const {
    return m_day;
}

void BookingDate::SetMonth(int month) {
    m_month = month;
}

int BookingDate::GetMonth() const {
    return m_month;
}

void BookingDate::SetYear(int year) {
    m_year = year;
}

int BookingDate::GetYear() const {
    return m_year;
}

QString BookingDate::ToString() const {
    return QString("%1/%2/%3").arg(m_day).arg(m_month).arg(m_year);
}

bool BookingDate::operator<(const BookingDate &other) const {
    if (m_year != other.m_year)
        return m_year < other.m_year;
    if (m_month != other.m_month)
        return m_month < other.m_month;
    return m_day < other.m_day;
}

bool BookingDate::operator==(const BookingDate &other) const {
    return m_day == other.m_day &&
           m_month == other.m_month &&
           m_year == other.m_year;
}
