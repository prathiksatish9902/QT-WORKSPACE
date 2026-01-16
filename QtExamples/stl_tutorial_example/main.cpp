#include <iostream>
#include "student.h"
using namespace std;

int main()
{
    Student s1("darshan", 7 , "12123");
    Student s2("girish" , 5 , "9879");
    Student s3(s1);

    std::vector<Student> studentList;
    std::cout<<"list size:"<<studentList.size()<<std::endl;
    studentList.push_back(s1);
    studentList.push_back(s2);
    std::cout<<"list size:"<<studentList.size()<<std::endl;

    for(auto &list : studentList)
    {
        std::cout<<studentList.begin()->m_name<<std::endl;

        std::cout<<list.m_name<<list.m_age<<list.m_rollNum<<std::endl;
    }
    return 0;
}
