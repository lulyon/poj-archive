#include<iostream>
#include<algorithm>
using namespace std;
typedef struct
{
    int d,c;
}node;
node a[10010];
int stack[10010];

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
        int top=1;
        stack[0]=a[0].c;
        
        for(i=1;i<n;++i)
        {
            for(j=0;j<top;++j)
            {
                if(a[i].c<stack[j])
                {
                    top=j;
                    stack[top++]=a[i].c;
                    break;
                }
            }
            if(j==top)
                stack[top++]=a[i].c;
        }
        printf("%d\n",top);
    }
    return 0;
}
