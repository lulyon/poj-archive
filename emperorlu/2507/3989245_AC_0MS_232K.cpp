#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
#define EXP 1e-6
void swap(double &aa,double &bb)
{
    double tmp;
    tmp = aa;
    aa = bb;
    bb = tmp;
}
int main()
{
    double l,r,mid;
    double A,B,x,y,c,f;
    while(scanf("%lf%lf%lf",&x,&y,&c)!=EOF)
    {
        if(x>y)swap(x,y);
        
 
        if(fabs(c*x+c*y-x*y)<EXP)
        {
            printf("0.000\n");
            continue;
        }
        
        l=0;
        r=x;
        mid=0.5000000*(l+r);
        
        while(1)
        {
            A = sqrt(x*x-mid*mid);
            B = sqrt(y*y-mid*mid);
            f = c*A+c*B-A*B;
            if(fabs(f)<EXP)
            {
                printf("%.3lf\n",mid);
                break;
            }
            else if(f<0)
            {
                l=mid;
                mid=0.500000*(l+r);
            }
            else
            {
                r=mid;
                mid=0.500000*(l+r);
            }
        }
    }
    return 0;
}

