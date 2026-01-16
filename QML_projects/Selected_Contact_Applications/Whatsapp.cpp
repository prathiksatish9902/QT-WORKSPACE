#include "Whatsapp.h"
#include <QFile>
#include <QTextStream>

Whatsapp::Whatsapp() {
    this->createContactData();
}

Whatsapp::~Whatsapp()
{
}

int Whatsapp::rowCount(const QModelIndex &parent) const
{
    return m_contactList.count();
}

QVariant Whatsapp::data(const QModelIndex &index, int role) const
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
    case MESSAGETIMEROLE:
        return contact->getCallTime();
    case INCOMINGROLE:
        return contact->getIsIncoming();
    case OUTGOINGROLE:
        return contact->getIsOutgoing();
    }
    return QVariant();
}

QHash<int, QByteArray> Whatsapp::roleNames() const
{
    QHash<int, QByteArray> l_contactRole;
    l_contactRole[NAMEROLE] = "name";
    l_contactRole[PHONENUMBERROLE] = "phoneNumber";
    l_contactRole[IMAGEROLE] = "profileImage";
    l_contactRole[MESSAGETIMEROLE] = "messageTime";
    l_contactRole[INCOMINGROLE] = "incomingCall";
    l_contactRole[OUTGOINGROLE] = "outgoingCall";
    return l_contactRole;
}

void Whatsapp::createContactData()
{
    loadFromCsv("whatsapp.csv"); // Changed to use separate whatsapp.csv
}
