#include "date.h"

Date::Date() : m_day(1), m_month(1), m_year(2025) {
}

Date::Date(int day, int month, int year) : m_day(day), m_month(month), m_year(year) {
}

Date::~Date() {
}

void Date::SetDay(int day) {
    m_day = day;
}

int Date::GetDay() const {
    return m_day;
}

void Date::SetMonth(int month) {
    m_month = month;
}

int Date::GetMonth() const {
    return m_month;
}

void Date::SetYear(int year) {
    m_year = year;
}

int Date::GetYear() const {
    return m_year;
}

QString Date::ToString() const {
    return QString("%1/%2/%3").arg(m_day).arg(m_month).arg(m_year);
}
