#ifndef AUDITORIUM_H
#define AUDITORIUM_H
#include <QString>

class Auditorium
{
public:
    Auditorium();
    Auditorium(const QString& auditoriumId, const QString& auditoriumName, int seatCapacity, const QString& auditoriumStatus);
    ~Auditorium();

    void SetId(const QString& auditoriumId);
    QString GetId() const;

    void SetName(const QString& auditoriumName);
    QString GetName() const;

    void SetSeatCapacity(int seatCapacity);
    int GetSeatCapacity() const;

    void SetStatus(const QString& auditoriumStatus);
    QString GetStatus() const;

private:
    QString m_auditoriumId;
    QString m_auditoriumName;
    int m_seatCapacity;
    QString m_auditoriumStatus;
};

#endif // AUDITORIUM_H
