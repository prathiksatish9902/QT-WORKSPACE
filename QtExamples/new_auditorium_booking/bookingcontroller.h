#ifndef BOOKINGCONTROLLER_H
#define BOOKINGCONTROLLER_H

#include <QObject>
#include <QDate>
#include <QString>
#include <map>
#include <list>
#include "bookingdate.h"
#include "auditorium.h"
#include "calendarmanager.h"

class BookingController : public QObject
{
    Q_OBJECT

public:
    BookingController(CalendarManager* calendarManager, QObject* parent = nullptr);
    ~BookingController();

    void selectDate(const QDate& date);
    bool checkAvailability(const QString& auditoriumId, const BookingDate& bookingDate);
    bool bookAuditorium(const QString& auditoriumId, const BookingDate& bookingDate);

signals:
    void availabilityChecked(bool available);
    void bookingConfirmed(const QString& auditoriumId, const BookingDate& bookingDate);
    void bookingFailed(const QString& auditoriumId, const BookingDate& bookingDate);

private:
    CalendarManager* m_calendarManager;
    QDate m_selectedDate;
};

#endif // BOOKINGCONTROLLER_H
