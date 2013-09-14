#include<iostream>
using namespace std;
int a[1010];
int n,t;
int findmax(void)
{
    int index=0;
    for(int i=1;i<n;++i)
        if(a[i]>a[index])index=i;
    return index;
}
int main()
{
    scanf("%d%d",&n,&t);
    for(int i=0;i<n;++i)
        scanf("%d",a+i);
    if(n==1)
    {
        while(t--)
        {
            printf("%d",*a);
            if(t)printf(" ");
            else printf("\n");
        }
        return 0;
    }
    int remain,index,prev=0;
    while(t--)
    {
        index=findmax();
        printf("%d",index+1);
        if(t)printf(" ");
            else printf("\n");
        if(a[index]%(n-1)==0)
        {
            a[index]=prev-a[index]/(n-1);
        }
        else if(a[index]<0)
        {
            int temp=a[index]/(n-1)-1;
            remain=a[index]-temp*(n-1);
            a[index]=prev-temp;
            if(index==0)a[1]+=remain;
            else a[0]+=remain;
        }
        else
        {
            int temp=a[index]/(n-1);
            remain=a[index]-temp*(n-1);
            a[index]=prev-temp;
            if(index==0)a[1]+=remain;
            else a[0]+=remain;
        }
        prev=a[index];
    }
    return 0;
}