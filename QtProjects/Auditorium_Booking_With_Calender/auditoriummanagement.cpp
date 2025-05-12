// Implementation file
#include "auditoriummanagement.h"
#include <QMessageBox>
#include <QApplication>
#include <QDebug>
#include <iostream>
#include <iomanip>
#include <limits>

AuditoriumManagement::AuditoriumManagement(QWidget *parent) : QWidget(parent) {
    setupUI();
    // Connect buttons to their respective slots
    connect(addAuditoriumButton, &QPushButton::clicked, this, &AuditoriumManagement::AddAuditorium);
    connect(displayAuditoriumButton, &QPushButton::clicked, this, &AuditoriumManagement::DisplayAuditorium);
    connect(bookAuditoriumButton, &QPushButton::clicked, this, &AuditoriumManagement::BookAuditorium);
    connect(exitButton, &QPushButton::clicked, this, &AuditoriumManagement::ExitApplication);
}

AuditoriumManagement::~AuditoriumManagement() {
    // Correctly delete all auditorium pointers
    for (auto it = m_auditoriumMap.begin(); it != m_auditoriumMap.end(); ++it) {
        delete it.value();
    }
    m_auditoriumMap.clear();
}

void AuditoriumManagement::setupUI() {
    QVBoxLayout *layout = new QVBoxLayout(this);

    addAuditoriumButton = new QPushButton("Add Auditorium", this);
    layout->addWidget(addAuditoriumButton);

    displayAuditoriumButton = new QPushButton("Display Auditorium", this);
    layout->addWidget(displayAuditoriumButton);

    bookAuditoriumButton = new QPushButton("Book Auditorium", this);
    layout->addWidget(bookAuditoriumButton);

    exitButton = new QPushButton("Exit", this);
    layout->addWidget(exitButton);

    setLayout(layout);
    setWindowTitle("Auditorium Management System");
    resize(400, 200);
}

