#include "widget.h"
#include "ui_widget.h"
#include <QPaintEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    qDebug() << "widget constructor called";
    ui->setupUi(this);
}

Widget::~Widget()
{
    qDebug() << "widget destructor called";
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    qDebug() << "widget paint event function called";
    // Call the base class implementation if needed
    QWidget::paintEvent(event);
}
