#include<iostream>
#include<algorithm>
using namespace std;
__int64 que[10000000];
int main()
{
    int p1,p2,p3,n,head,tail;
    scanf("%d %d %d %d",&p1,&p2,&p3,&n);
    
    if(p1>p2)
    {
        p1^=p2^=p1^=p2;
    }
    if(p2>p3)
    {
        p2^=p3^=p2^=p3;
    }
    
    que[1]=p1;
    que[2]=p2;
    que[3]=p3;
    
    head=1;
    tail=3;
    
    while(head<=tail)
    {
        for(int i=1;i<=head;++i)
        {
            que[++tail]=que[i]*que[head];
            if(que[tail]>1e18)goto leap;
        }
        head++;
    }
    leap:;
    sort(que+1,que+tail+1);
    unique(que+1,que+tail+1);
    printf("%I64d\n",que[n]);
    
    return 0;
}

