#include<iostream>
using namespace std;


int in[50000];
int cnt[50000];

const int n=32010;
//树状数组

//求最小幂2^k:
int Lowbit(int t)
{
    return t & ( t ^ ( t - 1 ) );
}

             
  //求前n项和：
int Sum(int end)
{
    int sum = 0;
    while(end > 0)
    {
        sum += in[end];
        end -= Lowbit(end);
    }
    return sum;
}

 //对某个元素进行加法操作： 
void Plus(int pos , int num)
{
    while(pos <= n)
    {
          in[pos] += num;
          pos += Lowbit(pos);
    }
} 

int main()
{
    int t;
    cin>>t;
    int n1,n2;
    for(int i=1;i<=t;++i)
    {
        scanf("%d%d",&n1,&n2);
        
        cnt[Sum(n1+1)]++;
        
        Plus(n1+1,1);
        
    }
    
    for(int i=0;i<t;++i)
        printf("%d\n",cnt[i]);
    
    return 0;
}
