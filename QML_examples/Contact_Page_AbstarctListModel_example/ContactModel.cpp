#include "ContactModel.h"

ContactModel::ContactModel(QObject *parent)
    : QAbstractListModel{parent}
{
    m_contactList.push_back(new Contact("John Smith1", "+1-555-0123"));
    m_contactList.push_back(new Contact("John Smith2", "+1-555-0123"));
    m_contactList.push_back(new Contact("John Smith3", "+1-555-0123"));
    m_contactList.push_back(new Contact("John Smith4", "+1-555-0123"));
    m_contactList.push_back(new Contact("John Smith5", "+1-555-0123"));
    m_contactList.push_back(new Contact("John Smith6", "+1-555-0123"));
    m_contactList.push_back(new Contact("John Smith7", "+1-555-0123"));
    m_contactList.push_back(new Contact("John Smith8", "+1-555-0123"));
    m_contactList.push_back(new Contact("John Smith9", "+1-555-0123"));
    m_contactList.push_back(new Contact("John Smith10", "+1-555-0123"));

    qDebug()<<"in constructor"<< m_contactList.size();
}


ContactModel::~ContactModel()
{

}

int ContactModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_contactList.size();
}

QVariant ContactModel::data(const QModelIndex &index, int role) const
{
    const Contact *contact = m_contactList.at(index.row());

    switch(role)
    {
    case CONTACT_NAME:
        return contact->getContactName();

    case CONTACT_NUMBER:
        return contact->getContactNumber();

    default:
        return QVariant();
    }
    return QVariant();
}

QHash<int, QByteArray> ContactModel::roleNames() const
{
    QHash<int , QByteArray> l_roleNames;
    l_roleNames.insert(CONTACT_NAME , "contactName");
    l_roleNames.insert(CONTACT_NUMBER, "contactNumber");
    return l_roleNames;
}

QList<Contact *> ContactModel::getContactList() const
{
    return m_contactList;
}

void ContactModel::setContactList(const QList<Contact *> &newContactList)
{
    if (m_contactList == newContactList)
        return;
    m_contactList = newContactList;
    emit contactListChanged();
}



int ContactModel::getListSize()
{
    return m_contactList.size();
}



void ContactModel::addNumberButtonClicked()
{
    emit this->beginResetModel();
    m_contactList.push_back(new Contact("John Smith11", "+1-555-0123"));
    m_contactList.push_back(new Contact("John Smith12", "+1-555-0123"));
    m_contactList.push_back(new Contact("John Smith13", "+1-555-0123"));
    m_contactList.push_back(new Contact("John Smith14", "+1-555-0123"));
    m_contactList.push_back(new Contact("John Smith15", "+1-555-0123"));
    emit this->endResetModel();
    qDebug()<<"in function"<< m_contactList.size();
    // emit contactListChanged();
}

