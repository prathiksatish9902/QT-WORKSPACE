#include "mainwindow.h"
#include <QSlider>
#include <QLineEdit>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    slider = new QSlider(Qt::Horizontal, this);
    slider->setRange(0, 100);

    textField = new QLineEdit(this);
    textField->setReadOnly(true);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(slider);
    layout->addWidget(textField);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    connect(slider, &QSlider::valueChanged, this, &MainWindow::updateTextField);
}

MainWindow::~MainWindow()
{
    delete slider;
    delete textField;

}

void MainWindow::updateTextField(int value)
{
    textField->setText(QString::number(value));
}
