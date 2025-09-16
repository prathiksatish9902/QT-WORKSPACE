#ifndef CONTACTMODEL_H
#define CONTACTMODEL_H

#include <QObject>
#include "Contact.h"

class ContactModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<Contact *> contactList READ getContactList CONSTANT)

public:
    explicit ContactModel(QObject *parent = nullptr);
    ~ContactModel();

    QList<Contact *> getContactList() const;
    void setContactList(const QList<Contact *> &newContactList);
    Q_INVOKABLE int getListSize();
    Q_INVOKABLE void addNumberButtonClicked();

signals:

    void contactListChanged();

private:
    Contact *m_contact;
    QList<Contact*> m_contactList;

};

#endif // CONTACTMODEL_H
