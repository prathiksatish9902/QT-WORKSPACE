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

    // Initialize auditorium management
    m_auditoriumManagement.AddAuditorium();

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
    delete m_addAuditoriumButton;
    delete m_displayAuditoriumButton;
    delete m_bookAuditoriumButton;
    delete m_bookingDateInput;
    delete m_auditoriumIdInput;
    delete m_outputDisplay;
}

void CalendarWidget::setupUi()
{
    // Configure main widget
    setWindowTitle("Calendar");
    resize(900, 600);

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

    // Create day name buttons (Su, Mo, Tu, etc.)
    const char* dayNames[] = {"Su", "Mo", "Tu", "We", "Th", "Fr", "Sa"};

    for (int i = 0; i < 7; i++) {
        QPushButton* dayNameButton = new QPushButton(dayNames[i], this);
        dayNameButton->setGeometry(50 + (i * 85), 70, 80, 30);
        dayNameButton->setEnabled(false);
        m_dayNameButtons.push_back(dayNameButton);
    }

    // Auditorium management buttons
    m_addAuditoriumButton = new QPushButton("Add Auditorium", this);
    m_addAuditoriumButton->setGeometry(750, 100, 180, 30);
    connect(m_addAuditoriumButton, &QPushButton::clicked, this, &CalendarWidget::addAuditorium);

    m_displayAuditoriumButton = new QPushButton("Display Auditoriums", this);
    m_displayAuditoriumButton->setGeometry(750, 140, 180, 30);
    connect(m_displayAuditoriumButton, &QPushButton::clicked, this, &CalendarWidget::displayAuditoriums);

    m_bookAuditoriumButton = new QPushButton("Book Auditorium", this);
    m_bookAuditoriumButton->setGeometry(750, 180, 180, 30);
    connect(m_bookAuditoriumButton, &QPushButton::clicked, this, &CalendarWidget::bookAuditorium);

    QPushButton* exitButton = new QPushButton("Exit", this);
    exitButton->setGeometry(750, 300, 180, 30);
    connect(exitButton, &QPushButton::clicked, this, &CalendarWidget::close);

    exitButton->show();
    // Input fields
    m_bookingDateInput = new QLineEdit(this);
    m_bookingDateInput->setGeometry(750, 220, 180, 30);
    m_bookingDateInput->setPlaceholderText("DD MM YYYY");

    m_auditoriumIdInput = new QLineEdit(this);
    m_auditoriumIdInput->setGeometry(750, 260, 180, 30);
    m_auditoriumIdInput->setPlaceholderText("Auditorium ID");

    // Output display
    m_outputDisplay = new QTextEdit(this);
    m_outputDisplay->setGeometry(50, 450, 820, 120);
    m_outputDisplay->setReadOnly(true);

    // Ensure all buttons are visible
    for (auto& button : m_dayNameButtons) {
        button->show();
    }
    m_prevMonthButton->show();
    m_nextMonthButton->show();
    m_monthYearLabel->show();
    m_addAuditoriumButton->show();
    m_displayAuditoriumButton->show();
    m_bookAuditoriumButton->show();
    m_bookingDateInput->show();
    m_auditoriumIdInput->show();
    m_outputDisplay->show();
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
    m_currentMonth++;
    if (m_currentMonth > 12) {
        m_currentMonth = 1;
        m_currentYear++;
    }
    updateCalendar();
}

void CalendarWidget::previousMonth()
{
    m_currentMonth--;
    if (m_currentMonth < 1) {
        m_currentMonth = 12;
        m_currentYear--;
    }
    updateCalendar();
}

// void CalendarWidget::dayClicked()
// {
//     QPushButton* button = qobject_cast<QPushButton*>(sender());
//     if (button) {
//         m_selectedDay = button->property("day").toInt();

//         // Reset styling for all buttons
//         for (auto dayButton : m_dayButtons) {
//             dayButton->setStyleSheet("");
//         }

//         // Highlight the selected button
//         button->setStyleSheet("background-color: #a6d4fa;");
//     }
// }

