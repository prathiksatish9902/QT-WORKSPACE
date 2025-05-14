#include "year.h"

Year::Year() : m_year(2025) {
    AddMonths();
}

Year::Year(int year) : m_year(year) {
    AddMonths();
}

Year::~Year() {
    for (auto& pair : m_monthMap) {
        delete pair.second;
    }
}

void Year::SetYear(int year) {
    m_year = year;
}

int Year::GetYear() const {
    return m_year;
}

void Year::AddMonths() {
    m_monthMap[1] = new Month("January");
    m_monthMap[2] = new Month("February");
    m_monthMap[3] = new Month("March");
    m_monthMap[4] = new Month("April");
    m_monthMap[5] = new Month("May");
    m_monthMap[6] = new Month("June");
    m_monthMap[7] = new Month("July");
    m_monthMap[8] = new Month("August");
    m_monthMap[9] = new Month("September");
    m_monthMap[10] = new Month("October");
    m_monthMap[11] = new Month("November");
    m_monthMap[12] = new Month("December");
}

Month* Year::GetCurrentMonth(int key) const {
    auto it = m_monthMap.find(key);
    if (it != m_monthMap.end()) {
        return it->second;
    }
    return nullptr;
}
