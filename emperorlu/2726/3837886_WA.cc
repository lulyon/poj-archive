#include<iostream>
#include<algorithm>
using namespace std;
typedef struct
{
    int d,c;
}node;
node a[10010];

bool cmp(const node &aa,const node &bb)
{
        return aa.d<bb.d;
}
int main()
{
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(!n)break;
        
        for(int i=0;i<n;++i)
            scanf("%d%d",&a[i].d,&a[i].c);
        
        sort(a,a+n,cmp);
        int cn=1;
        int maxcost=a[0].c;
        for(int i=1;i<n;++i)
        {
            if(a[i].c>maxcost)
            {
                ++cn;
                maxcost=a[i].c; 
            }
        }
        printf("%d\n",cn);
    }
    return 0;
}
