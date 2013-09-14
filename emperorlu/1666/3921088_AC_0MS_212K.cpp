#include<iostream>
using namespace std;
int a[10000];

int main()
{
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(!n)break;
        
        for(int i=0;i<n;++i)
        {
            scanf("%d",a+i);
        }
        
        if(n==1)
        {
            printf("0 %d\n",a[0]);
            continue;
        }
        
        bool tag;
        int pre,pos,cn=0;
        while(1)
        {
            tag = 0;
            for(int i=0;i<n-1;++i)
            {
                if(a[i]!=a[i+1])tag=1;
            }
            if(a[n-1]!=a[0])tag=1;
            
            if(tag==0)
            {
                printf("%d %d\n",cn,a[0]);
                break;
            }
            pre = a[n-1]/2;
            for(int i=0;i<n;++i)
            {
                pos = a[i]/2;
                a[i] += pre-pos;
                if(a[i]%2)++a[i];
                pre = pos;                
            }
            cn++;
        }
    }
    return 0;
}