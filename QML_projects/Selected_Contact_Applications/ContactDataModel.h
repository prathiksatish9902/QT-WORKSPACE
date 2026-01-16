#ifndef CONTACTDATAMODEL_H
#define CONTACTDATAMODEL_H

#include <QAbstractListModel>
#include "Contact.h"

class ContactDataModel : public QAbstractListModel
{
    Q_OBJECT
public:
    ContactDataModel();
    ~ContactDataModel();

    virtual void createContactData() = 0;
    virtual void insertContactData(Contact*);
    Contact* getContactData(int index);

    void saveToCsv(const QString &filename) const;
    void loadFromCsv(const QString &filename);

protected:
    QList<Contact*> m_contactList;
};

#endif // CONTACTDATAMODEL_H
