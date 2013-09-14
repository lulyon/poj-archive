#include<stdio.h>
int main()
{
    int i,j,n,smax,a[100][100],b[100]={0};
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            {
                scanf("%d",*(a+i)+j);
            }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(a[i][j]>a[j][i])b[i]++;
    for(smax=0,i=1;i<n;i++)
    {
       if(b[i]>b[smax])smax=i;
    }
    printf("%d\n",smax+1);
    return 0;     
}
