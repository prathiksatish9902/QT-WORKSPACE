#ifndef CONTACTMODEL_H
#define CONTACTMODEL_H

#include <QAbstractListModel>
#include <QDebug>
#include "Contact.h"

class ContactModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(QList<Contact *> contactList READ getContactList WRITE setContactList NOTIFY contactListChanged FINAL)

public:
    explicit ContactModel(QObject *parent = nullptr);
    ~ContactModel();

    // QAbstractItemModel interface
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;

    QList<Contact *> getContactList() const;
    void setContactList(const QList<Contact *> &newContactList);

    Q_INVOKABLE int getListSize();
    Q_INVOKABLE void addNumberButtonClicked();

    enum ContactDataModel
    {
        CONTACT_NAME = 1,
        CONTACT_NUMBER
    };

signals:
    void contactListChanged();

private:
    QList<Contact*> m_contactList;

};

#endif // CONTACTMODEL_H
