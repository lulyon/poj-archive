#include<iostream>
using namespace std;
typedef struct node
{
    double a,b;
}pnode;
pnode p[50010]; 
bool cmp(pnode aa,pnode bb)
{
    return aa.a>bb.a;
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;++i)
        scanf("%lf%lf",&p[i].a,&p[i].b);
    sort(p,p+n,cmp);
    
    
    
    double max=-1;
    int index;
    for(int i=n-1;i>=n-k;--i)
    {
        if(p[i].b>max)
        {
            max=p[i].b;
            index=i;
        }
        
    }
    printf("%d\n",index+1);
    return 0;
}