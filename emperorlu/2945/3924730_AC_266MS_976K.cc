#include<iostream>
#include<algorithm>
using namespace std;
typedef struct
{
    char str[25];
}node;
node a[30000];

int num[30000];

bool cmp(const node &aa,const node &bb)
{
    return strcmp(aa.str,bb.str)<0;
}
int main()
{
    int n,m;
    while(1)
    {
        scanf("%d%d",&n,&m);
        if(!n&&!m)break;
        
        for(int i=0;i<n;++i)
        {
            scanf("%s",a[i].str);
            num[i]=0;
        }
        
        sort(a,a+n,cmp);
       
        
        int cn=0;
        a[n].str[0]=0;
        for(int i=1;i<=n;++i)
        {
            if(strcmp(a[i].str,a[i-1].str)==0)
                ++cn;
            else
            {
                ++num[cn];
                cn=0;
            }
        }
        
        for(int i=0;i<n;++i)
            printf("%d\n",num[i]);
    }
    return 0;
}
