#include<iostream>
#include<vector>
using namespace std;

int stack[30010];
bool b[30010];
int main()
{
    int n,m,k,num;
    while(1)
    {
        scanf("%d%d",&n,&m);
        if(!n&&!m)break;
        vector<int> label[n+10];
        vector<int> index[m+10];
        vector<int>::iterator i1,i2,end1,end2;
        memset(b,0,sizeof(b));
        int flag=0;
        for(int i=1;i<=m;++i)
        {
            scanf("%d",&k);
            for(int j=0;j<k;++j)
            {
                scanf("%d",&num);
                label[num].push_back(i);
                index[i].push_back(num);
                if(num==0)flag=1;
            }
        }
        if(flag==0)
        {
            printf("1\n");
            continue;
        }
        int cnt=0;
        stack[0]=0;
        int head,tail,code,group;
        head=tail=0;
        while(head<=tail)
        {
            code=stack[head];
            end1=label[code].end();
            for(i1=label[code].begin();i1<end1;++i1)
            {
                group = *i1;
                end2=index[group].end();
                for(i2=index[group].begin();i2<end2;++i2)
                {
                    if(!b[*i2])
                    {
                        ++cnt;
                        b[*i2]=1;
                        stack[++tail]=*i2;
                    }
                }
            }
            ++head;
        }
        printf("%d\n",cnt);
        
    }
    return 0;
}
