#include<iostream>
using namespace std;
int a[100010];
int hash[100010];
int main()
{
    int i,n;
    while(1)
    {
        scanf("%d",&n);
        if(!n)break;
        for(i=1;i<=n;++i)
        {
            scanf("%d",a+i);
            hash[a[i]]=i;
        }
        for(i=1;i<=n;++i)
        {
            if(a[hash[a[i]]]!=a[i])
            {
                printf("not ambiguous\n");
                break;
            }
        }
        if(i>n)
            printf("ambiguous\n");
    }
    return 0; 
}
