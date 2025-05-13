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

    QString header = QString("%1 %2").arg(m_month).arg(year);
    int headerWidth = 49;
    int headerPadding = (headerWidth - header.length()) / 2;
    QString centeredHeader = QString("%1%2").arg(QString(headerPadding, ' ')).arg(header);

    qDebug().noquote() << "\n" << centeredHeader;
    qDebug().noquote() << QString(headerWidth, '-');

    qDebug().noquote() << "  Sun       Mon       Tue       Wed       Thu       Fri       Sat  ";

    int currentDay = 1;

    int weeksNeeded = (firstDay + daysInMonth + 6) / 7;

    for (int week = 0; week < weeksNeeded; week++) {
        QString line = "";

        for (int dayOfWeek = 0; dayOfWeek < 7; dayOfWeek++) {
            int dayPosition = week * 7 + dayOfWeek;
            int dayNumber = dayPosition - firstDay + 1;

            if (dayNumber < 1 || dayNumber > daysInMonth) {
                line += "         ";
            }
            else {
                int count = 0;
                if (bookingCounts && bookingCounts->count(dayNumber) > 0) {
                    count = bookingCounts->at(dayNumber);
                }

                QString dayDisplay;
                if (dayNumber < 10) {
                    dayDisplay = QString("   %1/%2    ").arg(dayNumber).arg(count);
                } else {
                    dayDisplay = QString("  %1/%2    ").arg(dayNumber).arg(count);
                }

                if (dayDisplay.length() > 9) {
                    dayDisplay = dayDisplay.left(9);
                } else while (dayDisplay.length() < 9) {
                        dayDisplay += " ";
                    }

                line += dayDisplay;
            }
        }

        qDebug().noquote() << line;
    }
}

int Month::GetFirstDayOfMonth(int month, int year) const {
    if (month < 3) {
        month += 12;
        year--;
    }

    int k = year % 100;
    int j = year / 100;

    int dayOfWeek = (1 + ((13 * (month + 1)) / 5) + k + (k / 4) + (j / 4) - (2 * j)) % 7;

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
    return 1;
}
