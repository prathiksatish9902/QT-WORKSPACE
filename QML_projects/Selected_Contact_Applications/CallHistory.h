#ifndef CALLHISTORY_H
#define CALLHISTORY_H

#include "ContactDataModel.h"

class CallHistory : public ContactDataModel
{
    Q_OBJECT
public:
    enum ContactRoles {
        NAMEROLE = Qt::UserRole + 1,
        PHONENUMBERROLE,
        IMAGEROLE,
        CALLTIMEROLE,
        INCOMINGROLE,
        OUTGOINGROLE
    };

    CallHistory();
    ~CallHistory();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    void createContactData() override;
    void insertContactData(Contact *contact) override;

    // New function to add outgoing call to call history
    Q_INVOKABLE void addOutgoingCall(const QString &name, const QString &number, const QString &image);

};

#endif // CALLHISTORY_H
