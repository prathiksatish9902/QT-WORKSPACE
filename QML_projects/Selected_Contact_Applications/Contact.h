#ifndef CONTACT_H
#define CONTACT_H

#include <QObject>
#include <QString>

class Contact : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString contactName READ getContactName WRITE setContactName NOTIFY contactNameChanged FINAL)
    Q_PROPERTY(QString contactNumber READ getContactNumber WRITE setContactNumber NOTIFY contactNumberChanged FINAL)
    Q_PROPERTY(QString contactImage READ getContactImage WRITE setContactImage NOTIFY contactImageChanged FINAL)
    Q_PROPERTY(QString callTime READ getCallTime WRITE setCallTime NOTIFY callTimeChanged FINAL)
    Q_PROPERTY(bool isIncoming READ getIsIncoming WRITE setIsIncoming NOTIFY isIncomingChanged FINAL)
    Q_PROPERTY(bool isOutgoing READ getIsOutgoing WRITE setIsOutgoing NOTIFY isOutgoingChanged FINAL)

public:
    explicit Contact(QObject *parent = nullptr);
    Contact(QString name, QString number, QString image = "", QObject *parent = nullptr);
    ~Contact();

    QString getContactName() const;
    void setContactName(const QString &newContactName);
    QString getContactNumber() const;
    void setContactNumber(const QString &newContactNumber);
    QString getContactImage() const;
    void setContactImage(const QString &newContactImage);
    QString getCallTime() const;
    void setCallTime(const QString &newCallTime);
    bool getIsIncoming() const;
    void setIsIncoming(bool newIsIncoming);
    bool getIsOutgoing() const;
    void setIsOutgoing(bool newIsOutgoing);

signals:
    void contactNameChanged();
    void contactNumberChanged();
    void contactImageChanged();
    void callTimeChanged();
    void isIncomingChanged();
    void isOutgoingChanged();

private:
    QString m_contactName;
    QString m_contactNumber;
    QString m_contactImage;
    QString m_callTime;
    bool m_isIncoming;
    bool m_isOutgoing;
};

#endif // CONTACT_H
