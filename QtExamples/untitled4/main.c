#include <stdio.h>

int main()
{
    printf("Hello World!\n");
int a[10];
int *p;
int *q;
int *r;
p = a;
printf("%u\n",p);

++p;
printf("%u\n",p);

q = a+1;
r = a+2;
printf("%u\n",p);
printf("%u",q);
printf("\n%u",r);
printf("\n%u",a);
    return 0;
}
