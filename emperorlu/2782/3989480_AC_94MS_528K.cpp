#include<stdio.h>
#include<cstdlib>
#include<algorithm>
using namespace std;
int p[100005]={0};
int n,l;
int can(int m)
{
    int i,j,q;
    j=2*m-1;
    for(i=0;i<j;i++)
    {
        if(j>=n)q=0;
        else q=p[j];
        if(p[i]+q<=l)j--; 
        else
            break;                
    }
    if(i>=j)return 1;
    else return 0;
}
int cmp(const int &a,const int &b)
{
    return a>b;
}
int main()
{
    int i,sum,low,mid,high;
    scanf("%d%d",&n,&l);
    sum=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
        sum+=p[i];
    }
    sort(p,p+n,cmp);
    high=n;
    low=sum/l;
    while(low<high)
    {
        mid=((low+high)/2);
        if(can(mid))high=mid;
        else low=mid+1;
    }
    printf("%d\n",low);
    return 0;
}
