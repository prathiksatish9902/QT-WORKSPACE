#include "calendarmanager.h"
#include "bookingdate.h"
#include "auditorium.h"
#include <map>
#include <list>

CalendarManager::CalendarManager() {
    // Initialize the calendar manager with default values or configurations
}

CalendarManager::~CalendarManager() {
    // Clean up any resources if necessary
}

void CalendarManager::AddBooking(const BookingDate& date, const std::string& auditoriumId) {
    m_bookingMap[date].push_back(auditoriumId);
}

bool CalendarManager::IsAuditoriumBooked(const std::string& auditoriumId, const BookingDate& date) {
    auto it = m_bookingMap.find(date);
    if (it != m_bookingMap.end()) {
        const auto& bookedAuditoriums = it->second;
        return std::find(bookedAuditoriums.begin(), bookedAuditoriums.end(), auditoriumId) != bookedAuditoriums.end();
    }
    return false;
}

std::list<std::string> CalendarManager::GetAvailableAuditoriums(const BookingDate& date, const std::list<Auditorium>& auditoriums) {
    std::list<std::string> availableAuditoriums;
    for (const auto& auditorium : auditoriums) {
        if (!IsAuditoriumBooked(auditorium.GetId(), date)) {
            availableAuditoriums.push_back(auditorium.GetId());
        }
    }
    return availableAuditoriums;
}

std::map<BookingDate, std::list<std::string>> CalendarManager::GetBookingMap() const {
    return m_bookingMap;
}
