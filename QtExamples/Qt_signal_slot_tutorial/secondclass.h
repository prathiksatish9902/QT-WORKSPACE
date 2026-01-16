#ifndef SECONDCLASS_H
#define SECONDCLASS_H

#include "firstclass.h"

class SecondClass : public FirstClass
{
public:
    FirstClass fclass;

    explicit SecondClass(QObject *parent = nullptr);
    ~SecondClass();

public slots:
    void onApplicationChanged();
};

#endif // SECONDCLASS_H
