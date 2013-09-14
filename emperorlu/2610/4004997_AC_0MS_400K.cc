#include<iostream>
using namespace std;

double dist(double x1,double y1,double x2,double y2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int main()
{
    double x1,y1,x2,y2,x,y,ansx,ansy;
    scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
    bool flag=0;
    while(scanf("%lf%lf",&x,&y)!=EOF)
    {
        if(!flag && dist(x2,y2,x,y)>=4*dist(x1,y1,x,y))
        {
            ansx = x;
            ansy = y;
            flag=1;
        }
    }
    if(flag)
        printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n",ansx,ansy);
    else
        printf("The gopher cannot escape.\n");
    
    return 0;
}
