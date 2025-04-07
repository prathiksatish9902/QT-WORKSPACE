#include "dbc.h"
#include <QDebug>

DBC::DBC() {
    qDebug()<<"dbc constructor  called";

}

DBC::~DBC()
{
    qDebug()<<"dbc destructor  called";

}

void DBC::paintEvent()
{
    qDebug()<<"dbc paint event called";
}
