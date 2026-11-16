/*记忆化
题目：P1464*/
#include <stdio.h>

long long shuzu[21][21][21];    //全局数组本来就全是0

long long w(long long a,long long b,long long c)
{
    if(a<=0||b<=0||c<=0)return 1;
    else if(a>20||b>20||c>20)return w(20,20,20);
    else if(shuzu[a][b][c]!=0)return shuzu[a][b][c];
    else if(a<b&&b<c)
    {
        shuzu[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);    //赋值运算的左操作数必须是左值：=左边必须是能装东西的盒子（变量，数组元素），而不能是w（a,b,c）（一次函数调用，调用的结果是一个值，不是盒子）
        return shuzu[a][b][c];
    }
    else
    {
        shuzu[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
        return shuzu[a][b][c];
    }
}
int main()
{
    long long a=0,b=0,c=0;
    scanf("%lld%lld%lld",&a,&b,&c);
    while(a!=-1||b!=-1||c!=-1)
    {
        printf("w(%lld, %lld, %lld) = %lld\n",a,b,c,w(a,b,c));
        scanf("%lld%lld%lld",&a,&b,&c);
    }
}