#include <iostream>
#include"b.h"
using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    A *ptr = new B;
    delete ptr;
    return 0;
}
