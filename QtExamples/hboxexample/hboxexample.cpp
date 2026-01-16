#include "hboxexample.h"
#include <QPushButton>
#include <QHBoxLayout>

HBoxExample::HBoxExample(QWidget *parent)
    : QWidget(parent)
{
    layout = new QHBoxLayout(this);

    button1 = new QPushButton("Button 1", this);
    button2 = new QPushButton("Button 2", this);
    button3 = new QPushButton("Button 3", this);
    removeButton = new QPushButton("Remove Button 2", this);

    layout->addWidget(button1);
    layout->addSpacing(10); // Add spacing between buttons
    layout->addWidget(button2);
    layout->addStretch();   // Add stretchable space
    layout->addWidget(button3);
    layout->addWidget(removeButton);

    connect(removeButton, &QPushButton::clicked, this, &HBoxExample::removeSecondButton);
}

void HBoxExample::removeSecondButton()
{
    // Remove button2 from the layout
    layout->removeWidget(button2);

    // Optionally hide and delete the button
    // button2->hide();
    // button2->deleteLater();
    button2->move(50,50);
}
