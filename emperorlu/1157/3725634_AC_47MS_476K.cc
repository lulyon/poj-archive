#include<iostream>
using namespace std;
int f,v;
int a[110][110];
void readin()
{
    cin>>f>>v;
    for(int i=0;i<f;++i)
        for(int j=0;j<v;++j)
            scanf("%d",&a[i][j]);
}
int dp()
{
    for(int i=1;i<f;++i)
    {
        for(int j=i;j<v;++j)
        {
            int max=-1000;
            for(int k=0;k<j;++k)
            {
                if(max<a[i-1][k])max=a[i-1][k];
            }
            a[i][j]+=max;
        }
    }
    int max=-1000;
    for(int i=f-1;i<v;++i)
    {
        if(max<a[f-1][i])max=a[f-1][i];
    }
    return max;
}
void print()
{
    cout<<dp()<<endl;
}
int main()
{
    readin();
    print();
    return 0;
}