#include "firstclass.h"

FirstClass::FirstClass(QObject *parent)
    : QObject{parent}
{
    qDebug()<<Q_FUNC_INFO;

// setApplicationName("new Application");
}

FirstClass::~FirstClass()
{
    qDebug()<<Q_FUNC_INFO;
}

QString FirstClass::getapplicationName() const
{
    return m_applicationName;
}

void FirstClass::setApplicationName(const QString &newApplicationName)
{
    m_applicationName = newApplicationName;
    emit signalEmitt();

}
