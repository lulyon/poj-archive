#include<iostream>
using namespace std;
int y[1010];
int main()
{
    int t,a,b,c,d,e,f,g,h,i;
    cin>>t;
    while(t--)
    {
        scanf("%d %d %d %d %d %d %d %d %d",&a,&b,&c,&d,&e,&f,&g,&h,&i);
        
        if(i==0)
        {
            printf("%d\n",a);
            continue;
        }
        if(i==1)
        {
            printf("%d\n",b);
            continue;
        }
        if(i==2)
        {
            printf("%d\n",c);
            continue;
        }
        y[0]=a;
        y[1]=b;
        y[2]=c;
        
        for(int j=3;j<=i;++j)
        {
            if(j%2)
            {
                y[j]=d*y[j-1]+e*y[j-2]-f*y[j-3];
                y[j]%=g;
                while(y[j]<0)y[j]+=g;
                while(y[j]>=g)y[j]-=g;
                
            }
            else
            {
                y[j]=f*y[j-1]-d*y[j-2]+e*y[j-3];
                y[j]%=h;
                while(y[j]<0)y[j]+=h;
                while(y[j]>=h)y[j]-=h;
                
            }
        }
        printf("%d\n",y[i]);
    }
    return 0;
}

