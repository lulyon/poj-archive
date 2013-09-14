#include<iostream>
#include<algorithm>
using namespace std;
typedef struct
{
    int top;
    int info[110];
}node;
node stack[110];
int main()
{
    //freopen("/export/home/acm/Desktop/1.dat","r",stdin);
    int p,t,i,j,k;
    cin>>p>>t;
    int tmp,t1,t2;
    while(scanf("%d%d",&t1,&t2)!=EOF)
    {
        stack[t1].info[stack[t1].top++]=t2;
    }
    if(p==1)
    {
        printf("1\n");
        return 0;
    }
 
    for(i=1;i<=p;++i)
    {
        sort(stack[i].info,stack[i].info+stack[i].top);
    }

    
    bool flag;
    int cn=1;
    for(i=2;i<=p;++i)
    {
        flag=0;
        for(j=1;j<i;++j)
        {
            if(stack[i].top!=stack[j].top)
            {
                continue;
            }
            for(k=0;k<stack[i].top;++k)
            {
                if(stack[i].info[k]!=stack[j].info[k])
                {
                    break;
                }
            }
            if(k==stack[i].top)
            {
                flag=1;
                break;
            }            
        }
        if(flag==0)++cn;
    }
    printf("%d\n",cn);
    return 0;
}

