#include<iostream>
using namespace std;
bool isselfnum[10000];
void calc()
{
    isselfnum[1]=1;
    isselfnum[2]=0;
    for(int i=2;i<10000;i++)
    {
        int sum=i,n=i;
        while(n)
        {
            sum+=n%10;
            if(sum>=10000)break;
            n/=10;
        }
        if(sum<10000)isselfnum[sum]=1;
    }
}
int main()
{
    calc();
    for(int i=1;i<10000;i++)
        if(isselfnum[i])
            printf("%d\n",i);
    return 0;
} 
