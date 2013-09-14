#include<iostream>
#include<algorithm>
using namespace std;
double a[10],b[10],s[10];
int pm[10],ans[10];

int main()
{
    int n;
    double d;
    scanf("%d%lf",&n,&d);
    
    for(int i=0;i<n;++i)
    {
        scanf("%lf%lf%lf",a+i,b+i,s+i);
        pm[i]=ans[i]=i;
    }
    
    double max=0;
    
    do
    {
        double p=1,exp=d;
        int flag=0;
        for(int i=0;i<n;++i)
        {
            if(exp>a[pm[i]]&&exp<b[pm[i]])
            {
                p*=(exp-a[pm[i]])/(b[pm[i]]-a[pm[i]]);
                exp+=s[pm[i]];
            }
            else if(exp<=a[pm[i]])
            {
                flag=1;
                break;
            }
            else
            {
                exp+=s[pm[i]];
            }
        }
        if(flag==0)
        {
            if(max<p)
            {
                max=p;
                for(int i=0;i<n;++i)
                {
                    ans[i]=pm[i];
                }
            }
        }
        
    }while(next_permutation(pm,pm+n));
    
    printf("%.3lf\n",max);
    for(int i=0;i<n;++i)
    {
        printf("%d",ans[i]+1);
        if(i!=n-1)
            printf(" ");
        else
            printf("\n");
    }
    
    return 0;
}
