#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<stdbool.h>
#include<string.h>
int add(int x,int y)
{return x+y;}
void test (int(*p)(int ,int),int a,int b)
{
    // int x=(*p)(a,b);
    printf("%d\n",(*p)(a,b));
}
int main()
{
    int a=2;
    int b=4;
    int (*p)(int ,int)=add;//函数指针
    int c=(*p)(a,b);//函数指针调用
    printf("%d\n",c);
    test(add,c,b);//回调函数
    system("pause");
    return 0;
}
