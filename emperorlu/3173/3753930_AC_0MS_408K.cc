#include<iostream>
using namespace std;
int a[25][25];
int main()
{
    int n,s;
    cin>>n>>s;
    for(int j=1;j<=n;++j)
    {
        for(int i=1;i<=j;++i)
        {
            a[i][j]=s;
            s=s+1;
            if(s==10)s=1;
        }
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
        {
            if(a[i][j])
                printf("%d",a[i][j]);
            else
                printf(" ");
            if(j<n)
                printf(" ");
            else
                printf("\n");
        }
    
    return 0;
}
