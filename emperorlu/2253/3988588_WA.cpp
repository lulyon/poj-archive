#include<iostream>
#include<math.h>
using namespace std;

int x[1010],y[1010];

int d[1010][1010];

bool b[1010];


int dist(int x1,int y1,int x2,int y2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int main()
{
    int n,tt=0;
    while(1)
    {
        scanf("%d",&n);
        if(!n)break;
        
        scanf("%d%d",x,y);
        for(int i=1;i<n;++i)
        {
            scanf("%d%d",x+i,y+i);
            for(int j=0;j<i;++j)
            {
                d[i][j]=d[j][i]=dist(x[i],y[i],x[j],y[j]);
            }
            b[i]=0;
        }
        b[0]=1;
        int index,pos=0;
        int min,max=-INT_MAX;
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
        printf("Frog Distance = %.3lf\n\n",sqrt((double)max));
    }
    return 0;
}
