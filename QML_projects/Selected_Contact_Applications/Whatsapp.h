#ifndef WHATSAPP_H
#define WHATSAPP_H

#include "ContactDataModel.h"

class Whatsapp : public ContactDataModel
{
    Q_OBJECT
public:
    enum ContactRoles {
        NAMEROLE = Qt::UserRole + 1,
        PHONENUMBERROLE,
        IMAGEROLE,
        MESSAGETIMEROLE,
        INCOMINGROLE,
        OUTGOINGROLE
    };

    Whatsapp();
    ~Whatsapp();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    void createContactData() override;
};

#endif // WHATSAPP_H
