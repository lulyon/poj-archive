#include<iostream>
using namespace std;
int num[1010];

char str[10];

int l,r;

int main()
{
    int n,t,min,max;
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        
        min=INT_MAX;
        max=-INT_MAX;
        
        
        memset(num,0,sizeof(num));
        
        for(int i=0;i<n;++i)
        {
           scanf("%s",str);
           scanf("%d%d",&l,&r);
           
           --r;
           
           for(int j=l;j<=r;++j)
               ++num[j];
           
           
           if(min>l)min=l;
           if(min>r)min=r;
           
           if(max<l)max=l;
           if(max<r)max=r;
           
        }
        
        for(int i=min;i<=max;++i)
            if(num[i]>0)printf("%c",'A'+num[i]-1);
        printf("\n");
    }
    return 0;
}
