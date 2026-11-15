/*二分查找
题目：P2249*/
#include <stdio.h>
long long chazhao(long long num[],long long n,long long a)    //接收数组用long long num[]
{
    long long di=0,gao=n-1,ans=-1;
    while(di<gao)    //不判断num[]是否等于a，而是判断di和gao之间还有没有数，既避免死循环，又避免后面一项一项往前推最早的a
    {
        if(num[(di+gao)/2]>=a)
        {
            gao=(di+gao)/2;
        }
        else
        {
            di=(di+gao)/2+1;
        }
    }
    if(num[gao]==a)
    {
        ans=gao+1;
    }
    return ans;
}
int main()
{
    long long n,m;
    scanf("%lld%lld",&n,&m);
    long long num[n],mum[m];
    for(int i=0;i<=n-1;i++)
    {
        scanf("%lld",&num[i]);
    }
    for(int i=0;i<=m-1;i++)
    {
        scanf("%lld",&mum[i]);
    }
    for(int i=0;i<=m-1;i++)
    {
        printf("%lld ",chazhao(num,n,mum[i]));    //num[]只能出现在函数定义的参数里面。调用函数时传数组直接写数组名
    }
}