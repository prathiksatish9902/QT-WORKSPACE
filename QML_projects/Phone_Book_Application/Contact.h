#ifndef CONTACT_H
#define CONTACT_H

#include <QObject>

class Contact : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged FINAL)
    Q_PROPERTY(QString phoneNumber READ getPhoneNumber WRITE setPhoneNumber NOTIFY phoneNumberChanged FINAL)


public:
    explicit Contact(QObject *parent = nullptr);
    Contact(QString name ,  QString phoneNumber , QObject *parent = nullptr);

    QString getName() const;
    void setName(const QString &newName);

    QString getPhoneNumber() const;
    void setPhoneNumber(const QString &newPhoneNumber);

signals:

    void nameChanged();

    void phoneNumberChanged();

private:
    QString m_name;
    QString m_phoneNumber;
};

#endif // CONTACT_H
