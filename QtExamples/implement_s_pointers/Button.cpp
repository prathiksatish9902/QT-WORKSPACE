#include "Button.h"
#include<iostream>
using namespace std;

Button::Button(int length)
{
    m_length = length;
}

void Button::print()
{
    cout<<"Length is: "<<m_length<<endl;
}
