#include "month.h"
#include <QDebug>
#include <ctime>
#include <iomanip>

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
    int daysInMonth = m_dateList.size();
    int firstDay = GetFirstDayOfMonth(MonthToInt(), year);

    // Print month and year header in center
    QString header = QString("%1 %2").arg(m_month).arg(year);
    int headerPadding = (20 - header.length()) / 2;
    QString centeredHeader = QString("%1%2").arg(QString(headerPadding, ' ')).arg(header);
    qDebug().noquote() << "\n" << centeredHeader;
    qDebug().noquote() << "--------------------";
    qDebug().noquote() << "Sun Mon Tue Wed Thu Fri Sat";

    // Print leading spaces for the first week
    QString line = "";
    for (int i = 0; i < firstDay; i++) {
        line += "    ";  // 4 spaces for each empty cell
    }

    // Print days with booking counts
    for (int day = 1; day <= daysInMonth; day++) {
        // Get booking count for this day (0 if no bookings)
        int count = 0;
        if (bookingCounts && bookingCounts->count(day) > 0) {
            count = bookingCounts->at(day);
        }

        // Format as "day/count"
        QString dayStr = QString("%1/%2").arg(day).arg(count);

        // Add padding to maintain alignment (3 chars plus 1 space)
        line += dayStr.rightJustified(3) + " ";

        // If this is the last day of a week, print the line and reset
        if ((day + firstDay) % 7 == 0 || day == daysInMonth) {
            qDebug().noquote() << line;
            line = "";
        }
    }
}
int Month::GetFirstDayOfMonth(int month, int year) const {
    // Zeller's Congruence algorithm to find the day of week
    if (month < 3) {
        month += 12;
        year--;
    }

    int k = year % 100;
    int j = year / 100;

    int dayOfWeek = (1 + ((13 * (month + 1)) / 5) + k + (k / 4) + (j / 4) - (2 * j)) % 7;

    // Convert from Zeller's result (0 = Saturday) to Sunday = 0
    return (dayOfWeek + 6) % 7;
}

int Month::MonthToInt() const {
    if (m_month == "January") return 1;
    else if (m_month == "February") return 2;
    else if (m_month == "March") return 3;
    else if (m_month == "April") return 4;
    else if (m_month == "May") return 5;
    else if (m_month == "June") return 6;
    else if (m_month == "July") return 7;
    else if (m_month == "August") return 8;
    else if (m_month == "September") return 9;
    else if (m_month == "October") return 10;
    else if (m_month == "November") return 11;
    else if (m_month == "December") return 12;
    return 1; // Default to January if invalid
}


