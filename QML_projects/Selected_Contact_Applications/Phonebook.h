#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "ContactDataModel.h"

class Phonebook : public ContactDataModel
{
    Q_OBJECT
public:
    enum ContactRoles {
        NAMEROLE = Qt::UserRole + 1,
        PHONENUMBERROLE,
        IMAGEROLE
    };

    Phonebook();
    ~Phonebook();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    void createContactData() override;
    Q_INVOKABLE void addContact(const QString &name, const QString &number, const QString &image = "");
    Q_INVOKABLE void updateContactByPhone(const QString &oldNumber, const QString &newName, const QString &newNumber, const QString &newImage = "");
    Q_INVOKABLE void deleteContactByPhone(const QString &number);

private:
    void insertContactData(Contact *contact) override;
};

#endif // PHONEBOOK_H
