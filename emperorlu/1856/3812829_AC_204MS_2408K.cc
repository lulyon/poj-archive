#include<stdio.h>

int n,m,x1,y1,x2,y2,cn;
char a[1010][1010];
bool b[1010][1010];


void visit(int i,int j)
{
    b[i][j]=1;
    if(!b[i-1][j]&&a[i-1][j]=='#')
    {
        cn++;
        if(y1>i-1)y1=i-1;
        visit(i-1,j);
    }
    if(!b[i+1][j]&&a[i+1][j]=='#')
    {
        cn++;
        if(y2<i+1)y2=i+1;
        visit(i+1,j);
    }
    if(!b[i][j-1]&&a[i][j-1]=='#')
    {
        cn++;
        if(x1>j-1)x1=j-1;
        visit(i,j-1);
    }
    if(!b[i][j+1]&&a[i][j+1]=='#')
    {
        cn++;
        if(x2<j+1)x2=j+1;
        visit(i,j+1);
    }
    if(!b[i-1][j-1]&&a[i-1][j-1]=='#')
    {
        cn++;
        if(y1>i-1)y1=i-1;
        if(x1>j-1)x1=j-1;
        visit(i-1,j-1);
    }
    if(!b[i+1][j-1]&&a[i+1][j-1]=='#')
    {
        cn++;
        if(y2<i+1)y2=i+1;
        if(x1>j-1)x1=j-1;
        visit(i+1,j-1);
    }
    if(!b[i+1][j+1]&&a[i+1][j+1]=='#')
    {
        cn++;
        if(y2<i+1)y2=i+1;
        if(x2<j+1)x2=j+1;
        visit(i+1,j+1);
    }
    if(!b[i-1][j+1]&&a[i-1][j+1]=='#')
    {
        cn++;
        if(y1>i-1)y1=i-1;
        if(x2<j+1)x2=j+1;
        visit(i-1,j+1);
    }
}
int main()
{
    while(1)
    {
        scanf("%d%d",&n,&m);
        if(!n&&!m)break;
        
        
        for(int i=1;i<=n;++i)
        {
            scanf("%s",&a[i][1]);
            for(int j=1;j<=m;++j)
            {
                b[i][j]=0;
            }
            b[i][0]=b[i][m+1]=1;
        }
        
        for(int j=0;j<=m+1;++j)
        {
            b[0][j]=b[n+1][j]=1;
        }
        bool flag=0;
        int num=0;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                if(!b[i][j]&&a[i][j]=='#')
                {
                    num++;
                    x1=x2=j;
                    y1=y2=i;
                    cn=1;
                    visit(i,j);
                    int area=(x2-x1+1)*(y2-y1+1);
                    if(area!=cn)
                    {
                        printf("Bad placement.\n");
                        flag=1;
                        goto leap;
                    }
                }
            }
            
        }
        leap:
            if(flag==0)
        		printf("There are %d ships.\n",num);
        
    }
    return 0;
}
