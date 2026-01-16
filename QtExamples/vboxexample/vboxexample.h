#ifndef VBOXEXAMPLE_H
#define VBOXEXAMPLE_H

#include <QWidget>

class QPushButton;
class QVBoxLayout;

class VBoxExample : public QWidget
{
    Q_OBJECT

public:
    explicit VBoxExample(QWidget *parent = nullptr);

private slots:
    void removeSecondButton();

private:
    QVBoxLayout *layout;
    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button3;
    QPushButton *removeButton;
};

#endif // VBOXEXAMPLE_H
