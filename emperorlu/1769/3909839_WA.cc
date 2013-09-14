#include<iostream>
#include<algorithm>
using namespace std;
#define M 1000010
int R[M];
typedef struct
{
    int l,r;
}interval;
interval ival[M];
bool cmp(const interval &a,const interval &b)
{
    if(a.l!=b.l)
        return a.l<b.l;
    else
        return (a.r<b.r);
}
int main()
{
    int n,m;
    //while(1)
    {
        scanf("%d%d",&n,&m);
        
        for(int i=0;i<m;++i)
        {
            scanf("%d%d",&ival[i].l,&ival[i].r);
        }
        sort(ival,ival+m,cmp);
        
        
        
        R[0]=ival[0].r;
        int top=1,cn=1,r=R[0];
        if(r>=n)
        {
            printf("1\n");
            return 0;
        }
        for(int i=1;i<m;++i)
        {
            if(ival[i].r>r)
            {
                r=ival[i].r;
                for(int j=0;j<top;++j)
                {
                    if(ival[i].l<=R[j])
                    {
                        cn=j+2;
                        top=j+1;
                        R[top++]=r;
                        break;
                    }   
                }
                if(r>=n)
                {
                    printf("%d\n",cn);
                    break;
                }
                
            }
        }
    }
    //system("pause");
    return 0;
}


