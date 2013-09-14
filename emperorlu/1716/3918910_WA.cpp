#include<iostream>
using namespace std;
int num[10010];
int main()
{
    int min=INT_MAX,max=-INT_MAX,a,b,n;
    cin>>n;
    while(n--)
    {
        scanf("%d%d",&a,&b);
        if(min>a)min=a;
        if(min>b)min=b;
        if(max<a)max=a;
        if(max<b)max=b;
        
        for(int i=a;i<=b;++i)
            ++num[i];
    }
    int cn=0;
    for(int i=min;i<=max;++i)
        if(num[i]==2)++cn;
    
    printf("%d\n",cn);
    return 0;
}
