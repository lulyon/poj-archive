#include<iostream>
using namespace std;
long long a[1000];

void init()
{
    a[0]=9;
    for(int i=1;;i+=2)
    {
        a[i]=a[i-1]*2;
        a[i+1]=a[i]*9;
        if(a[i+1]>=4294967295)break;
    }
}
int main()
{
    init();
    int i,n;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;n>a[i];++i);
        if(i%2)
            printf("Ollie wins.\n");
        else
            printf("Stan wins.\n");
    }
    return 0;
}

