#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    long long mm,i,n;
    double m,p;
    while(1)
    {
        scanf("%lld",&n);
        if(!n)break;
        
       i=(long long)(log(fabs((double)n))/log(2.0000000))+1;
       //cout<<i<<endl;
       
       
       for(;i>1;--i)
       {
           m=pow((double)n,1.0000000/(double)i);
           mm=(long long)m;
           if(m-(double)mm<1e-12||(double)mm+1-m<1e-12)
           {
               printf("%lld\n",i);
               break;
           }
       }
       if(i==1)
           printf("1\n");
    }
    return 0;
}

