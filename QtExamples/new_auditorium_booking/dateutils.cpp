#include "dateutils.h"
#include <QDate>
#include <QString>

bool isValidDate(int day, int month, int year) {
    QDate date(year, month, day);
    return date.isValid();
}

QString formatDate(int day, int month, int year) {
    QDate date(year, month, day);
    return date.toString("dd/MM/yyyy");
}

QDate getNextDate(const QDate& date) {
    return date.addDays(1);
}

QDate getPreviousDate(const QDate& date) {
    return date.addDays(-1);
}
