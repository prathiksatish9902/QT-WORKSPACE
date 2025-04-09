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
// #include <QSlider>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MyWidget w;
    w.show();
    MyButton pushbutton;
    QPushButton *button1 = &pushbutton;

    button1->show();


    qDebug()<<"----------------------------------------------";
    MyCheckBox cb;
    QCheckBox *checkbox = &cb;

    checkbox->show();
    qDebug()<<"----------------------------------------------";
    MyRadioButton rb;
    QRadioButton *radiobutton = &rb ;

    radiobutton->show();
    qDebug()<<"----------------------------------------------";
    MyToolButton tb;
    QToolButton *toolbutton = &tb ;

    toolbutton->show();
    qDebug()<<"----------------------------------------------";

    MySlider sl;
    QSlider *slider = &sl ;

    slider->show();
    qDebug()<<"----------------------------------------------";
    MyScrollBar sb;
    QScrollBar *scrollbar = &sb ;

    scrollbar->show();
    qDebug()<<"----------------------------------------------";

    MyDial dl;
    QDial *dial = &dl ;

    dial->show();
    qDebug()<<"----------------------------------------------";
    MySpinBox spb;
    QSpinBox *spinbox = &spb ;

    spinbox->show();
    qDebug()<<"----------------------------------------------";


    // delete w;
    // delete button1;
    // delete checkbox;
    // delete dial;
    // delete radiobutton;
    // delete scrollbar;
    // delete slider;
    // delete spinbox;
    // delete toolbutton;







    return a.exec();
}
