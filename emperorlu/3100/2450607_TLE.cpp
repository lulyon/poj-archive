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
   //     printf("%ld %ld\n",i,mut1);
    }
//     printf("%ld %ld\n",i,mut1);

    i-=2;
    if(i>0)
    {
        for(j=1,mut2=1;j<=n;j++)
        {
            mut2*=i;
        }
        if(mut1+mut2>=2*b)a=i;
            else a=i+1;
    }
    else a=1;
    //printf("%ld%ld",i,a);
    printf("%ld\n",a);
    }
    while(1);
    return 0;
}
