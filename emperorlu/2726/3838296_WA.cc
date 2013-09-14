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
        return aa.d<bb.d;
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
        for(i=1;i<n;++i)
        {
            f[i]=0;
            for(j=0;j<i;++j)
            {
                if(a[j].c<a[i].c&&f[i]<f[j])
                    f[i]=f[j];
            }
            ++f[i];
        }
        printf("%d\n",f[n-1]);
    }
    return 0;
}
