#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <vector>
class Student
{

public:
    std::string m_name;
    int m_age;
    std::string m_rollNum;
    Student(std::string name , int age , std::string rollNum);
    Student(const Student &s);
    ~Student();
};

#endif // STUDENT_H
