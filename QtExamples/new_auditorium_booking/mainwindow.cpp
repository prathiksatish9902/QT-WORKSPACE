#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bookingcontroller.h"
#include <QMessageBox>
#include <QDate>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    bookingController(new BookingController(this))
{
    ui->setupUi(this);
    connect(ui->calendarWidget, &QCalendarWidget::clicked, this, &MainWindow::onDateSelected);
    connect(ui->bookButton, &QPushButton::clicked, this, &MainWindow::onBookButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onDateSelected(const QDate &date)
{
    BookingDate bookingDate(date.day(), date.month(), date.year());
    updateAvailableAuditoriums(bookingDate);
}

void MainWindow::onBookButtonClicked()
{
    QDate selectedDate = ui->calendarWidget->selectedDate();
    BookingDate bookingDate(selectedDate.day(), selectedDate.month(), selectedDate.year());

    if (bookingController->isDateAvailable(bookingDate)) {
        // Logic to book the auditorium
        QString auditoriumId = ui->auditoriumComboBox->currentText();
        bookingController->bookAuditorium(auditoriumId, bookingDate);
        QMessageBox::information(this, "Booking Successful", "Auditorium booked successfully!");
    } else {
        QMessageBox::warning(this, "Booking Unavailable", "All auditoriums are booked on this date.");
    }
}

void MainWindow::updateAvailableAuditoriums(const BookingDate &bookingDate)
{
    // Logic to update the UI based on available auditoriums
    // This may involve greying out unavailable auditoriums in the combo box
}
