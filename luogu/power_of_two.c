/*幂次方
题目：P1010*/
#include <stdio.h>
void zhuanhuan(int n)
{
    int i=14,a=2048*2*2*2;
    for (i;i>=0;i--)
    {
        if(a>n)
        {
            a=a/2;
        }
        else  //a<=n,i是次数
        {
            break;
        }
    }
        if (i==1)printf("2");
        else if (i==0||i==2)printf("2(%d)",i);
        else
        {
            printf("2(");
            zhuanhuan(i);
            printf(")");
        }
        n=n-a;
        if(n>0)
        {
            printf("+");
            zhuanhuan(n);
        }
}
int main()
{
    int n;
    scanf("%d",&n);
    zhuanhuan(n);
}