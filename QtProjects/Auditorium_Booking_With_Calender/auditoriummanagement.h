#ifndef AUDITORIUMMANAGEMENT_H
#define AUDITORIUMMANAGEMENT_H
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMap>
#include <QString>
#include <QInputDialog>
#include <QLineEdit>
#include <QCalendarWidget>
#include <QDialog>
#include <QLabel>
#include <QComboBox>
#include <QDateEdit>
#include <QSpinBox>
#include <QFormLayout>
#include <QDialogButtonBox>
#include <QInputDialog>
#include <QMessageBox>
#include "auditorium.h"
#include "bookingdate.h"

class AuditoriumManagement : public QWidget
{
    Q_OBJECT
public:
    AuditoriumManagement(QWidget *parent = nullptr);
    ~AuditoriumManagement();
private slots:
    void AddAuditorium();
    void DisplayAuditorium();
    void BookAuditorium();
    void ExitApplication();
private:
    QMap<QString, Auditorium*> m_auditoriumMap;
    QMap<BookingDate, QList<QString>> m_bookingMap;
    bool IsAuditoriumBooked(const QString& auditoriumId, const BookingDate& bookingdate);
    bool IsValidBookingDate(const BookingDate &bookingDate);
    QPushButton *addAuditoriumButton;
    QPushButton *displayAuditoriumButton;
    QPushButton *bookAuditoriumButton;
    QPushButton *exitButton;
    void setupUI();

    friend class MainWindow;
};
#endif // AUDITORIUMMANAGEMENT_H
