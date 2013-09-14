#include<iostream>
using namespace std;
int a[1010];
int stack[1010];
int main()
{
    int i,j,t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            scanf("%d",a+i);
        sort(a+1,a+n+1);
        int top=0;
        if(n%2)
        {
            stack[top++]=a[1]-1;
            for(i=2;i<=n;i+=2)
            {
                stack[top++]=a[i+1]-a[i]-1;
            }
            
        }
        else
        {
            for(i=1;i<=n;i+=2)
            {
                stack[top++]=a[i+1]-a[i]-1;
            }
        }
        
        for(i=1;i<top;++i)
            stack[0]^=stack[i];
        
        if(stack[0])
            printf("Georgia will win\n");
        else
            printf("Bob will win\n");
    }
    return 0;
}
