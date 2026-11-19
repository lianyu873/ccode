/*二分答案
题目：P2440*/
/*二分查找vs二分答案
二分查找：在现成的数据里找，前提：数据有序
二分答案：在可能的答案里找，前提可行性单调（如果长度z可行，比z小的也可行）
*/

#include <stdio.h>
int max(int shuzu[],int n)
{
    int max_=shuzu[0];//函数和变量不要用同一个名字
    for (int i=1;i<n;i++)
    {
        if(shuzu[i]>max_)max_=shuzu[i];
    }
    return max_;
}
int sum(int shuzu[],int n,int max)
{
    int sum_=0;
    for (int i=0;i<n;i++)
    {
        int y=shuzu[i]/max;
        sum_+=y;
    }
    return sum_;
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int shuzu[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&shuzu[i]);
    }
    int max_=max(shuzu,n),min_=0;
    while(1)
    {
        int mid=(max_+min_+1)/2;
        if(sum(shuzu,n,mid)>=k)min_=mid;
        else max_=mid-1;
        if(max_==min_)
        {
            printf("%d",min_);
            break;
        }
    }
}