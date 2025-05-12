#include "calendermanager.h"
#include "calender.h"
#include "year.h"
#include "month.h"
#include "bookingdate.h"

CalenderManager::CalenderManager(QWidget *parent) : QWidget(parent) {
    calender = new Calender();
}

CalenderManager::~CalenderManager() {
    delete calender;
    for (auto& pair : m_yearsMap) {
        delete pair.second;
    }
}

void CalenderManager::GetCalenderYear() {
    calender->GetCurrentYear();
    GetCalenderMonth();
}

void CalenderManager::GetCalenderMonth() {
    GetCalenderDate();
}

void CalenderManager::GetCalenderDate() {
    Year *y = calender->GetCurrentYear();
    Month *m = y->GetCurrentMonth(4);
    if (m) {
        int currentdate = m->GetCurrentDate(28);
    } else {
        qDebug() << "Month not found!";
    }
}

Year* CalenderManager::GetOrCreateYear(int year) {
    auto it = m_yearsMap.find(year);
    if (it != m_yearsMap.end()) {
        return it->second;
    }

    Year* newYear = new Year(year);
    m_yearsMap[year] = newYear;
    return newYear;
}

void CalenderManager::PrintMonthCalendar(int month, int year, std::map<BookingDate, std::list<std::string>> *bookingMap) {
    Year *y = GetOrCreateYear(year);
    if (y) {
        Month *m = y->GetCurrentMonth(month);
        if (m) {
            std::map<int, int> bookingCounts;
            if (bookingMap != nullptr) {
                for (const auto& pair : *bookingMap) {
                    const BookingDate& date = pair.first;
                    if (date.GetMonth() == month && date.GetYear() == year) {
                        bookingCounts[date.GetDay()] = pair.second.size();
                    }
                }
            }
            m->PrintCalendar(year, &bookingCounts);
        } else {
            qDebug() << "Month not found!";
        }
    } else {
        qDebug() << "Year not found!";
    }
}

void CalenderManager::NavigateCalendar(int &month, int &year, bool nextMonth, std::map<BookingDate, std::list<std::string>> *bookingMap) {
    if (nextMonth) {
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    } else {
        month--;
        if (month < 1) {
            month = 12;
            year--;
        }
    }

    PrintMonthCalendar(month, year, bookingMap);
}
