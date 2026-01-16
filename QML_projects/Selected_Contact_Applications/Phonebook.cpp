#include "Phonebook.h"
#include <QFile>
#include <QTextStream>

Phonebook::Phonebook() {
    this->createContactData();
}

Phonebook::~Phonebook()
{
}

int Phonebook::rowCount(const QModelIndex &parent) const
{
    return m_contactList.count();
}

QVariant Phonebook::data(const QModelIndex &index, int role) const
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
    }
    return QVariant();
}

QHash<int, QByteArray> Phonebook::roleNames() const
{
    QHash<int, QByteArray> l_contactRole;
    l_contactRole[NAMEROLE] = "name";
    l_contactRole[PHONENUMBERROLE] = "phoneNumber";
    l_contactRole[IMAGEROLE] = "profileImage";
    return l_contactRole;
}

void Phonebook::createContactData()
{
    loadFromCsv("phonebook.csv"); // Changed to use separate phonebook.csv
}

void Phonebook::insertContactData(Contact *contact)
{
    ContactDataModel::insertContactData(contact);
    saveToCsv("phonebook.csv");
}

void Phonebook::addContact(const QString &name, const QString &number, const QString &image)
{
    Contact *c = new Contact(name, number, image, this);
    insertContactData(c);
    saveToCsv("phonebook.csv");
}

void Phonebook::updateContactByPhone(const QString &oldNumber, const QString &newName, const QString &newNumber, const QString &newImage)
{
    for (int i = 0; i < m_contactList.size(); ++i) {
        if (m_contactList[i]->getContactNumber() == oldNumber) {
            m_contactList[i]->setContactName(newName);
            m_contactList[i]->setContactNumber(newNumber);
            m_contactList[i]->setContactImage(newImage);
            emit dataChanged(index(i), index(i));
            break;
        }
    }
    saveToCsv("phonebook.csv");
}

void Phonebook::deleteContactByPhone(const QString &number)
{
    for (int i = 0; i < m_contactList.size(); ++i) {
        if (m_contactList[i]->getContactNumber() == number) {
            beginRemoveRows(QModelIndex(), i, i);
            delete m_contactList.takeAt(i);
            endRemoveRows();
            break;
        }
    }
    saveToCsv("phonebook.csv");
}
