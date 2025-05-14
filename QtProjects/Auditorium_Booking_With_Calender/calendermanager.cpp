#include "calendermanager.h"
#include "calender.h"
#include "year.h"
#include "month.h"
#include "bookingdate.h"
#include <QDebug>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

CalenderManager::CalenderManager(QWidget *parent) : QWidget(parent) {
    calender = new Calender();
    m_currentMonth = QDate::currentDate().month();
    m_currentYear = QDate::currentDate().year();
    setupUI();
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
    m_currentMonth = month;
    m_currentYear = year;

    qDebug().noquote() << "\n=========================";
    QString monthName = IntToMonthName(month);
    qDebug().noquote() << QString("Displaying calendar for: %1 %2").arg(monthName).arg(year);
    qDebug().noquote() << "=========================";

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

            qDebug().noquote() << "\nNavigation:";
            qDebug().noquote() << "- Use 'Next Month' to view the next month";
            qDebug().noquote() << "- Use 'Previous Month' to view the previous month";
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

int CalenderManager::GetCurrentMonth() const
{
    return m_currentMonth;
}

int CalenderManager::GetCurrentYear() const
{
    return m_currentYear;
}

void CalenderManager::setupUI() {
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QLabel *calendarTitle = new QLabel(this);
    calendarTitle->setText(QString("%1 %2").arg(IntToMonthName(m_currentMonth)).arg(m_currentYear));
    calendarTitle->setAlignment(Qt::AlignCenter);
    calendarTitle->setStyleSheet("font-size: 16pt; font-weight: bold;");
    mainLayout->addWidget(calendarTitle);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    previousMonthButton = new QPushButton("Previous Month", this);
    nextMonthButton = new QPushButton("Next Month", this);

    buttonLayout->addStretch();
    buttonLayout->addWidget(previousMonthButton);
    buttonLayout->addWidget(nextMonthButton);
    buttonLayout->addStretch();

    mainLayout->addLayout(buttonLayout);

    connect(previousMonthButton, &QPushButton::clicked, this, [this]() {
        NavigateCalendar(m_currentMonth, m_currentYear, false);
        updateCalendarTitle();
    });

    connect(nextMonthButton, &QPushButton::clicked, this, [this]() {
        NavigateCalendar(m_currentMonth, m_currentYear, true);
        updateCalendarTitle();
    });

    setLayout(mainLayout);
    resize(400, 200);
    setWindowTitle("Calendar Navigation");
}

void CalenderManager::updateCalendarTitle() {
    // This would update the calendar title if we were using a GUI calendar
    // In our console-based implementation, the title is printed within PrintMonthCalendar
}

QString CalenderManager::IntToMonthName(int month) {
    switch (month) {
    case 1: return "January";
    case 2: return "February";
    case 3: return "March";
    case 4: return "April";
    case 5: return "May";
    case 6: return "June";
    case 7: return "July";
    case 8: return "August";
    case 9: return "September";
    case 10: return "October";
    case 11: return "November";
    case 12: return "December";
    default: return "Unknown";
    }
}
