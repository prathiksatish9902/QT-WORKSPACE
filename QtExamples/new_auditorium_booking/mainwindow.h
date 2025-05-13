#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCalendarWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <map>
#include "BookingController.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onDateSelected(const QDate &date);
    void onBookAuditorium();

private:
    void setupUI();
    void updateAvailableAuditoriums(const QDate &date);
    void displayBookingCounts(const QDate &date);

    QCalendarWidget *calendarWidget;
    QPushButton *bookButton;
    QLabel *statusLabel;
    BookingController *bookingController;
    std::map<QString, bool> auditoriumAvailability; // Maps auditorium ID to availability status
};

#endif // MAINWINDOW_H
