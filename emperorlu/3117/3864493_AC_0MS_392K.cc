#include<iostream>
using namespace std;
char s[100];
int main()
{
    int sum,tmp,t,n;
    while(1)
    {
        scanf("%d %d",&t,&n);
        if(!t&&!n)break;
        sum=0;
        while(t--)
        {
            scanf("%s %d",s,&tmp);
            sum+=tmp;
        }
        printf("%d\n",3*n-sum);
    }
    return 0;
}
