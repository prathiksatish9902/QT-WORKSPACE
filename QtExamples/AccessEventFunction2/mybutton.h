#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>
#include <QEvent>
#include <QPaintEvent>
class MyButton : public QPushButton
{
public:
    MyButton();
    ~MyButton();
    bool event(QEvent *e) override;
    void paintEvent(QPaintEvent *event) override;
};

#endif // MYBUTTON_H
