#ifndef CALENDERMANAGER_H
#define CALENDERMANAGER_H

#include <QWidget>
#include <QPushButton>
#include <map>
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

private:
    Calender *calender;
    std::map<int, Year*> m_yearsMap;

    Year* GetOrCreateYear(int year);
    void setupUI();
    void createButtons();

    QPushButton *nextMonthButton;
    QPushButton *previousMonthButton;
};

#endif // CALENDERMANAGER_H
