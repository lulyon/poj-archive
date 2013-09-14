#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 1010
int t[N],step[N][2],sn;

int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}

int solve(int z,int y,int b,int a,int n)
{
    if(n==1)
    {
        step[sn++][0]=t[a];
        return t[a];
    }
    else if(n==2)
    {
        step[sn][0]=t[a];
        step[sn++][1]=t[b];
        return t[b];
    }
    else if(n==3)
    {
        step[sn][0]=t[a];
        step[sn++][1]=t[b];
        step[sn++][0]=t[a];
        step[sn][0]=t[a];
        step[sn++][1]=t[z];
        return t[a]+t[b]+t[z];
    }
    else if(n>=4)
    {
        if(2*t[b]>=t[a]+t[y])
        {
            step[sn][0]=t[a];
            step[sn++][1]=t[z];
            step[sn++][0]=t[a];
            step[sn][0]=t[a];
            step[sn++][0]=t[y];
            step[sn++][0]=t[a];
            return solve(z-2,y-2,b,a,n-2)+2*t[a]+t[z]+t[y];
        }
        else
        {
            step[sn][0]=t[a];
            step[sn++][1]=t[b];
            step[sn++][0]=t[a];
            step[sn][0]=t[y];
            step[sn++][1]=t[z];
            step[sn++][0]=t[b];
            return solve(z-2,y-2,b,a,n-2)+2*t[b]+t[a]+t[z];
        }
    }
    else return 0;
}

int main()
{
    int n;
    int i;
    scanf("%d",&n);
    {
        sn=0;
        memset(step,-1,sizeof(step));
        for(i=0;i<n;i++)scanf("%d",&t[i]);
        qsort(t,n,sizeof(int),cmp);
        printf("%d\n",solve(n-1,n-2,1,0,n));
        i=0;
        while(step[i][0]!=-1)
        {
            printf("%d",step[i][0]);
            if(step[i][1]!=-1)
                printf(" %d",step[i][1]);
            printf("\n");
            i++;
        }
    }
    return 0;
}
