#include<iostream>
using namespace std;
int judge(int max,int min)
{
    if(min==1&&max==2||max+1==2*min)return 0;
    else return 1;
}
int main()
{
    __int64 a,b,tmp;
    while(cin>>a>>b)
    {
        if(a<b)
        {
            tmp=a;
            a=b;
            b=tmp;
        }
        cout<<judge(a,b)<<endl;
    }
    return 0;
}
