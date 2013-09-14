#include<iostream>
using namespace std;

double x[1010],y[1010];

double d[1010][1010];

bool b[1010];


double dist(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{
    int n,tt=0;
    while(1)
    {
        scanf("%d",&n);
        if(!n)break;
        
        scanf("%lf%lf",x,y);
        for(int i=1;i<n;++i)
        {
            scanf("%lf%lf",x+i,y+i);
            for(int j=0;j<i;++j)
            {
                d[i][j]=d[j][i]=dist(x[i],y[i],x[j],y[j]);
            }
            b[i]=0;
        }
        b[0]=1;
        int index,pos=0;
        double min,max=-INT_MAX;
        while(1)
        {
            min=INT_MAX;
            for(int i=0;i<n;++i)
            {
               if(!b[i] && min>d[pos][i])
               {
                   index=i;
                   min=d[pos][i];
               }
            }
            b[index]=1;
            pos=index;
            if(max<min)max=min;
            if(pos==1)break;
        }
        printf("Scenario #%d\n",++tt);
        printf("Frog Distance = %.3lf\n\n",max);
    }
    return 0;
}
