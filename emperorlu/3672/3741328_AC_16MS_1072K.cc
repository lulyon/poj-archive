#include<iostream>
using namespace std;
int main()
{
    int m,t,u,f,d;
    scanf("%d%d%d%d%d",&m,&t,&u,&f,&d);
    int flat,up;
    up=u+d;
    flat=f+f;
    getchar();
    int sum=0;
    for(int i=0;i<t;++i)
    {
        if(getchar()=='f')
            sum+=flat;
        else
            sum+=up;
        if(sum>m)
        {
            cout<<i<<endl;
            return 0;
        }
        getchar();
    }
    
    return 0;
}