#include<iostream>
using namespace std;
double x[1010],y[1010];

typedef struct
{
    int index[1010];
    int num;
}adj;
adj v[1010];

bool b[1010];

char str[100];

int que[1010];
int visit[1010];

int stack[1010];

bool bfs(int i,int j)
{
    if(!b[i]||!b[j])return 0;
    if(i==j)return 1;

    que[0]=i;
    int top=0;
    stack[top++]=i;
    visit[i]=1;
    
    
    int head,tail,ver,index;
    head=tail=0;
    
    while(head<=tail)
    {
        ver=que[head];
        for(int ii=0;ii<v[ver].num;++ii)
        {
            index=v[ver].index[ii];
            if(b[index]&&!visit[index])
            {
                if(index==j)
                {
                    for(int jj=0;jj<top;++jj)
                        visit[stack[i]]=0;
                    return 1;
                }
                else
                {
                    visit[index]=1;
                    stack[top++]=index;
                    ++tail;
                    que[tail]=index;
                }
            }
        }
        head++;
    }
    return 0;
}

double dist(double x1,double y1,double x2,double y2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int main()
{
    int n,d,ds;
    cin>>n>>d;
    
    scanf("%lf%lf",x+1,y+1);
    v[1].num=0;
    b[1]=0;
    for(int i=2;i<=n;++i)
    {
        scanf("%lf%lf",x+i,y+i);
        v[i].num=0;
        b[i]=0;
        for(int j=1;j<i;++j)
        {
            ds = dist(x[i],y[i],x[j],y[j]);
            
            if(ds<=d*d)
            {
                //cout<<"hello"<<endl;
                v[i].index[v[i].num]=j;
                v[i].num++;
                
                v[j].index[v[j].num]=i;
                v[j].num++;
            }
        }
    }
    int p,q;
    while(scanf("%s",str)!=EOF)
    {
        if(str[0]=='O')
        {
            scanf("%d",&p);
            b[p]=1;
        }
        else if(str[0]=='S')
        {
            scanf("%d%d",&p,&q);
            if(bfs(p,q))
                printf("SUCCESS\n");
            else
                printf("FAIL\n");
        }
    }
    return 0;
}
