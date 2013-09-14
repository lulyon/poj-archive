#include<iostream>
using namespace std;
struct
{
    double x,y;
    
}point[1010];

int main()
{
    double a;
    int i,n;
    scanf("%d%lf",&n,&a);
    
    point[0].x=0.000000;
    point[0].y=a;
    
    double re=0;
    for(i=1;i<=n-2;++i)
        re-=2*(n-i-1);
    
    
    point[1].x=1.000000/(n-1);
    
    
    point[1].y=((n-2)*a+re)/(n-1);
    
    
    for(i=2;i<n;++i)
    {
        point[i].x = 2*point[i-1].x-point[i-2].x;
        point[i].y = 2*point[i-1].y-point[i-2].y+2.000000;
        
    }
    
    
    double tmp,min=-1000.000000;
    
    for(int i=1;i<n;++i)
    {
        tmp = - point[i].y/point[i].x;
        if(min<=tmp)min=tmp;
    }
    if(min<=0)min=0.000000;
    
    printf("%.2lf\n",min);
    
    return 0;
}

