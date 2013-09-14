#include<stdio.h>
int main()
{
    long f0,f1,f2,f3,f4,f5;
    while(scanf("%d%d%d",&f0,&f1,&f2)!=EOF)
    {
        f3=1*f0-3*f1+3*f2;
        f4=3*f0-8*f1+6*f2;
        f5=6*f0-15*f1+10*f2;
        printf("%d %d %d\n",f3,f4,f5);
    }
    return 0;
}
