#ifndef MYDIAL_H
#define MYDIAL_H

#include <QDial>
#include <QEvent>
#include <QPaintEvent>
class MyDial : public QDial
{
public:
    MyDial();
    ~MyDial();

    bool event(QEvent *e) override;
    void paintEvent(QPaintEvent *event) override;
};

#endif // MYDIAL_H
