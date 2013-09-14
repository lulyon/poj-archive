#include<iostream>
using namespace std;
bool notselfnum[10000];
void calc()
{
    notselfnum[1]=0;
    notselfnum[2]=1;
    for(int i=2;i<10000;i++)
    {
        int sum=i,n=i;
        while(n)
        {
            sum+=n%10;
            if(sum>=10000)break;
            n/=10;
        }
        if(sum<10000)notselfnum[sum]=1;
    }
}
int main()
{
    calc();
    for(int i=1;i<10000;i++)
        if(!notselfnum[i])
            printf("%d\n",i);
    //system("pause");
    return 0;
} 
