#include<iostream>
using namespace std;
bool b[50010];
int main()
{
    int i,j,n,m,tt=0;
    while(1)
    {
        cin>>n>>m;
        if(!n&&!m)break;
        memset(b,0,(n+5)*sizeof(bool));
        int t1,t2,cn=0;
        for(i=0;i<m;++i)
        {
            scanf("%d%d",&t1,&t2);
            if(!b[t1]&&!b[t2])
                cn++;
            b[t1]=b[t2]=1;
        }
        for(i=1;i<=n;++i)
            if(!b[i])cn++;
        ++tt;
        cout<<"Case ";
        cout<<tt;
        cout<<": ";
        cout<<cn;
        cout<<endl;
    }
    return 0;
}
