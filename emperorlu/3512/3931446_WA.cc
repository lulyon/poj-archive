#include<iostream>
#include<algorithm>
#include<math.h>
#define MAXN 2000
#define EPS 1e-12
using namespace std;
char str[50];

struct
{
    double x,y;
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
    int n=0;
    bool flag=0;
    int tt=0;
    while(1)
    {
        gets(str);

        if(str[0]=='-')
        {
            if(flag==0)
            {
                int top=0;
                for(int i=1;i<n;++i)
                {
                    for(int j=0;j<i;++j)
                    {
                        if(fabs(point[i].x-point[j].x)<EPS)
                        {
                            info[top].a=10000000000.000000;
                            info[top].b=point[i].x;
                            top++;
                        }
                        else
                        {
                            info[top].a=(point[i].y-point[j].y)/(point[i].x-point[j].x);
                            info[top].b=(point[i].x*point[j].y - point[j].x*point[i].y)/(point[i].x-point[j].x);
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
                printf("%d. %.0lf\n",++tt,ceil(sqrt(2.000000*max)));
                flag=1;
                n=0;
            }
            else
            {
                break;
            }
        }
        else
        {
            flag=0;
            sscanf(str,"%lf %lf",&point[n].x,&point[n].y);
            n++;
        }
        
    }
   
    return 0;
}
