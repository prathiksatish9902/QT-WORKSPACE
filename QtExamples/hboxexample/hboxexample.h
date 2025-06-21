#ifndef HBOXEXAMPLE_H
#define HBOXEXAMPLE_H

#include <QWidget>

class QPushButton;
class QHBoxLayout;

class HBoxExample : public QWidget
{
    Q_OBJECT

public:
    explicit HBoxExample(QWidget *parent = nullptr);

private slots:
    void removeSecondButton();

private:
    QHBoxLayout *layout;
    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button3;
    QPushButton *removeButton;
};

#endif // HBOXEXAMPLE_H
