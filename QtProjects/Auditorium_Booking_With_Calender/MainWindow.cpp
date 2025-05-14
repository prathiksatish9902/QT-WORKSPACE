#include "MainWindow.h"
#include <QMessageBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), auditoriumManagement(new AuditoriumManagement), calenderManager(new CalenderManager)
{
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    QGroupBox *buttonGroup = new QGroupBox("Auditorium Management", this);
    QVBoxLayout *buttonLayout = new QVBoxLayout(buttonGroup);

    addAuditoriumButton = new QPushButton("Add Auditorium", this);
    displayAuditoriumButton = new QPushButton("Display Auditorium", this);
    bookAuditoriumButton = new QPushButton("Book Auditorium", this);
    exitButton = new QPushButton("Exit", this);

    buttonLayout->addWidget(addAuditoriumButton);
    buttonLayout->addWidget(displayAuditoriumButton);
    buttonLayout->addWidget(bookAuditoriumButton);
    buttonLayout->addSpacing(10);
    buttonLayout->addWidget(exitButton);

    QGroupBox *calendarGroup = new QGroupBox("Calendar Navigation", this);
    QVBoxLayout *calendarLayout = new QVBoxLayout(calendarGroup);

    prevMonthButton = new QPushButton("Previous Month", this);
    nextMonthButton = new QPushButton("Next Month", this);
    currentMonthLabel = new QLabel("Current Month: May 2025", this);
    currentMonthLabel->setAlignment(Qt::AlignCenter);

    calendarLayout->addWidget(currentMonthLabel);

    QHBoxLayout *navButtonLayout = new QHBoxLayout();
    navButtonLayout->addWidget(prevMonthButton);
    navButtonLayout->addWidget(nextMonthButton);
    calendarLayout->addLayout(navButtonLayout);

    mainLayout->addWidget(buttonGroup);
    mainLayout->addWidget(calendarGroup);

    setCentralWidget(centralWidget);

    connect(addAuditoriumButton, &QPushButton::clicked, this, &MainWindow::onAddAuditoriumClicked);
    connect(displayAuditoriumButton, &QPushButton::clicked, this, &MainWindow::onDisplayAuditoriumClicked);
    connect(bookAuditoriumButton, &QPushButton::clicked, this, &MainWindow::onBookAuditoriumClicked);
    connect(exitButton, &QPushButton::clicked, this, &MainWindow::onExitClicked);

    connect(prevMonthButton, &QPushButton::clicked, this, &MainWindow::onPrevMonthClicked);
    connect(nextMonthButton, &QPushButton::clicked, this, &MainWindow::onNextMonthClicked);

    currentMonth = calenderManager->GetCurrentMonth();
    currentYear = calenderManager->GetCurrentYear();
    updateMonthLabel();

    setWindowTitle("Auditorium Booking System");
    resize(400, 400);

    calenderManager->PrintMonthCalendar(currentMonth, currentYear);
}

MainWindow::~MainWindow()
{
    delete auditoriumManagement;
    delete calenderManager;
}

void MainWindow::onAddAuditoriumClicked()
{
    auditoriumManagement->AddAuditorium();
    QMessageBox::information(this, "Add Auditorium", "Auditoriums have been added successfully.");
}

void MainWindow::onDisplayAuditoriumClicked()
{
    auditoriumManagement->DisplayAuditorium();
}

void MainWindow::onBookAuditoriumClicked()
{
    auditoriumManagement->BookAuditorium();
}

void MainWindow::onExitClicked()
{
    close();
}

void MainWindow::onPrevMonthClicked()
{
    if (currentMonth > 1) {
        currentMonth--;
    } else {
        currentMonth = 12;
        currentYear--;
    }

    updateMonthLabel();
    calenderManager->PrintMonthCalendar(currentMonth, currentYear);
}

void MainWindow::onNextMonthClicked()
{
    if (currentMonth < 12) {
        currentMonth++;
    } else {
        currentMonth = 1;
        currentYear++;
    }

    updateMonthLabel();
    calenderManager->PrintMonthCalendar(currentMonth, currentYear);
}

void MainWindow::updateMonthLabel()
{
    QString monthName;
    switch(currentMonth) {
    case 1: monthName = "January"; break;
    case 2: monthName = "February"; break;
    case 3: monthName = "March"; break;
    case 4: monthName = "April"; break;
    case 5: monthName = "May"; break;
    case 6: monthName = "June"; break;
    case 7: monthName = "July"; break;
    case 8: monthName = "August"; break;
    case 9: monthName = "September"; break;
    case 10: monthName = "October"; break;
    case 11: monthName = "November"; break;
    case 12: monthName = "December"; break;
    default: monthName = "Unknown"; break;
    }

    currentMonthLabel->setText(QString("Current Month: %1 %2").arg(monthName).arg(currentYear));
}







