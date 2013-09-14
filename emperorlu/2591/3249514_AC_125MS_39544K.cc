#include<iostream>
using namespace std;
int n,store[10000005];
void workout()
{
    int num,one,two,t1,t2;
    store[1]=1;
    one=two=1;
    for(num=2;num<=10000000;num++)
    {
        t1=2*store[one]+1;
        t2=3*store[two]+1;
        if(t1<t2)
        {
           store[num]=t1;
           one++;
        }
        else if(t1>t2)
        {
           store[num]=t2;
           two++;
        }
        else
        {
            store[num]=t1;
            one++;two++;
        }
    }//拍案叫绝 
}
int main()
{
    workout();
    
    while(scanf("%d",&n)!=EOF)
        printf("%d\n",store[n]);

    return 0;
}
