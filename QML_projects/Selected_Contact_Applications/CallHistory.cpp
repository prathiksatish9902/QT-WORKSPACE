#include "CallHistory.h"
#include <QFile>
#include <QTextStream>
#include <QDateTime>

CallHistory::CallHistory() {
    this->createContactData();
}

CallHistory::~CallHistory()
{
}

int CallHistory::rowCount(const QModelIndex &parent) const
{
    return m_contactList.count();
}

QVariant CallHistory::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= m_contactList.size())
        return QVariant();
    Contact *contact = m_contactList.at(index.row());
    switch (role) {
    case NAMEROLE:
        return contact->getContactName();
    case PHONENUMBERROLE:
        return contact->getContactNumber();
    case IMAGEROLE:
        return contact->getContactImage();
    case CALLTIMEROLE:
        return contact->getCallTime();
    case INCOMINGROLE:
        return contact->getIsIncoming();
    case OUTGOINGROLE:
        return contact->getIsOutgoing();
    }
    return QVariant();
}

QHash<int, QByteArray> CallHistory::roleNames() const
{
    QHash<int, QByteArray> l_contactRole;
    l_contactRole[NAMEROLE] = "name";
    l_contactRole[PHONENUMBERROLE] = "phoneNumber";
    l_contactRole[IMAGEROLE] = "profileImage";
    l_contactRole[CALLTIMEROLE] = "callTime";
    l_contactRole[INCOMINGROLE] = "incomingCall";
    l_contactRole[OUTGOINGROLE] = "outgoingCall";
    return l_contactRole;
}

void CallHistory::createContactData()
{
    loadFromCsv("callhistory.csv");
}

void CallHistory::insertContactData(Contact *contact)
{
    beginInsertRows(QModelIndex(), 0, 0); // Prepend to show recent calls first
    m_contactList.prepend(contact);
    endInsertRows();
    saveToCsv("callhistory.csv");
}

void CallHistory::addOutgoingCall(const QString &name, const QString &number, const QString &image)
{
    Contact *c = new Contact(name, number, image, this);
    c->setCallTime(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    c->setIsOutgoing(true);
    insertContactData(c);
}
