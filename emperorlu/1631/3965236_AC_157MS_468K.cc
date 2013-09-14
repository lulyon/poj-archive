#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
    int a[40005],c,m,n,i,k,t;
    scanf("%d",&m);
    while(m-->0)
    {
        scanf("%d",&n);
        if(n==0){printf("0\n");continue;}
        for(i=0;i<=n+2;i++)a[i]=0;
        c=1;
        scanf("%d",&t);
        a[0]=t;
        for(k=1;k<n;k++)
        {
            scanf("%d",&t);
            if(t>a[c-1]) a[c++]=t;
            else
            {
                int l=0,h=c-1,mid=(l+h)/2;
                while(l<h)
                {
                    if(a[mid]<t)l=mid+1;     //而来要注意上下指针的改变不一样
                    else if(a[mid]>t)h=mid;
                    mid=(l+h)/2;
                }
                a[mid]=t;
            }
        }
        printf("%d\n",c);
    }    
    //system("pause");
    //while(1);
    return 0;
}

