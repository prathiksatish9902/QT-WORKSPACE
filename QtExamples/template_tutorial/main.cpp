#include <iostream>
using namespace std;

template <typename T>
class MyClass{
public:
    MyClass(T a1 , T b1){ a = a1;
    b = b1;
    }
    T a;
    T b;
    static int count;
    void printValues(){
        a = 10;
        b = 5;
        count++;
        cout<<a<<endl;
        cout<<b<<endl;
        cout<<count;
    }
};
template <typename T>
void add(){
    // return a + b;
    // const T count = 10;
    // // count++;
    // cout<<count<<endl;
    // return 1;
}
template <typename T>
int MyClass<T>:: count =0;
int main()
{
    cout << "Hello World!" << endl;


    // add<int>();
    // add<float>();
    // add<double>();

    MyClass <int> entity(10 , 20);
    entity.printValues();

    MyClass <float> entity1(15.5 , 20.5);
    entity1.printValues();
    return 0;
}
