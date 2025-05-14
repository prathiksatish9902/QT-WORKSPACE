#ifndef CALENDARWIDGET_H
#define CALENDARWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QLineEdit>
#include <QTextEdit>
#include <vector>
#include <map>
#include <ctime>
#include <string>
#include <QDebug>
#include "auditoriummanagement.h"

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
    void addAuditorium();
    void displayAuditoriums();
    void bookAuditorium();

private:
    QPushButton *m_prevMonthButton;
    QPushButton *m_nextMonthButton;
    QPushButton *m_monthYearLabel;

    std::vector<QPushButton*> m_dayNameButtons;

    std::vector<QPushButton*> m_dayButtons;

    QPushButton *m_addAuditoriumButton;
    QPushButton *m_displayAuditoriumButton;
    QPushButton *m_bookAuditoriumButton;

    QLineEdit *m_bookingDateInput;
    QLineEdit *m_auditoriumIdInput;
    QTextEdit *m_outputDisplay;

    int m_currentMonth;
    int m_currentYear;

    int m_selectedDay;

    AuditoriumManagement m_auditoriumManagement;

    void setupUi();
    void updateCalendar();
    void clearDayButtons();
    int getDaysInMonth(int month, int year);
    int getFirstDayOfMonth(int month, int year);
    std::string getMonthName(int month);
};

#endif // CALENDARWIDGET_H





