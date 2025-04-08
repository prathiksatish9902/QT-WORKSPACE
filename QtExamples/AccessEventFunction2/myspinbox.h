#ifndef MYSPINBOX_H
#define MYSPINBOX_H

#include <QSpinBox>
#include <QEvent>
#include <QPaintEvent>

class MySpinBox : public QSpinBox
{
public:
    MySpinBox();
    ~MySpinBox();

    bool event(QEvent *e) override;
    void paintEvent(QPaintEvent *event) override;
};

#endif // MYSPINBOX_H
