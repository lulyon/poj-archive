#include<iostream>
using namespace std;

const int MaxN = 100100;
const int len=MaxN/2+1;
int p[len]={2},pp=1;

int d[len],e[len],dp;
void init()
{
    int i,j,cur;
    for(i=1;;++i)
    {
        if(!p[i])
        {
            p[pp++]=cur=i+i+1;
            for(j=2*i*(i+1);j<len;j+=cur)
                p[j]=1;
            if(j==2*i*(i+1))
                break;
        }
    }
    for(++i;i<len;++i)
    {
        if(!p[i])p[pp++]=i+i+1;
    }
}
void factorization(int num)
{
    int i,cnt,div;
    dp=0;
    for(i=0;i<pp&&p[i]<num;++i)
    {
        if(num%p[i]==0)
        {
            d[dp]=p[i];
            div=p[i]*p[i];
            cnt=1;
            while(num%div==0)
            {
                div*=p[i];
                ++cnt;
            }
            e[dp++]=cnt;
            div/=p[i];
            num/=div;
            if(num==1)
                break;
        }
    }
    
    if(num!=1)
    {
        d[dp]=num;
        e[dp++]=1;
    }
}

int f(int num)
{
    int sum=0;
    while(num)
    {
        sum+=num%10;
        num/=10;
    }
    return sum;
}

int main()
{
    int num,sum;
    init();
    
    while(1)
    {
        scanf("%d",&num);
        if(!num)break;
        
        num++;

        
        while(1)
        {
            factorization(num);
        
            sum=f(num);

            
            
            if(num==d[0])
            {
                num++;
                continue;
            }
            
            for(int i=0;i<dp;++i)
            {
                sum-=f(d[i])*e[i];
            }
            
            if(sum==0)break;
            
            
            num++;
        }
        leap:
            printf("%d\n",num);
        
    }
    return 0;
}
