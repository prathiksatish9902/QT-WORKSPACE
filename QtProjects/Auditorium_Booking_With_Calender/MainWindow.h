#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include "auditoriummanagement.h"
#include "calendermanager.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAddAuditoriumClicked();
    void onDisplayAuditoriumClicked();
    void onBookAuditoriumClicked();
    void onExitClicked();

    // Calendar navigation slots
    void onPrevMonthClicked();
    void onNextMonthClicked();

private:
    // Auditorium buttons
    QPushButton *addAuditoriumButton;
    QPushButton *displayAuditoriumButton;
    QPushButton *bookAuditoriumButton;
    QPushButton *exitButton;

    // Calendar navigation buttons
    QPushButton *prevMonthButton;
    QPushButton *nextMonthButton;
    QLabel *currentMonthLabel;

    // Calendar state
    int currentMonth;
    int currentYear;
    void updateMonthLabel();

    // Components
    AuditoriumManagement *auditoriumManagement;
    CalenderManager *calenderManager;
};

#endif // MAINWINDOW_H
