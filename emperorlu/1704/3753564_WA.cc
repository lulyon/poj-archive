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
        sort(a,a+n);
        for(i=1;i<=n;++i)
        {
            if(a[i]!=i)break;
        }
        if(i>n)
        {
            printf("Bob will win\n");
            continue;
        }
        int top=0;
        for(j=i;j<=n;)
        {   
            stack[top++]=a[j]-i;
            if(j<n&&a[j+1]==a[j]+1)
            {
                j+=2;
                i+=2;
            }
            else
            {
                j++;
                i++;
            }
        }
        
        
        for(i=1;i<top;++i)
            stack[0]^=stack[i];
        
        if(stack[0]%2)
            printf("Georgia will win\n");
        else
            printf("Bob will win\n");
    }
    return 0;
}
