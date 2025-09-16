#include "Contact.h"

Contact::Contact(QObject *parent)
    : QObject{parent}
{}

Contact::Contact(QString name, QString number, QString image, QObject *parent) : QObject{parent}
{
    m_contactName = name;
    m_contactNumber = number;
    m_contactImage = image;
    m_callTime = "";
    m_isIncoming = false;
    m_isOutgoing = false;
}

Contact::~Contact()
{
}

QString Contact::getContactName() const
{
    return m_contactName;
}

void Contact::setContactName(const QString &newContactName)
{
    if (m_contactName == newContactName)
        return;
    m_contactName = newContactName;
    emit contactNameChanged();
}

QString Contact::getContactNumber() const
{
    return m_contactNumber;
}

void Contact::setContactNumber(const QString &newContactNumber)
{
    if (m_contactNumber == newContactNumber)
        return;
    m_contactNumber = newContactNumber;
    emit contactNumberChanged();
}

QString Contact::getContactImage() const
{
    return m_contactImage;
}

void Contact::setContactImage(const QString &newContactImage)
{
    m_contactImage = newContactImage;
    emit contactImageChanged();
}

QString Contact::getCallTime() const
{
    return m_callTime;
}

void Contact::setCallTime(const QString &newCallTime)
{
    if (m_callTime == newCallTime)
        return;
    m_callTime = newCallTime;
    emit callTimeChanged();
}

bool Contact::getIsIncoming() const
{
    return m_isIncoming;
}

void Contact::setIsIncoming(bool newIsIncoming)
{
    if (m_isIncoming == newIsIncoming)
        return;
    m_isIncoming = newIsIncoming;
    emit isIncomingChanged();
}

bool Contact::getIsOutgoing() const
{
    return m_isOutgoing;
}

void Contact::setIsOutgoing(bool newIsOutgoing)
{
    if (m_isOutgoing == newIsOutgoing)
        return;
    m_isOutgoing = newIsOutgoing;
    emit isOutgoingChanged();
}
