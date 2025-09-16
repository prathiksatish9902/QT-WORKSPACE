#include "secondclass.h"

SecondClass::SecondClass(QObject *parent)
    : FirstClass{parent}
{
    qDebug()<<Q_FUNC_INFO;

    // FirstClass *obj = new FirstClass;
    connect(&fclass , &FirstClass::signalEmitt , this , &SecondClass::onApplicationChanged);
    fclass.setApplicationName("new");
}

SecondClass::~SecondClass()
{
    qDebug()<<Q_FUNC_INFO;
}

void SecondClass::onApplicationChanged()
{
    qDebug()<<"signal received";
}
