#include<iostream>
using namespace std;
int a[15][15];
bool b[15];
void init()
{
    a[1][0]=1;
    a[2][0]=2;
    a[2][1]=1;
    int pos;
    for(int i=3;i<=13;++i)
    {
        memset(b,0,sizeof(b));
        pos=-1;
        for(int j=2;j<=i+1;++j)
        {
            for(int k=1;k<=j;)
            {
                pos=(pos+1)%i;
                if(!b[pos])++k;
            }
            b[pos]=1;
            a[i][pos]=j-1;
        }
    }
    
}

int main()
{
    init();
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        printf("%d",a[n][0]);
        for(int i=1;i<n;++i)
            printf(" %d",a[n][i]);
        printf("\n");
    }
    return 0;
}
