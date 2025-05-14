#include "calendarwidget.h"

CalendarWidget::CalendarWidget(QWidget *parent) : QWidget(parent),
    m_prevMonthButton(nullptr),
    m_nextMonthButton(nullptr),
    m_monthYearLabel(nullptr)
{
    // Get current date
    time_t now = time(0);
    struct tm* current = localtime(&now);
    m_currentMonth = current->tm_mon + 1; // tm_mon is 0-based
    m_currentYear = current->tm_year + 1900; // Years since 1900
    m_selectedDay = 0; // No day selected initially

    setupUi();
    updateCalendar();

    // Debug output
    qDebug() << "Calendar initialized with month:" << m_currentMonth << "year:" << m_currentYear;
}

CalendarWidget::~CalendarWidget()
{
    // Clean up resources
    delete m_prevMonthButton;
    delete m_nextMonthButton;
    delete m_monthYearLabel;

    for (auto button : m_dayNameButtons) {
        delete button;
    }

    clearDayButtons();
}

void CalendarWidget::setupUi()
{
    // Configure main widget
    setWindowTitle("Calendar");
    resize(700, 500);

    // Create navigation buttons
    m_prevMonthButton = new QPushButton("<", this);
    m_prevMonthButton->setGeometry(50, 20, 40, 30);
    connect(m_prevMonthButton, &QPushButton::clicked, this, &CalendarWidget::previousMonth);

    m_monthYearLabel = new QPushButton("", this);
    m_monthYearLabel->setGeometry(100, 20, 500, 30);
    m_monthYearLabel->setFlat(true);
    m_monthYearLabel->setEnabled(false);

    m_nextMonthButton = new QPushButton(">", this);
    m_nextMonthButton->setGeometry(610, 20, 40, 30);
    connect(m_nextMonthButton, &QPushButton::clicked, this, &CalendarWidget::nextMonth);

    qDebug() << "Next month button connected to slot";

    // Create day name buttons (Su, Mo, Tu, etc.)
    const char* dayNames[] = {"Su", "Mo", "Tu", "We", "Th", "Fr", "Sa"};

    for (int i = 0; i < 7; i++) {
        QPushButton* dayNameButton = new QPushButton(dayNames[i], this);
        dayNameButton->setGeometry(50 + (i * 85), 70, 80, 30);
        dayNameButton->setEnabled(false);
        m_dayNameButtons.push_back(dayNameButton);
    }

    // Ensure all buttons are visible
    for (auto& button : m_dayNameButtons) {
        button->show();
    }
    m_prevMonthButton->show();
    m_nextMonthButton->show();
    m_monthYearLabel->show();
}

void CalendarWidget::clearDayButtons()
{
    for (auto button : m_dayButtons) {
        delete button;
    }
    m_dayButtons.clear();
}

void CalendarWidget::updateCalendar()
{
    // Update month/year label
    m_monthYearLabel->setText(QString::fromStdString(getMonthName(m_currentMonth) + " " + std::to_string(m_currentYear)));

    // Clear existing day buttons
    clearDayButtons();

    // Get days in month and first day of month
    int daysInMonth = getDaysInMonth(m_currentMonth, m_currentYear);
    int firstDay = getFirstDayOfMonth(m_currentMonth, m_currentYear);

    // Create day buttons
    int row = 0;
    int col = firstDay;

    for (int day = 1; day <= daysInMonth; day++) {
        QPushButton* dayButton = new QPushButton(QString::number(day), this);
        dayButton->setGeometry(50 + (col * 85), 110 + (row * 60), 80, 55);
        dayButton->setProperty("day", day);
        connect(dayButton, &QPushButton::clicked, this, &CalendarWidget::dayClicked);

        // Explicitly show the button
        dayButton->show();

        m_dayButtons.push_back(dayButton);

        col++;
        if (col > 6) {
            col = 0;
            row++;
        }
    }

    // Debug to verify button creation
    qDebug() << "Created" << m_dayButtons.size() << "day buttons for"
             << getMonthName(m_currentMonth).c_str() << m_currentYear;

    // Force update of the widget
    update();
}

void CalendarWidget::nextMonth()
{
    qDebug() << "Next month clicked - Current month:" << m_currentMonth;
    m_currentMonth++;
    if (m_currentMonth > 12) {
        m_currentMonth = 1;
        m_currentYear++;
    }
    qDebug() << "Changing to month:" << m_currentMonth << "year:" << m_currentYear;
    updateCalendar();
}

void CalendarWidget::previousMonth()
{
    qDebug() << "Previous month clicked - Current month:" << m_currentMonth;
    m_currentMonth--;
    if (m_currentMonth < 1) {
        m_currentMonth = 12;
        m_currentYear--;
    }
    qDebug() << "Changing to month:" << m_currentMonth << "year:" << m_currentYear;
    updateCalendar();
}

void CalendarWidget::dayClicked()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button) {
        m_selectedDay = button->property("day").toInt();

        // Reset styling for all buttons
        for (auto dayButton : m_dayButtons) {
            dayButton->setStyleSheet("");
        }

        // Highlight the selected button
        button->setStyleSheet("background-color: #a6d4fa;");
    }
}

int CalendarWidget::getDaysInMonth(int month, int year)
{
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            return 29; // Leap year
        }
    }

    return daysInMonth[month];
}

int CalendarWidget::getFirstDayOfMonth(int month, int year)
{
    struct tm timeinfo = {0};
    timeinfo.tm_year = year - 1900;
    timeinfo.tm_mon = month - 1;
    timeinfo.tm_mday = 1;

    mktime(&timeinfo);
    return timeinfo.tm_wday;
}

std::string CalendarWidget::getMonthName(int month)
{
    const std::string monthNames[] = {
        "", "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    if (month >= 1 && month <= 12) {
        return monthNames[month];
    }

    return "Unknown";
}
