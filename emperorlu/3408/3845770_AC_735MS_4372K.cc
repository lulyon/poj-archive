#include<iostream>
using namespace std;
int n;
struct
{
    int c[1010],num;
}a[1010];

bool b[1010];
int q[1010],cn[1010];
int bfs(int i)
{
    memset(b,0,(n+5)*sizeof(bool));
    b[i]=1;
    q[0]=i;
    cn[i]=0;
    
    int head=0,tail=0,max=0;
    while(head<=tail)
    {
        for(int j=0;j<a[q[head]].num;++j)
        {
            if(!b[a[q[head]].c[j]])
            {
                b[a[q[head]].c[j]]=1;
                q[++tail] = a[q[head]].c[j];
                cn[q[tail]] = cn[q[head]]+1;
                if(max<cn[q[tail]])
                    max=cn[q[tail]];
                
                //cout<<a[q[head]].c[j]<<endl;
            }
        }
        ++head;
    }
    for(int j=1;j<=n;++j)
        if(!b[j])return -1;
    return max;
    
}



int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&a[i].num);
        for(int j=0;j<a[i].num;++j)
        {
            scanf("%d",&(a[i].c[j]));
        }
    }
    int maxtime=-INT_MAX,tmp,index;
    bool flag=0;
    for(int i=1;i<=n;++i)
   // int i=1;
    {
        tmp = bfs(i);
        
        //cout<<tmp<<endl;
        if(tmp!=-1)
        {
            if(maxtime<=tmp)
            {
                flag=1;
                maxtime=tmp;
                index=i;
            }
        }
    }
    if(flag==0)
        printf("impossible\n");
    else
        printf("%d\n%d\n",maxtime,index);

    return 0;
}

