#ifndef MYCLASS_H
#define MYCLASS_H
template <typename T>

class MyClass
{
public:
    MyClass(T* ptr);
    ~MyClass();
    T* getPtr();
    T* operator->();

private:
    T* m_ptr;
};

#endif // MYCLASS_H
