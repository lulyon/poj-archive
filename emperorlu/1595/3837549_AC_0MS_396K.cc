#include<iostream>
using namespace std;
int a[1000];
int top;
bool prime(int n)
{
    for(int i=2;i<top;++i)
        if(n%a[i]==0)return 0;
    return 1;
}
void init()
{
    a[0]=1;
    a[1]=2;
    top=2;
    for(int i=3;i<1100;i+=2)
        if(prime(i))a[top++]=i;
}
int main()
{
    init();
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        
        for(i=0;i<top;++i)
        {
            if(a[i]>n)break;
        }
        if(i<top)
        {
            printf("%d %d:",n,m);
            if(i%2)
            {
                j=i/2-m+1;
                if(j>=0)
                for(;j<i/2+m;++j)
                {
                    printf(" %d",a[j]);
                }
                else
                {
                    for(j=0;j<i;++j)
                        printf(" %d",a[j]);
                }
            }
            else
            {
                j=i/2-m;
                if(j>=0)
                for(;j<i/2+m;++j)
                {
                    printf(" %d",a[j]);
                }
                else
                    for(j=0;j<i;++j)
                        printf(" %d",a[j]);
            }
            printf("\n\n");
        }
        
    }
    return 0;
}
