#include<iostream>
#include<algorithm>
using namespace std;
double a[100];
double stack[10000];
int main()
{
    int f,r;
    double tmp;
    while(1)
    {
        scanf("%d",&f);
        if(!f)break;
        
        scanf("%d",&r);
        for(int i=0;i<f;++i)
            scanf("%lf",a+i);
        
        int top=0;
        while(r--)
        {
            scanf("%lf",&tmp);
            for(int i=0;i<f;++i)
                stack[top++]=tmp/a[i];
        }
        sort(stack,stack+top);
        double max=-1;
        for(int i=1;i<top;++i)
        {
            tmp=stack[i]/stack[i-1];
            if(max<tmp)max=tmp;
        }
        printf("%.2lf\n",max);
    }
    return 0;
}
