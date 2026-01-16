#include "ContactModel.h"
#include <QDebug>

ContactModel::ContactModel(QObject *parent)
    : QObject{parent}
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
    m_contactList.push_back(new Contact("John Smith11", "+1-555-0123"));
    m_contactList.push_back(new Contact("John Smith12", "+1-555-0123"));
    m_contactList.push_back(new Contact("John Smith13", "+1-555-0123"));
    m_contactList.push_back(new Contact("John Smith14", "+1-555-0123"));
    m_contactList.push_back(new Contact("John Smith15", "+1-555-0123"));

    qDebug()<<"in function"<< m_contactList.size();
    emit contactListChanged();
}
