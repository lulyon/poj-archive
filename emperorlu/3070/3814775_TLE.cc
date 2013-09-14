#include<iostream>
using namespace std;
#define NUM 10000
__int64 ans[2][2];
__int64 tmp[2][2];
__int64 a[2][2];
__int64 b;
void pow()
{
   
   for (; b; b >>= 1)
   {
       if ((b & 1))
       {
           tmp[0][0]=(ans[0][0]*a[0][0]+ans[0][1]*a[0][1])%NUM;
           tmp[0][1]=(ans[0][0]*a[0][1]+ans[0][1]*a[1][1])%NUM;
           //tmp[1][0]=(ans[1][0]*a[0][0]+ans[1][1]*ans[1][0])%NUM;
           tmp[1][1]=(ans[1][0]*a[0][1]+ans[1][1]*a[1][1])%NUM;
           
           ans[0][0]=tmp[0][0];
           ans[0][1]=tmp[0][1];
           //ans[1][0]=tmp[1][0];
           ans[1][1]=tmp[1][1];
       }
       tmp[0][0]=(a[0][0]*a[0][0]+a[0][1]*a[0][1])%NUM;
       tmp[0][1]=(a[0][0]*a[0][1]+a[0][1]*a[1][1])%NUM;
       //tmp[1][0]=(a[1][0]*a[0][0]+a[1][1]*a[1][0])%NUM;
       tmp[1][1]=(a[1][0]*a[0][1]+a[1][1]*a[1][1])%NUM;
       
       a[0][0]=tmp[0][0];
       a[0][1]=tmp[0][1];
       //a[1][0]=tmp[1][0];
       a[1][1]=tmp[1][1];
   }
   
}


int main()
{
    ans[0][0] = ans[1][1] = 1;
    ans[0][1] = 0;
    a[0][0] = a[0][1] = 1;
    a[1][1]=0;
    while(1)
    {
        scanf("%I64d",&b);
        if(b==0)printf("0\n");
        else
        {
            pow();
            printf("%I64d\n",ans[0][1]);
        }
    }
    return 0;
}
