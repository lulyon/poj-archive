#include<iostream>
#include<algorithm>
using namespace std;
long long que[10000000];
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
    que[4]=p1*p1;
    que[5]=p1*p2;
    que[6]=p2*p2;
    sort(que+1,que+6);
    
    head=3;
    tail=6;
    
    while(head<=tail)
    {
            que[++tail]=p1*que[head];
            que[++tail]=p2*que[head];
            que[++tail]=p3*que[head];
            if(que[tail]>1e18)break;
        head++;
    }
    
    sort(que+1,que+tail+1);
    unique(que+1,que+tail+1);
    
    printf("%I64d\n",que[n]);
    
    return 0;
}

