#include<iostream>
using namespace std;
int main()
{
    int n,t1,t2;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d %d",&t1,&t2);
        t1*=t2;
        printf("Scenario #%d:\n",i);
        if(t1%2)
            printf("%d.41\n\n",t1);
        else
            printf("%d.00\n\n",t1);
    }
    return 0;
}
