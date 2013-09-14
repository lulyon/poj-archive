#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 1010
int t[N];

int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}

int solve(int z,int y,int b,int a,int n)
{
    if(n==1)
            return t[a];
    else if(n==2)
        return t[b];
    else if(n==3)
        return t[a]+t[b]+t[z];
    else if(n>=4)
    {
        if(2*t[b]>=t[a]+t[y])
            return solve(z-2,y-2,b,a,n-2)+2*t[a]+t[z]+t[y];
        else
            return solve(z-2,y-2,b,a,n-2)+2*t[b]+t[a]+t[z];
    }
    else return 0;
}

int main()
{
    int n;
    int i,tt;
    scanf("%d",&tt);
    while(tt--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)scanf("%d",&t[i]);
        qsort(t,n,sizeof(int),cmp);
        printf("%d\n",solve(n-1,n-2,1,0,n));
    }
    return 0;
}
