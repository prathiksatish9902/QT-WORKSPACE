#include "mywidget.h"
#include "mybutton.h"
#include "mycheckbox.h"
#include "myradiobutton.h"
#include "mytoolbutton.h"
#include  "myslider.h"
#include "myscrollbar.h"
#include "mydial.h"
#include "myspinbox.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QEvent *e;
    QPaintEvent *event;
    MyWidget w;
    w.show();

    MyButton button1;
    button1.event(e);
    button1.paintEvent(event);
    qDebug()<<"----------------------------------------------";
    MyCheckBox checkbox;
    checkbox.event(e);
    checkbox.paintEvent(event);
    qDebug()<<"----------------------------------------------";

    MyRadioButton radiobutton;
    radiobutton.event(e);
    radiobutton.paintEvent(event);
    qDebug()<<"----------------------------------------------";

    MyToolButton toolbutton;
    toolbutton.event(e);
    toolbutton.paintEvent(event);
    qDebug()<<"----------------------------------------------";


    MySlider slider;
    slider.event(e);
    slider.paintEvent(event);
    qDebug()<<"----------------------------------------------";

    MyScrollBar scrollbar;
    scrollbar.event(e);
    scrollbar.paintEvent(event);
    qDebug()<<"----------------------------------------------";


    MyDial dial;
    dial.event(e);
    dial.paintEvent(event);
    qDebug()<<"----------------------------------------------";

    MySpinBox spinbox;
    spinbox.event(e);
    spinbox.paintEvent(event);
    qDebug()<<"----------------------------------------------";



    return a.exec();
}
