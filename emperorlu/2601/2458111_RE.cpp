#include<stdio.h>
float f(float a[],float c[],int n,int p)
{
    if(p==0)return a[0];
    else if(p==n+1)return a[n+1];
    else return (f(a,c,n,p-1)+f(a,c,n,p+1))/2-c[p];
       
}
int main()
{
    int i,n;
    float a[10000],c[10000];
    scanf("%d",&n);
    scanf("%f%f",&a[0],&a[n+1]);
    for(i=1;i<=n;i++)
    {
        scanf("%f",c+i);
    }
    a[1]=f(a,c,n,1);
    printf("%.2f\n",a[1]);
    return 0;    
}
