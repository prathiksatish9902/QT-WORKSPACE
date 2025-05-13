#ifndef CALENDERMANAGER_H
#define CALENDERMANAGER_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <map>
#include <QDate>
#include "calender.h"

class BookingDate;

class CalenderManager : public QWidget
{
    Q_OBJECT

public:
    CalenderManager(QWidget *parent = nullptr);
    ~CalenderManager();

    void GetCalenderYear();
    void GetCalenderMonth();
    void GetCalenderDate();
    void PrintMonthCalendar(int month, int year, std::map<BookingDate, std::list<std::string>>* bookingMap = nullptr);
    void NavigateCalendar(int &month, int &year, bool nextMonth, std::map<BookingDate, std::list<std::string>>* bookingMap = nullptr);

    int GetCurrentMonth() const;
    int GetCurrentYear() const;

private:
    Calender *calender;
    std::map<int, Year*> m_yearsMap;
    int m_currentMonth;
    int m_currentYear;

    Year* GetOrCreateYear(int year);
    void setupUI();
    void updateCalendarTitle();
    QString IntToMonthName(int month);

    QPushButton *nextMonthButton;
    QPushButton *previousMonthButton;
    QLabel *monthYearLabel;
};

#endif // CALENDERMANAGER_H
