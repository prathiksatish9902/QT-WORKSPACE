#include "c.h"

C::C() {
    std::cout<<"c constructor called"<<std::endl;

}

C::~C()
{
    std::cout<<"c destructor called"<<std::endl;

}

void C::display()
{
    std::cout<<"c display called"<<std::endl;
    std::cout<<"anurag"<<std::endl;
}
