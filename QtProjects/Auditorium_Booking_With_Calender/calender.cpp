#include "calender.h"

Calender::Calender() {
    year = new Year(2025);
}

Calender::~Calender() {
    delete year;
}

void Calender::AddYear() {
    m_yearList.push_back(year);
}

Year* Calender::GetCurrentYear() {
    return year;
}
