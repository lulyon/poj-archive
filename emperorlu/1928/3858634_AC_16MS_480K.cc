#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 55
int m,n,k;
typedef struct
{
    int i,j,data;
}INFO;
INFO info[MAXN*MAXN];

bool cmp(const INFO &aa,const INFO &bb)
{
    return aa.data>bb.data;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%d%d%d",&m,&n,&k);
        int top=0,tmp;
        for(int i=1;i<=m;++i)
        {
            for(int j=1;j<=n;++j)
            {
                scanf("%d",&tmp);
                if(tmp)
                {
                    info[top].i=i;
                    info[top].j=j;
                    info[top].data=tmp;
                    ++top;
                }
            }
        }
        
        
        
        if(top==0)
        {
            printf("0\n");
            continue;
        }

        if(top==1)
        {
            if(2*info[0].i+1<=k)
                printf("%d\n",info[0].data);
            else
                printf("0\n");
            continue;
        }
        sort(info,info+top,cmp);
        
        int time=info[0].i+1,sum=info[0].data;
        
        if(time+info[0].i>k)
        {
            printf("0\n");
            continue;
        }
        
        int id,jd;
        bool flag=0;
        
        for(int i=1;i<top;++i)
        {
            id=info[i].i-info[i-1].i;
            if(id<0)id=-id;
            jd=info[i].j-info[i-1].j;
            if(jd<0)jd=-jd;
            
            tmp = id+jd+1;
            time+=tmp;
            
            if(time+info[i].i>k)
            {
                flag=1;
                printf("%d\n",sum);
                break;
            }
            
            sum+=info[i].data;
            //cout<<sum<<endl;
        }
        if(flag==0)
        {
            printf("%d\n",sum);
        }
    }
    return 0;
}


