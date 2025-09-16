#include <iostream>
#include <thread>
using namespace std;
void search(){
    for(int i = 0; i<=100; i++)
        std::cout<<"search function called"<<i<<std::endl;
    // std::this_thread::sleep_for(std::chrono::seconds(100));
}
void search2(){
    for(int i= 100; i>0; i--)
        std::cout<<"search2 function"<<i<<std::endl;
}
int main()
{
    // search();
    auto start = std::chrono::high_resolution_clock::now();
    std::thread t1(search);
    std::thread t2(search2);
    std::cout<<"hi"<<std::endl;
    t1.join();
    t2.join();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout<<"execution time:"<<duration.count()<<std::endl;
    return 0;
}
