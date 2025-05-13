#include "auditorium.h"

Auditorium::Auditorium() {}

Auditorium::Auditorium(const QString& auditoriumId, const QString& auditoriumName, int seatCapacity, const QString& auditoriumStatus)
    : m_auditoriumId(auditoriumId), m_auditoriumName(auditoriumName), m_seatCapacity(seatCapacity), m_auditoriumStatus(auditoriumStatus) {}

Auditorium::~Auditorium() {}

void Auditorium::SetId(const QString& auditoriumId) {
    m_auditoriumId = auditoriumId;
}

QString Auditorium::GetId() const {
    return m_auditoriumId;
}

void Auditorium::SetName(const QString& auditoriumName) {
    m_auditoriumName = auditoriumName;
}

QString Auditorium::GetName() const {
    return m_auditoriumName;
}

void Auditorium::SetSeatCapacity(int seatCapacity) {
    m_seatCapacity = seatCapacity;
}

int Auditorium::GetSeatCapacity() const {
    return m_seatCapacity;
}

void Auditorium::SetStatus(const QString& auditoriumStatus) {
    m_auditoriumStatus = auditoriumStatus;
}

QString Auditorium::GetStatus() const {
    return m_auditoriumStatus;
}
