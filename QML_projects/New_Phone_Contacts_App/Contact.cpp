#include "Contact.h"

Contact::Contact(QObject *parent)
    : QObject{parent}
{}

Contact::Contact(QString name, QString phoneNumber, QObject *parent)
    : QObject{parent}, m_name(name), m_phoneNumber(phoneNumber)
{

}

QString Contact::getName() const
{
    return m_name;
}

void Contact::setName(const QString &newName)
{
    if (m_name == newName)
        return;
    m_name = newName;
    emit nameChanged();
}

QString Contact::getPhoneNumber() const
{
    return m_phoneNumber;
}

void Contact::setPhoneNumber(const QString &newPhoneNumber)
{
    if (m_phoneNumber == newPhoneNumber)
        return;
    m_phoneNumber = newPhoneNumber;
    emit phoneNumberChanged();
}
