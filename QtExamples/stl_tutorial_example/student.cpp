#include "student.h"

Student::Student(std::string name , int age , std::string rollNum) {
    m_name = name;
    m_age = age;
    m_rollNum = rollNum;
}

Student::Student(const Student &s)
{
    std::cout<<"copy constructor"<<std::endl;
}

Student::~Student()
{

}
