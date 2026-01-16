#include "a.h"

A::A() {
    std::cout<<"default constructor"<<std::endl;
}

A::A(int a)
{
    std::cout<<"parameter constructor"<<std::endl;

}

A::A(int b = 0){
    std::cout<<"nullptr constructor"<<std::endl;

}
