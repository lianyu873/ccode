/*快速幂
题目：P1226*/
#include <stdio.h>
int main()
{
    long long a,b,p,m=1,current,cishu;
    scanf("%lld%lld%lld",&a,&b,&p);
    current=a%p;cishu=b;
    if(cishu==0){
        current=1;
    }
    else
    {
        while(cishu>1)
        {
            if(cishu%2==0)
            {
                cishu/=2;
                current*=current;
                current=current%p;
            }
            else
            {
                m=(m*current)%p;
                cishu-=1;
            }
        }
    }
    m=(m*current)%p;
    printf("%lld^%lld mod %lld=%lld\n",a,b,p,m);
}