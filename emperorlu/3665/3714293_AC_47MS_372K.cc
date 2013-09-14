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
            printf("%d\n",*a);
            
        }
        return 0;
    }
    int remain,index,prev=0;
    while(t--)
    {
        index=findmax();
        printf("%d\n",index+1);
        
        remain=a[index]%(n-1);
        
        for(int i=0;i<n;++i)
        {
            if(i!=index)
            {
                if(remain>0)
                {
                    a[i]+=a[index]/(n-1)+1;
                    --remain;
                }
                else
                {
                    a[i]+=a[index]/(n-1);
                }
            }
        }
        a[index]=0;
    }
    return 0;
}