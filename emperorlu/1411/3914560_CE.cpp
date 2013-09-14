#include<iostream>
#include <math.h>
using namespace std;
int num;
int a[2000];
void init()
{
    a[0]=2;
    a[1]=3;
    num=2;
    int i,j;
    bool flag;
    for (i=5;i<9091;i+=2)
    {
        flag=0;
        for (j=1;j<num && a[j]*a[j]<=i;j++)
        {
            if (i%a[j]==0)
            {
                flag=1;
                break;
            }
        }
        if (flag==0)
            a[num++]=i;
    }
    
}

int main()
{    

    int m,c,b,p,q,n,i,j;
    double s;
    
    while (m>0)
    {
        scanf("%d%d%d",&m,&c,&b);
        if(!m)break;
        
        n=0;
        s=(double)c/b;
        for (i=num-1;i>=0;i--)
        {
            if (a[i]>m) continue;
            for (j=i;j<=num-1;j++)
            {
                if (a[j]>m||a[j]*a[i]>m||((double)a[i]/a[j])<s) break;
                if (a[j]*a>n)
                {
                    n=a[i]*a[j];
                    p=a[i];
                    q=a[j];
                }
            }
        }
        printf("%d %d\n",p,q);
    }
    return 0;
}
