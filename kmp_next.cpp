//next数组
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//next数组求值
void GetNext(char *sub,int lensub,int *next)
{
    next[0] = -1;
    next[1] = 0;
    int i = 2;//当前i的下标
    int j = 0;//前一项的k
    for(;i < lensub;i++)
    {
        if(j == -1 || sub[i-1] == sub[j])
        {
            next[i] = j + 1;
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
}
//str 代表主串
//sub 代表子串
//pos 代表从主串的pos位置开始找
int KMP (char * str,char *sub,int pos)
{
    //断言
    assert(str != NULL && sub != NULL);
    //计算主串和字串的长度
    int lenstr = strlen(str);
    int lensub = strlen(sub);
    if(lenstr == 0 || lensub == 0 ) return -1;
    if(pos < 0 || pos >= lenstr) return -1;

    int *next = (int*)malloc(sizeof(int)*lensub);
    assert(next != NULL);

    GetNext(sub,lensub,next);

    int i = pos;//遍历主串
    int j = 0;//遍历字串

    while(i < lenstr && j < lensub)
    {
        if(j == -1 || str[i] == sub[j])
        {
            i++;
            j++;
        }
        else
        {
            j=next[j];
        }
    }
    if(j >= lensub)
    {
        return i - j;
    }
    return -1;
}
int main()
{
    printf("%d\n",KMP("abcabcabcd","abcd",0));
    printf("%d\n",KMP("abcabcabcd","abcf",0));
    printf("%d\n",KMP("abcabcabcd","ab",0));
    system("pause");
    return 0;
}