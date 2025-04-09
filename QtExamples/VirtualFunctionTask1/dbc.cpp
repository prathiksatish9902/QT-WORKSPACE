#include "dbc.h"
#include <QDebug>
#include <QPaintEvent>

DBC::DBC() {
    qDebug() << "dbc constructor called";
}

DBC::~DBC()
{
    qDebug() << "dbc destructor called";
}

void DBC::paintEvent(QPaintEvent *event)
{
    qDebug() << "dbc paint event called";
    ABC::paintEvent(event);
}
