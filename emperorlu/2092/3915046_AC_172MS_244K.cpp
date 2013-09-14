#include<iostream>
using namespace std;
int num[10010];
int main()
{
    int i,j,n,m,tmp;
    while(1)
    {
        scanf("%d%d",&n,&m);
        if(!n&&!m)break;
        
        memset(num,0,sizeof(num));
        
        for(i=0;i<n;++i)
            for(j=0;j<m;++j)
            {
                scanf("%d",&tmp);
                ++num[tmp];
            }
        
        int max=0,sec=0;
        for(i=1;i<=10000;++i)
            if(max<num[i])max=num[i];
        
        for(i=1;i<=10000;++i)
        {
            if(max!=num[i]&&sec<num[i])
                sec = num[i];
        }
        for(i=1;i<=10000;++i)
        {
            if(sec==num[i])
            {
                printf("%d",i);
                ++i;
                break;
            }
        }
        for(;i<=10000;++i)
        {
            if(sec==num[i])
            {
                printf(" %d",i);
            }
        }
        printf("\n");
        
    }
    return 0;
}
