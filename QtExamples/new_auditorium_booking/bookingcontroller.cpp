#include "bookingcontroller.h"
#include "calendarmanager.h"
#include "auditorium.h"
#include "bookingdate.h"
#include <QMessageBox>

BookingController::BookingController(CalendarManager* calendarManager, QObject* parent)
    : QObject(parent), m_calendarManager(calendarManager) {}

void BookingController::selectDate(const BookingDate& date) {
    m_selectedDate = date;
    checkAvailability();
}

void BookingController::checkAvailability() {
    auto availableAuditoriums = m_calendarManager->getAvailableAuditoriums(m_selectedDate);
    emit availabilityChecked(availableAuditoriums);
}

void BookingController::bookAuditorium(const QString& auditoriumId) {
    if (m_calendarManager->bookAuditorium(auditoriumId, m_selectedDate)) {
        QMessageBox::information(nullptr, "Booking Successful", "Auditorium booked successfully!");
    } else {
        QMessageBox::warning(nullptr, "Booking Failed", "Auditorium is already booked on this date.");
    }
}
