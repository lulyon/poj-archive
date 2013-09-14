#include<iostream>
#include<algorithm>
using namespace std;
typedef struct
{
    int x,y;
}pt;
pt point[6];
int stack[6];
bool b[6];
void swap(int &aa,int &bb)
{
    aa^=bb^=aa^=bb;
}

bool cmp(const pt &aa,const pt &bb)
{
    if(aa.x!=bb.x)
        return aa.x>bb.x;
    else
        return aa.y>=bb.y;
}
int main()
{
    int i;
    leap:;
    while(scanf("%d%d%d%d%d%d%d%d%d%d%d%d",
&point[0].x,&point[0].y,&point[1].x,&point[1].y,
&point[2].x,&point[2].y,&point[3].x,&point[3].y,
&point[4].x,&point[4].y,&point[5].x,&point[5].y)!=EOF)
    {
        for(i=0;i<6;++i)
        {
            if(point[i].x<point[i].y)
                swap(point[i].x,point[i].y);
        }
        sort(point,point+6,cmp);
        for(i=0;i<6;i+=2)
        {
            if(point[i].x!=point[i+1].x || point[i].y!=point[i+1].y)
            {
                printf("IMPOSSIBLE\n");
                goto leap;
            }
        }
        
        for(i=0;i<6;i+=2)
        {
            stack[i]=point[i].x;
            stack[i+1]=point[i].y;
        }
        memset(b,0,sizeof(b));
        for(i=2;i<6;++i)
            if(!b[i]&&stack[0]==stack[i])
            {
                b[i]=1;
                break;
            }
        if(i==6)
        {
            printf("IMPOSSIBLE\n");
            continue;
        }
        for(i=2;i<6;i+=2)
            if(!b[i]&&!b[i+1])
            {
                if(stack[1]==stack[i])
                {
                    b[i]=1;
                    break;
                }
                if(stack[1]==stack[i+1])
                {
                    b[i+1]=1;
                    break;
                }
            }
        if(i==6)
        {
            printf("IMPOSSIBLE\n");
            continue;
        }
        int top=0;
        for(int i=2;i<6;++i)
        {
            if(!b[i])
                stack[top++]=stack[i];
        }
        if(stack[0]==stack[1])
            printf("POSSIBLE\n");
        else
            printf("IMPOSSIBLE\n");
    }
    return 0;
}
