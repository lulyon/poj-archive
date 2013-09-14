#include<iostream>
#include<math.h>
using namespace std;
#define MAXN 110
double x[MAXN],y[MAXN];
double a[MAXN][MAXN];
double mins[MAXN];
bool b[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%lf%lf",x,y);
    if(n==1)
    {
        printf("0\n");
        return 0;
    }
    b[0]=0;
    for(int i=1;i<n;++i)
    {
        scanf("%lf%lf",x+i,y+i);
        for(int j=0;j<i;++j)
        {
            a[i][j]=a[j][i]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
        }
        b[i]=0;
    }
    double min=INT_MAX;
    int ii,jj;
    for(int i=0;i<n;++i)
        for(int j=i+1;j<n;++j)
        {
            if(min>a[i][j])
            {
                min = a[i][j];
                ii = i;
                jj = j;
            }
        }
    double sum=min;
    b[ii]=b[jj]=1;
    
    for(int i=0;i<n;++i)
    {
        if(!b[i])
        {
            if(a[i][ii]>a[i][jj])
                mins[i]=a[i][jj];
            else
                mins[i]=a[i][ii];
        }
    }
    int m=n-2,index;
    while(m--)
    {
        min=INT_MAX;
        for(int i=0;i<n;++i)
        {
            if(!b[i] && min>mins[i])
            {
                min=mins[i];
                index = i;
            }
        }
        sum+=min;
        b[index]=1;
        
        for(int i=0;i<n;++i)
        {
            if(!b[i]&&mins[i]>a[i][index])
                    mins[i]=a[i][index];
        }   
    }
    
    printf("%.2lf\n",sum);
    return 0;
}
