#include "MyClass.h"
#include "Button.h"
#include<iostream>
using namespace std;

template <typename T>
MyClass<T>::MyClass(T *ptr1)
{
    cout<<"MyClass Constructor"<<endl;
    m_ptr = ptr1;
}

template <typename T>
MyClass<T>::~MyClass()
{
    delete m_ptr;
    cout<<"Deleted memory"<<endl;
}

template<typename T>
T *MyClass<T>::getPtr()
{
    return m_ptr;
}

template<typename T>
T *MyClass<T>::operator->()
{
    return m_ptr;
}

template class MyClass<Button>;
template class MyClass<int>;
template class MyClass<double>;

