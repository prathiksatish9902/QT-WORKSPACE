#include "ContactDataModel.h"
#include <QFile>
#include <QTextStream>

ContactDataModel::ContactDataModel() {}

ContactDataModel::~ContactDataModel()
{
    qDeleteAll(m_contactList);
}

void ContactDataModel::insertContactData(Contact *contact)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_contactList.append(contact);
    endInsertRows();
}

Contact *ContactDataModel::getContactData(int index)
{
    if (index < 0 || index >= m_contactList.count()) return nullptr;
    return m_contactList.at(index);
}

void ContactDataModel::saveToCsv(const QString &filename) const
{
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) return;
    QTextStream out(&file);
    out << "name,phoneNumber,profileImage,callTime,isIncoming,isOutgoing\n";
    for (Contact *c : m_contactList) {
        out << c->getContactName() << ","
            << c->getContactNumber() << ","
            << c->getContactImage() << ","
            << c->getCallTime() << ","
            << (c->getIsIncoming() ? "true" : "false") << ","
            << (c->getIsOutgoing() ? "true" : "false") << "\n";
    }
    file.close();
}

void ContactDataModel::loadFromCsv(const QString &filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;
    QTextStream in(&file);
    if (in.atEnd()) {
        file.close();
        return;
    }
    in.readLine(); // Skip header
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        if (fields.size() < 6) continue;

        for (int i = 0; i < fields.size(); ++i) {
            fields[i] = fields[i].trimmed();
            if (fields[i].startsWith("\"") && fields[i].endsWith("\"")) {
                fields[i] = fields[i].mid(1, fields[i].length() - 2);
            }
        }

        Contact *c = new Contact(fields[0], fields[1], fields[2], this);
        c->setCallTime(fields[3]);
        c->setIsIncoming(fields[4] == "true");
        c->setIsOutgoing(fields[5] == "true");
        insertContactData(c);
    }
    file.close();
}
