#include<iostream>
#include<set>
using namespace std;
int main()
{
    int k,m,r,c,tmp,cnt;
    set<int> iset;
    while(1)
    {
        scanf("%d",&k);
        if(!k)break;
        
        scanf("%d",&m);
        while(k--)
        {
            scanf("%d",&tmp);
            iset.insert(tmp);
        }
        int flag=0;
        while(m--)
        {
            scanf("%d %d",&c,&r);
            cnt=0;
            while(c--)
            {
                scanf("%d",&tmp);
                if(iset.count(tmp))++cnt;
            }
            if(cnt<r)flag=1;
        }
        if(flag)printf("no\n");
        else printf("yes\n");
        iset.clear();
    }
    return 0;
}
