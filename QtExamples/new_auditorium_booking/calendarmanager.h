#ifndef CALENDARMANAGER_H
#define CALENDARMANAGER_H

#include <QObject>
#include <QMap>
#include <QList>
#include "bookingdate.h"
#include "auditorium.h"

class CalendarManager : public QObject
{
    Q_OBJECT

public:
    CalendarManager(QObject *parent = nullptr);
    ~CalendarManager();

    void addAuditorium(const Auditorium &auditorium);
    bool isAuditoriumAvailable(const BookingDate &date, const QString &auditoriumId) const;
    void bookAuditorium(const BookingDate &date, const QString &auditoriumId);
    QList<QString> getAvailableAuditoriums(const BookingDate &date) const;

private:
    QMap<BookingDate, QMap<QString, bool>> m_bookingMap; // Maps date to auditorium availability
    QList<Auditorium> m_auditoriums; // List of auditoriums
};

#endif // CALENDARMANAGER_H
