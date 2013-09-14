#include<iostream>
using namespace std;
int main()
{
    int h,u,d,f;
    while(1)
    {
        scanf("%d%d%d%d",&h,&u,&d,&f);
        if(!h)break;
        u*=100;
        d*=100;
        h*=100;
        int a0=0,a1,n=0;
        while(1)
        {
            
            
            if(f*n<100)
            {
                a1=a0+u-u*f*n/100;
                
            }
            else
                a1=a0;
            
            a0=a1;
            n++;
            
            if(a0>h)
            {
                printf("success on day %d\n",n);
                break;
            }
            
            a0-=d;
            //cout<<a0<<endl;
            
            if(a0<0)
            {
                printf("failure on day %d\n",n);
                break;
            }
        }
    }
    return 0;
}