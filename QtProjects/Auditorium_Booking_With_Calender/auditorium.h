#ifndef AUDITORIUM_H
#define AUDITORIUM_H

#include <QString>

class Auditorium
{
public:
    Auditorium();
    Auditorium(QString auditoriumId, QString auditoriumName, int seatCapacity, QString auditoriumStatus);
    ~Auditorium();

    void SetId(QString auditoriumId);
    QString GetId() const;

    void SetName(QString auditoriumName);
    QString GetName() const;

    void SetSeatCapacity(int seatCapacity);
    int GetSeatCapacity() const;

    void SetStatus(QString auditoriumStatus);
    QString GetStatus() const;

private:
    QString m_auditoriumId;
    QString m_auditoriumName;
    int m_seatCapacity;
    QString m_auditoriumStatus;
};

#endif // AUDITORIUM_H
