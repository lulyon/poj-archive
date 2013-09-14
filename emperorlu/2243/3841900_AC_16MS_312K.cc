#include<stdio.h>
#define n 8
bool b[15][15];
int x[15*15],y[15*15],s[15*15];
int x1,y1,x2,y2;
char s1[5],s2[5];
int head,tail;
void bfs(int i,int j)
{
    b[i][j]=1;
    if(b[x2][y2])
    {
        printf("To get from %s to %s takes %d knight moves.\n",s1,s2,s[tail]);
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
                printf("To get from %s to %s takes %d knight moves.\n",s1,s2,s[tail]);
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
                printf("To get from %s to %s takes %d knight moves.\n",s1,s2,s[tail]);
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
                printf("To get from %s to %s takes %d knight moves.\n",s1,s2,s[tail]);
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
                printf("To get from %s to %s takes %d knight moves.\n",s1,s2,s[tail]);
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
                printf("To get from %s to %s takes %d knight moves.\n",s1,s2,s[tail]);
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
                printf("To get from %s to %s takes %d knight moves.\n",s1,s2,s[tail]);
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
                printf("To get from %s to %s takes %d knight moves.\n",s1,s2,s[tail]);
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
                printf("To get from %s to %s takes %d knight moves.\n",s1,s2,s[tail]);
                return;
            }
        }
        ++head;
    }
    
}
int main()
{

    while(scanf("%s%s",s1,s2)!=EOF)
    {
        //printf("%s %s\n",s1,s2);
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
        
        
        x1=s1[0]-'a';
        y1=s1[1]-'1';
        x2=s2[0]-'a';
        y2=s2[1]-'1';
        x1+=2;
        y1+=2;
        x2+=2;
        y2+=2;
        
        head=tail=0;
        bfs(x1,y1);
        
    }
    return 0;
}
