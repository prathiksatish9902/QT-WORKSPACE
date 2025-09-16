#include "ContactModel.h"
#include <algorithm>

ContactModel::ContactModel(QObject *parent) : QAbstractListModel(parent) {
    m_contactList.append(new Contact("Alice Smith", "1234567890", this));
    m_contactList.append(new Contact("Bob Johnson", "9876543210", this));
    m_contactList.append(new Contact("Charlie Brown", "5551234567", this));
    std::sort(m_contactList.begin(), m_contactList.end(), [](Contact *a, Contact *b) {
        return a->getName().toLower() < b->getName().toLower();
    });
}

int ContactModel::rowCount(const QModelIndex &parent) const
{
    return m_contactList.count();
}

QVariant ContactModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= m_contactList.size())
        return QVariant();

    Contact *contact = m_contactList.at(index.row());
    switch (role) {
    case NAMEROLE:
        return contact->getName();
    case PHONENUMBERROLE:
        return contact->getPhoneNumber();
    }
    return QVariant();
}

QHash<int, QByteArray> ContactModel::roleNames() const
{
    QHash<int, QByteArray> l_contactRole;
    l_contactRole[NAMEROLE] = "name";
    l_contactRole[PHONENUMBERROLE] = "phoneNumber";
    return l_contactRole;
}

void ContactModel::addContact(const QString &name, const QString &phoneNumber)
{
    int insertIndex = 0;
    for (; insertIndex < m_contactList.size(); ++insertIndex) {
        if (m_contactList[insertIndex]->getName().toLower() > name.toLower()) {
            break;
        }
    }

    beginInsertRows(QModelIndex(), insertIndex, insertIndex);
    m_contactList.insert(insertIndex, new Contact(name, phoneNumber, this));
    endInsertRows();
}

void ContactModel::deleteContact(int index)
{
    if (index < 0 || index >= m_contactList.size())
        return;

    beginRemoveRows(QModelIndex(), index, index);
    Contact *contact = m_contactList.takeAt(index);
    contact->deleteLater();
    endRemoveRows();
}

void ContactModel::editContact(int index, const QString &name, const QString &phoneNumber)
{
    if (index < 0 || index >= m_contactList.size())
        return;

    Contact *contact = m_contactList.at(index);
    bool nameChanged = contact->getName() != name;

    contact->setName(name);
    contact->setPhoneNumber(phoneNumber);
    emit dataChanged(this->index(index), this->index(index));

    if (nameChanged) {
        beginResetModel();
        std::sort(m_contactList.begin(), m_contactList.end(), [](Contact *a, Contact *b) {
            return a->getName().toLower() < b->getName().toLower();
        });
        endResetModel();
    }
}

QVariantMap ContactModel::get(int index)
{
    QVariantMap map;
    if (index < 0 || index >= m_contactList.size())
        return map;
    const Contact *contact = m_contactList.at(index);
    map["name"] = contact->getName();
    map["phone"] = contact->getPhoneNumber();
    return map;
}
