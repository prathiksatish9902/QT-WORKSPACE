#include "Button.h"
#include "MyClass.h"
#include<iostream>
using namespace std;

int main()
{
    int* ptr= new int;
    MyClass<int> m1(ptr);
    cout<<*ptr<<endl;
    MyClass<double> m2(new double);

    MyClass<Button> btnPtr(new Button(10));
    //btnPtr.getPtr()->print();
    btnPtr->print();
    return 0;
}
