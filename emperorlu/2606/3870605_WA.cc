#include<iostream>
#include<algorithm>
#include<math.h>
#define MAXN 250
#define EPS 1e-6
using namespace std;
struct
{
    int x,y;
}point[MAXN];
typedef struct
{
    double a,b;
}INFO;
INFO info[MAXN*MAXN];
bool cmp(const INFO &aa,const INFO &bb)
{
    if(fabs(aa.a - bb.a)>EPS)
        return aa.a < bb.a;
    else return aa.b < bb.b;
}


int main()
{
    int n;
    cin>>n;
    scanf("%d %d",&point[0].x,&point[0].y);
    int top=0;
    for(int i=1;i<n;++i)
    {
        scanf("%d %d",&point[i].x,&point[i].y);
        for(int j=0;j<i;++j)
        {
            if(point[i].x==point[j].x)
            {
                info[top].a=(double)INT_MAX;
                info[top].b=(double)point[i].x;
                top++;
            }
            else
            {
                info[top].a=(point[i].y-point[j].y)/(double)(point[i].x-point[j].x);
                info[top].b=(point[i].x*point[j].y - point[j].x*point[i].y)/(double)(point[i].x-point[j].x);
                top++;
            }
        }
    }
    
    sort(info,info+top,cmp);
    int cn=1,max=0;
    for(int i=1;i<top;++i)
    {
        if(fabs(info[i].a-info[i-1].a)<EPS&&fabs(info[i].b-info[i-1].b)<EPS)
        {
            ++cn;
        }
        else
        {
            cn=1;
        }
        if(max<cn)max=cn;
    }
    printf("%d\n",max/2);
    return 0;
}
