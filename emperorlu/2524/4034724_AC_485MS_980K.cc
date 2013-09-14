#include<iostream>
using namespace std;

const int maxn = 50010;

int cnt;

typedef struct
{
    int data,parent,rank;
}ufs_tree;

ufs_tree t[maxn];

void ufs_make(int n)
{
    for(int i=1;i<=n;++i)
    {
        t[i].parent = i;
        t[i].data = i;
        t[i].rank = i;
    }
}

int ufs_find(int x)
{
    int tmp = x;
    while(x!=t[x].parent)
        x = t[x].parent;    
    t[tmp].parent = x;
    return x;
}

void ufs_union(int x,int y)
{
    x = ufs_find(x);
    y = ufs_find(y);
    if(x==y)return;
    cnt--;
    if(t[x].rank<t[y].rank)
        t[x].parent = y;
    
    else
    {
        t[y].parent = x;
        if(t[x].rank == t[y].rank)
            ++t[x].rank;
    }
}

int main()
{
    int n,m,t1,t2,tt=0;
    while(1)
    {
        scanf("%d%d",&n,&m);
        if(!n&&!m)break;
        
        ufs_make(n);
        
        cnt=n;
        while(m--)
        {
            scanf("%d%d",&t1,&t2);
            ufs_union(t1,t2);
        }
        
        printf("Case %d: %d\n",++tt,cnt);
    }
    return 0;
}
