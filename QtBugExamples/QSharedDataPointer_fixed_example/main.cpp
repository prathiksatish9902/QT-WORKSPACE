#include "employee.h"
#include "employeedata.h"
int main(int argc, char *argv[])
{
    Employee e1(1001, "Albrecht Durer");
    Employee e2 = e1;
    e1.setName("Hans Holbein");

}
