#ifndef CALENDARWIDGET_H
#define CALENDARWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <vector>
#include <map>
#include <ctime>
#include <string>
#include <QDebug>

class CalendarWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CalendarWidget(QWidget *parent = nullptr);
    ~CalendarWidget();

public slots:
    void nextMonth();
    void previousMonth();
    void dayClicked();

private:
    // Navigation buttons
    QPushButton *m_prevMonthButton;
    QPushButton *m_nextMonthButton;
    QPushButton *m_monthYearLabel;

    // Day name buttons (Su, Mo, Tu, etc.)
    std::vector<QPushButton*> m_dayNameButtons;

    // Calendar day buttons
    std::vector<QPushButton*> m_dayButtons;

    // Current month and year
    int m_currentMonth;
    int m_currentYear;

    // Selected date if any
    int m_selectedDay;

    // Methods
    void setupUi();
    void updateCalendar();
    void clearDayButtons();
    int getDaysInMonth(int month, int year);
    int getFirstDayOfMonth(int month, int year);
    std::string getMonthName(int month);
};

#endif // CALENDARWIDGET_H