void AuditoriumManagement::AddAuditorium() {
    // Create dialog for auditorium input
    QDialog dialog(this);
    dialog.setWindowTitle("Add New Auditorium");

    QFormLayout formLayout(&dialog);

    // Create input fields
    QLineEdit *idEdit = new QLineEdit(&dialog);
    QLineEdit *nameEdit = new QLineEdit(&dialog);
    QSpinBox *capacitySpinBox = new QSpinBox(&dialog);
    capacitySpinBox->setRange(10, 1000);
    capacitySpinBox->setValue(100);

    QComboBox *statusComboBox = new QComboBox(&dialog);
    statusComboBox->addItems({"Available", "Under Maintenance", "Reserved"});

    // Add fields to form
    formLayout.addRow("ID:", idEdit);
    formLayout.addRow("Name:", nameEdit);
    formLayout.addRow("Capacity:", capacitySpinBox);
    formLayout.addRow("Status:", statusComboBox);

    // Add buttons
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                               Qt::Horizontal, &dialog);
    formLayout.addRow(&buttonBox);

    // Connect buttons
    connect(&buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    connect(&buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

    // Show dialog and process result
    if (dialog.exec() == QDialog::Accepted) {
        QString id = idEdit->text();
        QString name = nameEdit->text();
        int capacity = capacitySpinBox->value();
        QString status = statusComboBox->currentText();

        // Validate inputs
        if (id.isEmpty() || name.isEmpty()) {
            QMessageBox::warning(this, "Invalid Input", "ID and Name cannot be empty.");
            return;
        }

        // Check if auditorium ID already exists
        if (m_auditoriumMap.contains(id)) {
            QMessageBox::warning(this, "Duplicate ID",
                                 "An auditorium with this ID already exists.");
            return;
        }

        // Create and add the new auditorium
        Auditorium *auditorium = new Auditorium(id, name, capacity, status);
        m_auditoriumMap[id] = auditorium;

        QMessageBox::information(this, "Success", "Auditorium added successfully!");
    }
}

void AuditoriumManagement::DisplayAuditorium() {
    if (m_auditoriumMap.isEmpty()) {
        QMessageBox::information(this, "No Auditoriums",
                                 "There are no auditoriums to display. Please add some first.");
        return;
    }

    QString output = "Auditorium List:\n\n";

    // Create fixed-width column headers properly using QString
    output += QString("ID          Name                      Capacity        Status\n");
    output += QString("------------------------------------------------------------------\n");

    for (auto it = m_auditoriumMap.begin(); it != m_auditoriumMap.end(); ++it) {
        Auditorium *auditorium = it.value();

        // Format each field with appropriate width
        QString id = auditorium->GetId().leftJustified(10, ' ');
        QString name = auditorium->GetName().leftJustified(25, ' ');
        QString capacity = QString::number(auditorium->GetSeatCapacity()).leftJustified(15, ' ');
        QString status = auditorium->GetStatus().leftJustified(15, ' ');

        // Append the formatted row
        output += id + name + capacity + status + "\n";
    }

    QMessageBox::information(this, "Auditorium List", output);
}

void AuditoriumManagement::BookAuditorium() {
    if (m_auditoriumMap.isEmpty()) {
        QMessageBox::information(this, "No Auditoriums",
                                 "There are no auditoriums to book. Please add some first.");
        return;
    }

    // Create booking dialog
    QDialog dialog(this);
    dialog.setWindowTitle("Book an Auditorium");

    QFormLayout formLayout(&dialog);

    // Create auditorium selection dropdown
    QComboBox *auditoriumCombo = new QComboBox(&dialog);
    for (auto it = m_auditoriumMap.begin(); it != m_auditoriumMap.end(); ++it) {
        Auditorium *auditorium = it.value();
        if (auditorium->GetStatus() == "Available") {
            auditoriumCombo->addItem(auditorium->GetName() + " (" + auditorium->GetId() + ")",
                                     auditorium->GetId());
        }
    }

    if (auditoriumCombo->count() == 0) {
        QMessageBox::information(this, "No Available Auditoriums",
                                 "There are no available auditoriums to book.");
        return;
    }

    // Create date selection
    QDateEdit *dateEdit = new QDateEdit(QDate::currentDate(), &dialog);
    dateEdit->setCalendarPopup(true);
    dateEdit->setMinimumDate(QDate::currentDate());

    // Add fields to form
    formLayout.addRow("Auditorium:", auditoriumCombo);
    formLayout.addRow("Date:", dateEdit);

    // Add buttons
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                               Qt::Horizontal, &dialog);
    formLayout.addRow(&buttonBox);

    // Connect buttons
    connect(&buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    connect(&buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

    // Show dialog and process result
    if (dialog.exec() == QDialog::Accepted) {
        QString auditoriumId = auditoriumCombo->currentData().toString();
        QDate date = dateEdit->date();

        // Create a BookingDate object
        BookingDate bookingDate(date.day(), date.month(), date.year());

        // Check if the auditorium is already booked on that date
        if (IsAuditoriumBooked(auditoriumId, bookingDate)) {
            QMessageBox::warning(this, "Already Booked",
                                 "This auditorium is already booked for the selected date.");
            return;
        }

        // Validate booking date
        if (!IsValidBookingDate(bookingDate)) {
            QMessageBox::warning(this, "Invalid Date",
                                 "The selected date is not valid for booking.");
            return;
        }

        // Add the booking
        if (!m_bookingMap.contains(bookingDate)) {
            m_bookingMap[bookingDate] = QList<QString>();
        }
        m_bookingMap[bookingDate].append(auditoriumId);

        // Update auditorium status
        m_auditoriumMap[auditoriumId]->SetStatus("Reserved");

        QMessageBox::information(this, "Success",
                                 "Auditorium booked successfully for " +
                                     date.toString("MMMM d, yyyy"));
    }
}

void AuditoriumManagement::ExitApplication() {
    // Ask for confirmation before exiting
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Exit Confirmation",
                                                              "Are you sure you want to exit the application?",
                                                              QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QApplication::quit();
    }
}

bool AuditoriumManagement::IsAuditoriumBooked(const QString& auditoriumId, const BookingDate& bookingdate) {
    if (m_bookingMap.contains(bookingdate)) {
        return m_bookingMap[bookingdate].contains(auditoriumId);
    }
    return false;
}

bool AuditoriumManagement::IsValidBookingDate(const BookingDate &bookingDate) {
    // Get current date
    QDate currentDate = QDate::currentDate();
    QDate bookingQDate(bookingDate.GetYear(), bookingDate.GetMonth(), bookingDate.GetDay());

    // Booking date should be today or in the future
    if (bookingQDate < currentDate) {
        return false;
    }

    // Additional validation logic can be added here
    // For example, limit bookings to next 6 months
    QDate maxDate = currentDate.addMonths(6);
    if (bookingQDate > maxDate) {
        return false;
    }

    return true;
}
