#ifndef DBC_H
#define DBC_H

#include "abc.h"

class DBC : public ABC
{
public:
    DBC();
    ~DBC();

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // DBC_H
