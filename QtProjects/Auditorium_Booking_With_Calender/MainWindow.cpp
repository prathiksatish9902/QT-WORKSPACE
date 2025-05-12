#include "MainWindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), auditoriumManagement(new AuditoriumManagement)
{
    addAuditoriumButton = new QPushButton("Add Auditorium", this);
    displayAuditoriumButton = new QPushButton("Display Auditorium", this);
    bookAuditoriumButton = new QPushButton("Book Auditorium", this);
    exitButton = new QPushButton("Exit", this);

    addAuditoriumButton->setGeometry(50, 50, 200, 40);
    displayAuditoriumButton->setGeometry(50, 100, 200, 40);
    bookAuditoriumButton->setGeometry(50, 150, 200, 40);
    exitButton->setGeometry(50, 200, 200, 40);

    connect(addAuditoriumButton, &QPushButton::clicked, this, &MainWindow::onAddAuditoriumClicked);
    connect(displayAuditoriumButton, &QPushButton::clicked, this, &MainWindow::onDisplayAuditoriumClicked);
    connect(bookAuditoriumButton, &QPushButton::clicked, this, &MainWindow::onBookAuditoriumClicked);
    connect(exitButton, &QPushButton::clicked, this, &MainWindow::onExitClicked);
}

MainWindow::~MainWindow()
{
    delete auditoriumManagement;
}

void MainWindow::onAddAuditoriumClicked()
{
    auditoriumManagement->AddAuditorium();
    QMessageBox::information(this, "Add Auditorium", "Auditoriums have been added successfully.");
}

void MainWindow::onDisplayAuditoriumClicked()
{
    auditoriumManagement->DisplayAuditorium();
    QMessageBox::information(this, "Display Auditorium", "Auditorium details have been displayed in the console.");
}

void MainWindow::onBookAuditoriumClicked()
{
    auditoriumManagement->BookAuditorium();
    QMessageBox::information(this, "Book Auditorium", "Auditorium booking process has been initiated. Check the console for details.");
}

void MainWindow::onExitClicked()
{
    close();
}
