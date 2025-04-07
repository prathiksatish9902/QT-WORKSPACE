#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    qDebug()<<"widget constructor called";
    ui->setupUi(this);
}

Widget::~Widget()
{
    qDebug()<<"widget destructor called";

    delete ui;
}

void Widget::paintEvent()
{
    qDebug()<<"widget paint event function called";
}
