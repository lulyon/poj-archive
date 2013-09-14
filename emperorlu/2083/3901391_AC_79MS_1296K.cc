#include<iostream>
using namespace std;
bool a[8][800][800];
int b[8]={0,1,3,9,27,81,243,729};
void init()
{
    a[1][1][1]=1;
    int m;
    for(int i=2;i<=7;++i)
    {
        m=b[i-1];
        for(int j=1;j<=m;++j)
        {
            for(int k=1;k<=m;++k)
            {
                a[i][j][k]=a[i-1][j][k];
                a[i][j+m+m][k]=a[i-1][j][k];
                a[i][j+m][k+m]=a[i-1][j][k];
                a[i][j][k+m+m]=a[i-1][j][k];
                a[i][j+m+m][k+m+m]=a[i-1][j][k];
            }
        }
    }
    //cout<<a[2][3][2]<<endl;
}

int main()
{
    init();
    int n,r,m;
    while(1)
    {
        scanf("%d",&n);
        if(n==-1)break;
        
        m=b[n];
        for(int i=1;i<=m;++i)
        {
            for(int j=m;j>=0;--j)
                if(a[i][j])
                {
                    r=j;
                    break;
                }
            
            for(int j=1;j<=r;++j)
            {
                if(a[n][i][j])
                    printf("X");
                else
                    printf(" ");
            }
            printf("\n");
        }
        
        printf("-\n");
    }
    
    return 0;
}
