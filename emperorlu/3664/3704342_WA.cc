#include<iostream>
using namespace std;
typedef struct node
{
    double a,b;
}pnode;
pnode p[50010]; 
int cmp(const void *aa,const void *bb)
{
    return ((pnode *)aa)->a < ((pnode *)bb)->a?1:-1;
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;++i)
        scanf("%lf%lf",&p[i].a,&p[i].b);
    qsort(p,n,sizeof(p[0]),cmp);
    
    
    
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