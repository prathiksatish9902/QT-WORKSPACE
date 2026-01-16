#include <stdio.h>
// void search(int array);
// void search(int array){
// printf("%d \n",array);
// }

struct Student{
char m_studentName[10];
int rollNumber;
};

void search(char stuName[] , int rollNum);
void search(char stuName[], int rollNum){
printf("%s , %d\n",stuName, &rollNum);
}
int main()
{
//     printf("Hello World!\n");
// int arr[10] = {1,2,3,4,5,6,7,8,9,10};
// printf("%d \n",arr);

// search(arr);

struct Student s1 = {"darshan" , 5};
search(&s1.m_studentName, &s1.rollNumber);
    return 0;
}
