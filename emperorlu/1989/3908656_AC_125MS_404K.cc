#include<iostream>
using namespace std;
bool b[10010];
int main()
{
    int n,k,cnt,total,index;
    scanf("%d %d",&n,&k);
    memset(b,0,(k+5)*sizeof(bool));
    total=1;
    cnt=0;
    while(n--)
    {
        scanf("%d",&index);
        if(!b[index])
        {
            b[index]=1;
            ++cnt;
            if(cnt==k)
            {
               ++total; 
               memset(b,0,(k+5)*sizeof(bool));
               cnt=0;
            }
        }
    }
    printf("%d\n",total);
    return 0;
}
