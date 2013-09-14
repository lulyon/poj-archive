#include<stdio.h>
#include<memory.h>
int a[15][15],b[15][15];
int main()
{
    int n,cn=0;
    char p;
    while(scanf("%d\n",&n)!=EOF)
    {
        cn++;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                scanf("%c",&p);
                if(p=='.')a[i][j]=0;
                else a[i][j]=-1;
            }
            getchar();
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[i][j]!=-1)
                {
                    for(int k=i-1;k<=i+1;k++)
                    {
                        for(int l=j-1;l<=j+1;l++)
                        {
                            if(a[k][l]==-1)a[i][j]++;
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                scanf("%c",&p);
                if(p=='x')b[i][j]=1;
                else b[i][j]=0;
            }
            getchar();
        }
        int flag=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[i][j]==-1&&b[i][j]==1)
                {
                    flag=1;
                    goto leap;
                }
            }
        }
        leap:
            if(cn!=1)putchar('\n');
            if(flag)
            {
                for(int i=1;i<=n;i++)
                {
                    for(int j=1;j<=n;j++)
                    {
                        if(a[i][j]==-1)printf("*");
                        else if(b[i][j]==0)printf(".");
                        else printf("%d",a[i][j]);
                    }
                    putchar('\n');
                }
            }
            else
            {
                for(int i=1;i<=n;i++)
                {
                    for(int j=1;j<=n;j++)
                    {
                        if(b[i][j]==0)printf(".");
                        else if(b[i][j]==1&&a[i][j]!=-1)
                            printf("%d",a[i][j]);
                    }
                    putchar('\n');
                }
            }
    }
    return 0;
} 