void CalendarWidget::dayClicked()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button) {
        m_selectedDay = button->property("day").toInt();
        QString date = QString::number(m_selectedDay) + " " + QString::number(m_currentMonth) + " " + QString::number(m_currentYear);
        m_bookingDateInput->setText(date);

        QMessageBox::information(this, "Date Selected", "Selected date: " + date);
    }
}

// void CalendarWidget::addAuditorium()
// {
//     m_auditoriumManagement.AddAuditorium();
//     m_outputDisplay->append("Auditoriums added successfully.");
// }
void CalendarWidget::addAuditorium()
{
    m_auditoriumManagement.AddAuditorium();
    QMessageBox::information(this, "Success", "Auditoriums added successfully.");
}

// void CalendarWidget::displayAuditoriums()
// {
//     std::ostringstream oss;
//     m_auditoriumManagement.DisplayAuditorium();
//     m_outputDisplay->append(QString::fromStdString(oss.str()));
// }

void CalendarWidget::displayAuditoriums()
{
    std::ostringstream oss;
    oss << "Auditorium ID" << std::setw(20) << "Auditorium Name" << std::setw(20)
        << "Seat Capacity" << std::setw(15) << "Status" << "\n";
    oss << "---------------------------------------------------------------------------------\n";

    const auto& auditoriumMap = m_auditoriumManagement.GetAuditoriumMap();
    for (const auto& pair : auditoriumMap) {
        Auditorium* auditorium = pair.second;
        if (auditorium->GetStatus() == "available") {
            oss << pair.first << std::setw(20) << auditorium->GetName() << std::setw(20)
            << auditorium->GetSeatCapacity() << std::setw(20) << auditorium->GetStatus() << "\n";
        }
    }

    m_outputDisplay->setText(QString::fromStdString(oss.str()));
    QMessageBox::information(this, "Success", "Auditorium list displayed successfully.");
}

// void CalendarWidget::bookAuditorium()
// {
//     QString dateInput = m_bookingDateInput->text();
//     QString auditoriumId = m_auditoriumIdInput->text();

//     if (dateInput.isEmpty() || auditoriumId.isEmpty()) {
//         m_outputDisplay->append("Please enter both booking date and auditorium ID.");
//         return;
//     }

//     int day, month, year;
//     std::istringstream iss(dateInput.toStdString());
//     iss >> day >> month >> year;

//     BookingDate bookingDate(day, month, year);
//     if (!m_auditoriumManagement.IsValidBookingDate(bookingDate)) {
//         m_outputDisplay->append("Invalid booking date.");
//         return;
//     }

//     if (m_auditoriumManagement.IsAuditoriumBooked(auditoriumId.toStdString(), bookingDate)) {
//         m_outputDisplay->append("Auditorium is already booked for the selected date.");
//         return;
//     }

//     m_auditoriumManagement.m_bookingMap[bookingDate].push_back(auditoriumId.toStdString());
//     m_outputDisplay->append("Auditorium booked successfully.");
// }


void CalendarWidget::bookAuditorium()
{
    QString dateInput = m_bookingDateInput->text();
    QString auditoriumId = m_auditoriumIdInput->text();

    if (dateInput.isEmpty() || auditoriumId.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please fill in both the date and auditorium ID.");
        return;
    }

    int day, month, year;
    std::istringstream iss(dateInput.toStdString());
    iss >> day >> month >> year;

    BookingDate bookingDate(day, month, year);
    if (!m_auditoriumManagement.IsValidBookingDate(bookingDate)) {
        QMessageBox::warning(this, "Error", "Invalid booking date.");
        return;
    }

    if (m_auditoriumManagement.IsAuditoriumBooked(auditoriumId.toStdString(), bookingDate)) {
        QMessageBox::warning(this, "Error", "Auditorium is already booked for the selected date.");
        return;
    }

    m_auditoriumManagement.m_bookingMap[bookingDate].push_back(auditoriumId.toStdString());
    QMessageBox::information(this, "Success", "Auditorium booked successfully.");
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











