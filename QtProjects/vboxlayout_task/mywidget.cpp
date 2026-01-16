#include "mywidget.h"
#include <QPushButton>
#include <QVBoxLayout>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    // Create buttons
    QPushButton *button1 = new QPushButton("Button 1", this);
    QPushButton *button2 = new QPushButton("Button 2", this);
    QPushButton *button3 = new QPushButton("Button 3", this);

    // Create layout and add buttons
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(button1);
    vbox->addWidget(button2);
    vbox->addWidget(button3);

    // Set layout to this widget
    setLayout(vbox);
}
