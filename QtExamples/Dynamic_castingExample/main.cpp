#include <iostream>
#include"a.h"
#include"b.h"
#include"c.h"
using namespace std;

int main()
{
    A *aptr;
    B b1;
    B *bptr;
    C c1;
    aptr = &c1;
    std::cout<<"hi"<<std::endl;
    aptr->display();
    bptr = dynamic_cast <B*> (aptr);
    if(bptr == NULL)
    {
        std::cout<<"invalid"<<std::endl;
    }
    else
    {
        std::cout<<"bye"<<std::endl;

        bptr->display();
    }
    return 0;
}
