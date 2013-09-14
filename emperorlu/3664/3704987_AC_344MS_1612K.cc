#include<iostream>
using namespace std;
typedef struct NODE
{
    double a,b;
    int index;
}pnode;
pnode p[50010];
int cmp(const pnode &aa,const pnode &bb)
{
    return aa.a<bb.a;
}
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;++i)
    {
        scanf("%lf%lf",&p[i].a,&p[i].b);
        p[i].index=i;
    }
    sort(p,p+n,cmp);
    
  
    
    int pindex=n-1;
    for(int i=n-2;i>=n-k;--i)
    {
        if(p[i].b>p[pindex].b)pindex=i;
    }
    cout<<p[pindex].index+1<<endl;
    return 0;
}