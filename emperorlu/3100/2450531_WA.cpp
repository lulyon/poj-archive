#include<stdio.h>
int main()
{
    long i,j,a,b,mut1,mut2,n;
    while((scanf("%ld%ld",&b,&n),b)!=0)
   { for(i=1,mut1=1;mut1<b;i++)
    {
        mut1=1;
        for(j=1;j<=n;j++)
        {
            mut1*=i;
        }
    }
    i-=2;
    for(j=1,mut2=1;j<=n;j++)
    {
        mut2*=i;
    }
    if(mut1+mut2>=2*b)a=i;
    else a=i+1;
    printf("%ld\n",a);
    }
    return 0;
}
