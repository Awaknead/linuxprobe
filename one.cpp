#include<stdio.h>
#include<stdlib.h>
int add(int x,int y)
{return x+y;}
int main ()
{
    int a=1;
    int b=2;
    int(*p)(int ,int)=add;
    int c=(*p)(a,b);
    printf("%d.\n",c);
    printf("Holle wrold.\n");
    system("pause");
    return 0;
}