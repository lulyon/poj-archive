#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    //freopen("cpp.cpp","w",stdout);
    char p1,p2;
    double h,t,d,a1,a2;
    while(1)
    {
        scanf("%c",&p1);
        if(p1=='E')break;
        scanf(" %lf %c %lf",&a1,&p2,&a2);
        getchar();
        if(p1=='D')
        {
            if(p2=='T')
            {
                d=a1;
                t=a2;
                h=t+0.5555*(6.11*exp(5417.7530*((1/273.16)-1/(d+273.16)))-10.0);
            }
            else if(p2=='H')
            {
                d=a1;
                h=a2;
                t=h-0.5555*(6.11*exp(5417.7530*((1/273.16)-1/(d+273.16)))-10.0);
            }
        }
        else if(p1=='T')
        {
            if(p2=='D')
            {
                t=a1;
                d=a2;
                h=t+0.5555*(6.11*exp(5417.7530*((1/273.16)-1/(d+273.16)))-10.0);
            }
            else if(p2=='H')
            {
                t=a1;
                h=a2;
                d=1/273.16-log(((h-t)/0.5555+10.0)/6.11)/5417.7530;
                d=1/d-273.16;
            }
        }
        else if(p1=='H')
        {
            if(p2=='T')
            {
                h=a1;
                t=a2;
                d=1/273.16-log(((h-t)/0.5555+10.0)/6.11)/5417.7530;
                d=1/d-273.16;
            }
            else if(p2=='D')
            {
                h=a1;
                d=a2;
                t=h-0.5555*(6.11*exp(5417.7530*((1/273.16)-1/(d+273.16)))-10.0);
            }
        }
        printf("T %.1lf D %.1lf H %.1lf\n",t,d,h);
    }
    return 0;
}
