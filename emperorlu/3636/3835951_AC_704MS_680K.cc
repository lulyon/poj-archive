#include<iostream>
#include<algorithm>
using namespace std;
typedef struct
{
    int x,y;
}node;
int stack[20010];

node a[20010];

bool cmp(const node &aa,const node &bb)
{
    if(aa.x!=bb.x)
        return aa.x < bb.x;
    else
        return aa.y > bb.y;
}
int main()
{
    int n,t;
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;++i)
        {
            scanf("%d%d",&a[i].x,&a[i].y);
        }
        
        sort(a,a+n,cmp);
        
        int i,j,top=1;
        stack[0]=0;
        
        for(i=1;i<n;++i)
        {
            for(j=0;j<top;++j)
            {
                if(a[i].x>a[stack[j]].x && a[i].y>a[stack[j]].y)
                {
                    stack[j]=i;
                    break;
                }
            }
            if(j==top)
                stack[top++]=i;
        }
        printf("%d\n",top);
    }
    return 0;
}

