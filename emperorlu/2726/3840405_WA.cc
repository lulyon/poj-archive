#include<iostream>
#include<algorithm>
using namespace std;
typedef struct
{
    int d,c;
}node;

node a[10010];
int f[10010];


bool cmp(const node &aa,const node &bb)
{
    if(aa.d!=bb.d)
         return aa.d<bb.d;
    else
         return aa.c>bb.c;
}
int main()
{
    int i,j,n;
    while(1)
    {
        scanf("%d",&n);
        if(!n)break;
        
        for(i=0;i<n;++i)
            scanf("%d%d",&a[i].d,&a[i].c);
        
        sort(a,a+n,cmp);
        f[0]=1;
        int min=a[0].c,cn=1;
        
        for(i=1;i<n;++i)
        {
            if(min>a[i].c)
            {
                min = a[i].c;
                cn++;
            }
        }
        
        printf("%d\n",cn);
    }
    return 0;
}
