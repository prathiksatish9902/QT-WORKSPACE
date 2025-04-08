#include "mywidget.h"
#include "ui_mywidget.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    qDebug()<<"my widget constructor called";
    ui->setupUi(this);
}

MyWidget::~MyWidget()
{
    qDebug()<<"my widget destructor called";
    delete ui;

}
