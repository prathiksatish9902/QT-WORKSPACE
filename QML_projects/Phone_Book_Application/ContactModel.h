#ifndef CONTACTMODEL_H
#define CONTACTMODEL_H

#include <QAbstractListModel>
#include <Contact.h>

class ContactModel : public QAbstractListModel
{
    Q_OBJECT
public:
    ContactModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;

    Q_INVOKABLE void addContact(const QString &name , const QString &phoneNumber);
    Q_INVOKABLE void deleteContact(int index);
    Q_INVOKABLE void editContact(int index , const QString &name , const QString &phoneNumber);
    Q_INVOKABLE QVariantMap get(int index);

    enum ContactRole{
        NAMEROLE = 1,
        PHONENUMBERROLE
    };

private:
    QList<Contact*> m_contactList;

};

#endif // CONTACTMODEL_H
