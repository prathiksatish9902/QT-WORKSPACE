#ifndef CONTACTMODEL_H
#define CONTACTMODEL_H

#include <QAbstractListModel>
#include <Contact.h>

class ContactModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int count READ count NOTIFY countChanged)

public:
    ContactModel(QObject *parent = nullptr);
    int count() const;

    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;

    Q_INVOKABLE void addContact(const QString &name , const QString &phoneNumber);
    Q_INVOKABLE void deleteContactByPhone(const QString &phone);
    Q_INVOKABLE void updateContactByPhone(const QString &oldPhone, const QString &newName, const QString &newPhone);

    enum ContactRole{
        NAMEROLE = Qt::UserRole + 1,
        PHONENUMBERROLE
    };

signals:
    void countChanged();

private:
    QList<Contact*> m_contactList;

};

#endif // CONTACTMODEL_H
