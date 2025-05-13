#ifndef DATEUTILS_H
#define DATEUTILS_H

#include <QString>
#include <QDate>

class DateUtils {
public:
    static bool isValidDate(int day, int month, int year);
    static QString formatDate(const QDate& date);
    static QDate getNextDate(const QDate& date);
    static QDate getPreviousDate(const QDate& date);
};

#endif // DATEUTILS_H
