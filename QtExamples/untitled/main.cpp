#include "mywidget.h"
#include<QPushButton>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWidget w;
    QPushButton *button=new QPushButton("1",&w);
    QPushButton *button1=new QPushButton("2",&w);

    // button1->setGeometry(x,y,width,height);

    button1->setGeometry(30,0,40,40);

    w.show();
    return a.exec();
}
