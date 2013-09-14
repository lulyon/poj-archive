#include<iostream>
using namespace std;
typedef struct
{
    int parent,num,c[100];
}node;
node tree[10000];

bool b[10000];
bool ap[10000];

int x[1000],y[1000];

void make(int max)
{
    for(int i=1;i<=max;++i)
    {
        tree[i].parent=i;
        tree[i].num=0;
    }
}

bool dfs(int i)
{
    if(b[i])return 0;
    
    b[i]=1;
    int m=tree[i].num;
    bool flag;

    
    for(int j=0;j<m;++j)
    {
        flag=dfs(tree[i].c[j]);
        if(flag==0)return 0;
    }
    return 1;
}

int main()
{
    int n=0;
    int max=0,tt=0;
    while(1)
    {
        scanf("%d%d",x+n,y+n);
        if(x[n]==-1)break;
        
        
        if(x[n]==0&&y[n]==0)
        {
            if(n==0)
            {
                printf("Case %d is a tree.\n",++tt);
                continue;
            }
            make(max);
            memset(ap,0,(max+5)*sizeof(bool));
            
            for(int i=0;i<n;++i)
            {
                tree[y[i]].parent=x[i];
                tree[x[i]].c[tree[x[i]].num++]=y[i];
                ap[x[i]]=ap[y[i]]=1;
            }
            
            int cn=0,root;
            bool flag=0;
            for(int i=1;i<=max;++i)
            {
                if(ap[i]&&tree[i].parent==i)
                {
                    root=i;
                    ++cn;
                    if(cn==2)
                    {
                        printf("Case %d is not a tree.\n",++tt);
                        flag=1;
                        break;
                    }
                }
            }
            
            //cout<<cn<<endl;
            
            if(flag==0)
            {
                if(cn==0)
                {
                    printf("Case %d is not a tree.\n",++tt);
                }
                else
                {
                    if(dfs(root))
                        printf("Case %d is a tree.\n",++tt);
                    else
                        printf("Case %d is not a tree.\n",++tt);
                }
            }
            
            max=0;
            n=0;
        }
        else
        {
            if(max<x[n])max=x[n];
            if(max<y[n])max=y[n];
            b[x[n]]=b[y[n]]=0;
            
            ++n;
        }
    }
    return 0;
}
