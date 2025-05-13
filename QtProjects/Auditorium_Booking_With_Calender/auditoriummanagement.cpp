#include "auditoriummanagement.h"
#include "calendermanager.h"
#include <QMessageBox>
#include <QApplication>
#include <QDebug>
#include <iostream>
#include <iomanip>
#include <limits>


#include <map>
#include <list>
#include <string>

AuditoriumManagement::AuditoriumManagement(QWidget *parent) : QWidget(parent) {
    setupUI();
    connect(addAuditoriumButton, &QPushButton::clicked, this, &AuditoriumManagement::AddAuditorium);
    connect(displayAuditoriumButton, &QPushButton::clicked, this, &AuditoriumManagement::DisplayAuditorium);
    connect(bookAuditoriumButton, &QPushButton::clicked, this, &AuditoriumManagement::BookAuditorium);
    connect(exitButton, &QPushButton::clicked, this, &AuditoriumManagement::ExitApplication);
}

AuditoriumManagement::~AuditoriumManagement() {
    for (auto auditoriumList = m_auditoriumMap.begin(); auditoriumList != m_auditoriumMap.end(); ++auditoriumList) {
        delete auditoriumList.value();
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
    QMap<QString, Auditorium*>::iterator auditoriumList;
    for (auditoriumList = m_auditoriumMap.begin(); auditoriumList != m_auditoriumMap.end(); ++auditoriumList) {
        delete auditoriumList.value();
    }
    m_auditoriumMap.clear();

    m_auditoriumMap["AUD001"] = new Auditorium("AUD001", "Auditorium 1", 300, "Available");
    m_auditoriumMap["AUD002"] = new Auditorium("AUD002", "Auditorium 2", 300, "Available");
    m_auditoriumMap["AUD003"] = new Auditorium("AUD003", "Auditorium 3", 300, "Available");
    m_auditoriumMap["AUD004"] = new Auditorium("AUD004", "Auditorium 4", 300, "Available");
    m_auditoriumMap["AUD005"] = new Auditorium("AUD005", "Auditorium 5", 300, "Available");
    m_auditoriumMap["AUD006"] = new Auditorium("AUD006", "Auditorium 6", 300, "Available");
    m_auditoriumMap["AUD007"] = new Auditorium("AUD007", "Auditorium 7", 300, "Available");
    m_auditoriumMap["AUD008"] = new Auditorium("AUD008", "Auditorium 8", 300, "Available");
    m_auditoriumMap["AUD009"] = new Auditorium("AUD009", "Auditorium 9", 300, "Available");
    m_auditoriumMap["AUD010"] = new Auditorium("AUD010", "Auditorium 10", 300, "Available");

    QMessageBox::information(this, "Success", "Predefined auditoriums added successfully!");
}
void AuditoriumManagement::DisplayAuditorium() {
    if (m_auditoriumMap.isEmpty()) {
        QMessageBox::information(this, "No Auditoriums",
                                 "There are no auditoriums to display. Please add some first.");
        return;
    }

    QString output = "Auditorium List:\n\n";

    output += QString("ID          Name                      Capacity        Status\n");
    output += QString("------------------------------------------------------------------\n");

    for (auto it = m_auditoriumMap.begin(); it != m_auditoriumMap.end(); ++it) {
        Auditorium *auditorium = it.value();

        QString id = auditorium->GetId().leftJustified(10, ' ');
        QString name = auditorium->GetName().leftJustified(25, ' ');
        QString capacity = QString::number(auditorium->GetSeatCapacity()).leftJustified(15, ' ');
        QString status = auditorium->GetStatus().leftJustified(15, ' ');

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

    QDialog dialog(this);
    dialog.setWindowTitle("Book an Auditorium");
    QFormLayout formLayout(&dialog);

    QDateEdit *dateEdit = new QDateEdit(QDate::currentDate(), &dialog);
    dateEdit->setCalendarPopup(true);
    dateEdit->setMinimumDate(QDate::currentDate());
    formLayout.addRow("Date:", dateEdit);

    QComboBox *auditoriumCombo = new QComboBox(&dialog);

    auto updateAvailableAuditoriums = [this, auditoriumCombo, dateEdit]() {
        auditoriumCombo->clear();
        QDate date = dateEdit->date();
        BookingDate bookingDate(date.day(), date.month(), date.year());

        for (auto it = m_auditoriumMap.begin(); it != m_auditoriumMap.end(); ++it) {
            Auditorium *auditorium = it.value();
            QString auditoriumId = auditorium->GetId();

            bool isBooked = IsAuditoriumBooked(auditoriumId, bookingDate);

            if (!isBooked) {
                auditoriumCombo->addItem(auditorium->GetName() + " (" + auditoriumId + ")",
                                         auditoriumId);
            }
        }
    };

    updateAvailableAuditoriums();

    connect(dateEdit, &QDateEdit::dateChanged, [updateAvailableAuditoriums]() {
        updateAvailableAuditoriums();
    });

    formLayout.addRow("Auditorium:", auditoriumCombo);

    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                               Qt::Horizontal, &dialog);
    formLayout.addRow(&buttonBox);

    connect(&buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    connect(&buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

    if (dialog.exec() == QDialog::Accepted) {
        if (auditoriumCombo->count() == 0) {
            QMessageBox::information(this, "No Available Auditoriums",
                                     "There are no available auditoriums to book for the selected date.");
            return;
        }

        QString auditoriumId = auditoriumCombo->currentData().toString();
        QDate date = dateEdit->date();

        BookingDate bookingDate(date.day(), date.month(), date.year());

        if (!IsValidBookingDate(bookingDate)) {
            QMessageBox::warning(this, "Invalid Date",
                                 "The selected date is not valid for booking.");
            return;
        }

        if (!m_bookingMap.contains(bookingDate)) {
            m_bookingMap[bookingDate] = QList<QString>();
        }
        m_bookingMap[bookingDate].append(auditoriumId);

        QMessageBox::information(this, "Success",
                                 "Auditorium booked successfully for " +
                                     date.toString("MMMM d, yyyy"));

        std::map<BookingDate, std::list<std::string>> stdBookingMap;
        for (auto it = m_bookingMap.begin(); it != m_bookingMap.end(); ++it) {
            std::list<std::string> bookings;
            for (const QString &qstr : it.value()) {
                bookings.push_back(qstr.toStdString());//converting qstring to std::string befor adding to std::list.
            }
            stdBookingMap[it.key()] = bookings;
        }

        CalenderManager calenderManager;
        calenderManager.PrintMonthCalendar(date.month(), date.year(), &stdBookingMap);
    }
}

void AuditoriumManagement::ExitApplication() {
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
    QDate currentDate = QDate::currentDate();
    QDate bookingQDate(bookingDate.GetYear(), bookingDate.GetMonth(), bookingDate.GetDay());

    if (bookingQDate < currentDate) {
        return false;
    }

    QDate maxDate = currentDate.addMonths(6);
    if (bookingQDate > maxDate) {
        return false;
    }

    return true;
}
