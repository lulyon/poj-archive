#include<stdio.h>
int n;
bool b[350][350];
int x[100000],y[100000],s[100000];
int x1,y1,x2,y2;
int head,tail;
void bfs(int i,int j)
{
    b[i][j]=1;
    if(b[x2][y2])
    {
        printf("0\n");
        return;
    }
    x[head]=i;
    y[head]=j;
    s[head]=0;
    while(head<=tail)
    {
        if(!b[x[head]+2][y[head]+1])
        {
            ++tail;
            x[tail]=x[head]+2;
            y[tail]=y[head]+1;
            s[tail]=s[head]+1;
            b[x[tail]][y[tail]]=1;
            if(b[x2][y2])
            {
                printf("%d\n",s[tail]);
                return;
            }
        }
        if(!b[x[head]-2][y[head]+1])
        {
            ++tail;
            x[tail]=x[head]-2;
            y[tail]=y[head]+1;
            s[tail]=s[head]+1;
            b[x[tail]][y[tail]]=1;
            if(b[x2][y2])
            {
                printf("%d\n",s[tail]);
                return;
            }
        }
        if(!b[x[head]-2][y[head]-1])
        {
            ++tail;
            x[tail]=x[head]-2;
            y[tail]=y[head]-1;
            s[tail]=s[head]+1;
            b[x[tail]][y[tail]]=1;
            if(b[x2][y2])
            {
                printf("%d\n",s[tail]);
                return;
            }
        }
        if(!b[x[head]+2][y[head]-1])
        {
            ++tail;
            x[tail]=x[head]+2;
            y[tail]=y[head]-1;
            s[tail]=s[head]+1;
            b[x[tail]][y[tail]]=1;
            if(b[x2][y2])
            {
                printf("%d\n",s[tail]);
                return;
            }
        }
        if(!b[x[head]+1][y[head]+2])
        {
            ++tail;
            x[tail]=x[head]+1;
            y[tail]=y[head]+2;
            s[tail]=s[head]+1;
            b[x[tail]][y[tail]]=1;
            if(b[x2][y2])
            {
                printf("%d\n",s[tail]);
                return;
            }
        }
        if(!b[x[head]-1][y[head]+2])
        {
            ++tail;
            x[tail]=x[head]-1;
            y[tail]=y[head]+2;
            s[tail]=s[head]+1;
            b[x[tail]][y[tail]]=1;
            if(b[x2][y2])
            {
                printf("%d\n",s[tail]);
                return;
            }
        }
        if(!b[x[head]-1][y[head]-2])
        {
            ++tail;
            x[tail]=x[head]-1;
            y[tail]=y[head]-2;
            s[tail]=s[head]+1;
            b[x[tail]][y[tail]]=1;
            if(b[x2][y2])
            {
                printf("%d\n",s[tail]);
                return;
            }
        }
        if(!b[x[head]+1][y[head]-2])
        {
            ++tail;
            x[tail]=x[head]+1;
            y[tail]=y[head]-2;
            s[tail]=s[head]+1;
            b[x[tail]][y[tail]]=1;
            if(b[x2][y2])
            {
                printf("%d\n",s[tail]);
                return;
            }
        }
        ++head;
    }
    
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        
        
        for(int i=2;i<=n+3;i++)
        {
            for(int j=2;j<=n+1;++j)
                b[i][j]=0;
            b[i][0]=b[i][1]=b[i][n+2]=b[i][n+3]=1;
        }
        
        for(int j=0;j<=n+3;++j)
        {
            b[0][j]=b[1][j]=b[n+2][j]=b[n+3][j]=1;
        }
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        
        x1+=2;
        y1+=2;
        x2+=2;
        y2+=2;
        
        head=tail=0;
        bfs(x1,y1);
        
    }
    return 0;
}
