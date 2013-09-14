#include<iostream>
using namespace std;
int a[500];
int stack[500*500];
int main()
{
    int i,j,n,t;
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        scanf("%d",a);   
        
        if(n==1)
        {
            printf("1\n");
            continue;
        }
        
        int top=0;
        for(i=1;i<n;++i)
        {
            scanf("%d",a+i);
            for(j=0;j<i;++j)
            {
                stack[top++]=a[i]-a[j];
            }
        }
        for(i=n;;++i)
        {
            for(j=0;j<top;++j)
            {
                if(stack[j]%i==0)break;
            }
            if(j==top)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
