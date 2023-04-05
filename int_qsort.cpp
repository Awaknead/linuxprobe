#include<stdio.h>
#include<stdlib.h>
// void qsort (void* base,   //目标数组的起始位置
//             size_t num,   //数组的大小（元素）
//             size_t width, //元素的大小（字节）
//             int (*cmp)(const void* e1,const void* e2)  //比较函数（两个比较值的地址）
//             );
//             // void* 类型的指针 可以接收任意类型地址
//             // void* 不能接引用操作
//             // void* 不能进行+ -整数的操作

// 以下是qsor整形数组快速排序
int cmp_int (const void* e1,const void* e2)
{
    // 比较两个值
    return *(int*)e1-*(int*)e2;
}
void test1()
{
    int arr[]={19,3,23,6,11,8,12,10,7,5};
    int sz=sizeof(arr)/sizeof(arr[0]);
    qsort(arr,sz,sizeof(arr[0]),cmp_int);
    for(int x=0;x<sz;x++)
    {
        printf("arr[%d]=%d.\n",x,arr[x]);
    }    
}
// 以下是qsort浮点型数组快速排序
int cmp_float(const void*e1,const void* e2)
{
    // if(*(float*)e1 == *(float*)e2)
    //    return 0;
    // else if(*(float*)e1 > *(float*)e2)
    //      return 1;
    // else
    //      return -1;
    return (int (*(float*)e1-*(float*)e2));
}
void test2()
{
    float drr[]={0.3,3.3,6.2,8.8,1.8,0.1,8.2};
    int sz=sizeof(drr)/sizeof(drr[0]);
    qsort(drr,sz,sizeof(drr[0]),cmp_float);
    for(int x=0;x<sz;x++)
    {
        printf("drr[%d]=%.2f.\n",x,drr[x]);
    }
}
struct srt
{
    char name[20];
    int age;
};
void test3()
{
    struct srt s[]={{"zhangshan",20},{"lisi",18},{"foutejia",23}};
    
}
int main()
{
    // qsort函数的调用test(测试)
    test1();
    putchar('\n');
    test2();
    system("pause");
    return 0;
}