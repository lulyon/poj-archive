#include<iostream>
using namespace std;
typedef struct node
{
    int data;
    int rank;
    int parent;
}ufstree;
ufstree t[50010];
bool b[50010];
void make(int n)
{
    for(int i=1;i<=n;++i)
    {
        t[i].data=i;
        t[i].rank=0;
        t[i].parent=i;
    }
};
int find(int x)
{
    if(x!=t[x].parent)
        return find(t[x].parent);
    return x;   
};
void union(int x,int y)
{
    x=find(x);
    y=find(y);
    if(t[x].rank>t[y].rank)
        t[y].parent=x;
    else
    {
        t[x].parent=y;
        if(t[x].parent==t[y].parent)
            ++t[y].rank;
    }
};

int main()
{
    int n,m;
    int tt=0;
    while(1)
    {
        cin>>n>>m;
        
        make(n);
        int a,b;
        for(int i=0;i<m;++i)
        {
            scanf("%d%d",&a,&b);
            union(a,b);
        }
        memset(b,0,(n+5)*sizeof(bool));
        for(int i=1;i<=n;++i)
        {
            b[find(i)]=1;
        }
        int cn=0;
        for(int i=1;i<=n;++i)
            if(b[i])++cn;
        printf("Case %d: %d\n",++tt,cn);
    }
    return 0;
}