#include "month.h"
#include <QDebug>
#include <ctime>

Month::Month(const QString& month) : m_month(month) {
    if (m_month == "January") AddDates(31);
    else if (m_month == "February") AddDates(28);
    else if (m_month == "March") AddDates(31);
    else if (m_month == "April") AddDates(30);
    else if (m_month == "May") AddDates(31);
    else if (m_month == "June") AddDates(30);
    else if (m_month == "July") AddDates(31);
    else if (m_month == "August") AddDates(31);
    else if (m_month == "September") AddDates(30);
    else if (m_month == "October") AddDates(31);
    else if (m_month == "November") AddDates(30);
    else if (m_month == "December") AddDates(31);
}

Month::~Month() {
}

void Month::SetMonth(const QString& month) {
    m_month = month;
}

QString Month::GetMonth() const {
    return m_month;
}

void Month::AddDates(int numDays) {
    m_dateList.clear();
    for (int i = 1; i <= numDays; i++) {
        m_dateList.push_back(i);
    }
}

int Month::GetCurrentDate(int date) const {
    if (date > 0 && date <= m_dateList.size()) {
        return m_dateList[date - 1];
    }
    return -1; // Invalid date
}

void Month::PrintCalendar(int year, const std::map<int, int>* bookingCounts) const {
    // Implementation for printing the calendar
}

int Month::GetFirstDayOfMonth(int month, int year) const {
    struct tm timeinfo = {0};
    timeinfo.tm_year = year - 1900;
    timeinfo.tm_mon = month - 1;
    timeinfo.tm_mday = 1;

    mktime(&timeinfo);
    return timeinfo.tm_wday;
}
