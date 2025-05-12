#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include "auditoriummanagement.h" // Ensure this include is present


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

private:
    QPushButton *addAuditoriumButton;
    QPushButton *displayAuditoriumButton;
    QPushButton *bookAuditoriumButton;
    QPushButton *exitButton;

    AuditoriumManagement *auditoriumManagement;
};

#endif // MAINWINDOW_H
