#include "abc.h"
#include <QDebug>

ABC::ABC(QWidget *parent)
    : QWidget{parent}
{
    qDebug()<<"abc constructor  called";

}

ABC::~ABC()
{
    qDebug()<<"abc destructor  called";

}

void ABC::paintEvent()
{
    qDebug()<<"abc paint event function called";
}
