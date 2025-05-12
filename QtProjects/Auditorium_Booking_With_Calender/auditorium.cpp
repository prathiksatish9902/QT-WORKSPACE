#include "auditorium.h"

Auditorium::Auditorium() : m_seatCapacity(0) {
}

Auditorium::Auditorium(QString auditoriumId, QString auditoriumName, int seatCapacity, QString auditoriumStatus)
    : m_auditoriumId(auditoriumId), m_auditoriumName(auditoriumName), m_seatCapacity(seatCapacity), m_auditoriumStatus(auditoriumStatus) {
}

Auditorium::~Auditorium() {
}

void Auditorium::SetId(QString auditoriumId) {
    m_auditoriumId = auditoriumId;
}

QString Auditorium::GetId() const {
    return m_auditoriumId;
}

void Auditorium::SetName(QString auditoriumName) {
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

void Auditorium::SetStatus(QString auditoriumStatus) {
    m_auditoriumStatus = auditoriumStatus;
}

QString Auditorium::GetStatus() const {
    return m_auditoriumStatus;
}
