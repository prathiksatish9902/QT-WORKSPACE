#ifndef MYTOOLBUTTON_H
#define MYTOOLBUTTON_H

#include <QToolButton>
#include <QEvent>
#include <QPaintEvent>
class MyToolButton : public QToolButton
{
public:
    MyToolButton();
    ~MyToolButton();

    bool event(QEvent *e) override;
    void paintEvent(QPaintEvent *event) override;
};

#endif // MYTOOLBUTTON_H
