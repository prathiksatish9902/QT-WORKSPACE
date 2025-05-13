#ifndef MONTH_H
#define MONTH_H

#include <QWidget>
#include <QString>
#include <QVector>
#include <map>

class Month
{
public:
    Month(const QString& month = "");
    ~Month();

    void SetMonth(const QString& month);
    QString GetMonth() const;

    void AddDates(int numDays = 30);
    int GetCurrentDate(int date) const;

    void PrintCalendar(int year, const std::map<int, int>* bookingCounts = nullptr) const;

private:
    QString m_month;
    QVector<int> m_dateList;

    int GetFirstDayOfMonth(int month, int year) const;
    int MonthToInt() const;
};

#endif // MONTH_H
