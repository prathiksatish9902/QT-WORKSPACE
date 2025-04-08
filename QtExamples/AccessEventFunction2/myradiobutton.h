#ifndef MYRADIOBUTTON_H
#define MYRADIOBUTTON_H

#include <QRadioButton>
#include <QEvent>
#include <QPaintEvent>
class MyRadioButton : public QRadioButton
{
public:
    MyRadioButton();
    ~MyRadioButton();

    bool event(QEvent *e) override;
    void paintEvent(QPaintEvent *event) override;
};

#endif // MYRADIOBUTTON_H
