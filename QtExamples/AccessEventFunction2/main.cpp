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

    MyWidget w;
    w.show();
    // MyButton pushbutton;
    // QPushButton *button1 = &pushbutton;

    // button1->show();


    // qDebug()<<"----------------------------------------------";
    // MyCheckBox cb;
    // QCheckBox *checkbox = &cb;

    // checkbox->show();
    // qDebug()<<"----------------------------------------------";
    // MyRadioButton rb;
    // QRadioButton *radiobutton = &rb ;

    // radiobutton->show();
    // qDebug()<<"----------------------------------------------";
    // MyToolButton tb;
    // QToolButton *toolbutton = &tb ;

    // toolbutton->show();
    // qDebug()<<"----------------------------------------------";

    // MySlider sl;
    // QSlider *slider = &sl ;

    // slider->show();
    // qDebug()<<"----------------------------------------------";
    // MyScrollBar sb;
    // QScrollBar *scrollbar = &sb ;

    // scrollbar->show();
    // qDebug()<<"----------------------------------------------";

    // MyDial dl;
    // QDial *dial = &dl ;

    // dial->show();
    // qDebug()<<"----------------------------------------------";
    // MySpinBox spb;
    // QSpinBox *spinbox = &spb ;

    // spinbox->show();
    // qDebug()<<"----------------------------------------------";
    qDebug()<<"----------------------------------------------";

    QPushButton *pushbutton1 = new MyButton;
    MyButton *pushbutton2 = dynamic_cast <MyButton*> (pushbutton1);
    if(pushbutton2)
    {
        pushbutton2->show();
    }
    else
    {
        qDebug()<<"downcasting failed";
    }
    qDebug()<<"----------------------------------------------";
    QCheckBox *checkbox1 = new MyCheckBox;
    MyCheckBox *checkbox2 = dynamic_cast <MyCheckBox*> (checkbox1);
    if(checkbox2)
    {
        checkbox2->show();
    }
    else
    {
        qDebug()<<"downcasting failed";
    }
    qDebug()<<"----------------------------------------------";

    QRadioButton *radiobutton1 = new MyRadioButton;
    MyRadioButton *radiobutton2 = dynamic_cast <MyRadioButton*> (radiobutton1);
    if(radiobutton2)
    {
        radiobutton2->show();
    }
    else
    {
        qDebug()<<"downcasting failed";
    }
    qDebug()<<"----------------------------------------------";

    QToolButton *toolbutton1 = new MyToolButton;
    MyToolButton *toolbutton2 = dynamic_cast <MyToolButton*> (toolbutton1);
    if(toolbutton2)
    {
        toolbutton2->show();
    }
    else
    {
        qDebug()<<"downcasting failed";
    }
    qDebug()<<"----------------------------------------------";

    QSlider *slider1 = new MySlider;
    MySlider *slider2 = dynamic_cast <MySlider*> (slider1);
    if(slider2)
    {
        slider2->show();
    }
    else
    {
        qDebug()<<"downcasting failed";
    }
    qDebug()<<"----------------------------------------------";

    QScrollBar *scrollbar1 = new MyScrollBar;
    MyScrollBar *scrollbar2 = dynamic_cast <MyScrollBar*> (scrollbar1);
    if(scrollbar2)
    {
        scrollbar2->show();
    }
    else
    {
        qDebug()<<"downcasting failed";
    }
    qDebug()<<"----------------------------------------------";

    QDial *dial1 = new MyDial;
    MyDial *dial2 = dynamic_cast <MyDial*> (dial1);
    if(dial2)
    {
        dial2->show();
    }
    else
    {
        qDebug()<<"downcasting failed";
    }
    qDebug()<<"----------------------------------------------";

    QSpinBox *spinbox1 = new MySpinBox;
    MySpinBox *spinbox2 = dynamic_cast <MySpinBox*> (spinbox1);
    if(spinbox2)
    {
        spinbox2->show();
    }
    else
    {
        qDebug()<<"downcasting failed";
    }
    qDebug()<<"----------------------------------------------";

    // delete pushbutton1;
    // delete checkbox1;

    return a.exec();
}
