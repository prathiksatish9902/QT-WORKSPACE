#ifndef MYCHECKBOX_H
#define MYCHECKBOX_H

#include <QCheckBox>
#include <QEvent>
#include <QPaintEvent>
class MyCheckBox : public QCheckBox
{
public:
    MyCheckBox();
    ~MyCheckBox();

    bool event(QEvent *e) override;
    void paintEvent(QPaintEvent *event) override;
};

#endif // MYCHECKBOX_H
