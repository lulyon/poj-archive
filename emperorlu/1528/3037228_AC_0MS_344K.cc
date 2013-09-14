#include<iostream>
#include<cmath>
using namespace std;
int check(int n)
{
    int m=(int)sqrt(n),sum=0;
    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%i==0)
            sum+=i+n/i;
        if(i*i==n)sum-=i;
    }
    sum-=n;
    if(sum<n)return -1;
    else if(sum==n)return 0;
    else if(sum>n)return 1;
}
int main()
{
    int n;
    cout<<"PERFECTION OUTPUT"<<endl;
    while(1)
    {
        cin>>n;
        if(!n)break;
        if(n==1)
            printf("%5d  DEFICIENT\n",n);
        else
        {
            int flag=check(n);
            if(flag==-1)
                printf("%5d  DEFICIENT\n",n);
            else if(flag==0)
                printf("%5d  PERFECT\n",n);
            else if(flag==1)
                printf("%5d  ABUNDANT\n",n);
        }
    }
    cout<<"END OF OUTPUT"<<endl;
    //system("pause");
    return 0;
}
