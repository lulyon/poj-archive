#include<iostream>
using namespace std;
int f,v;
int a[110][110];
void readin()
{
    scanf("%d%d",&f,&v);
    for(int i=0;i<f;++i)
        for(int j=0;j<v;++j)
            scanf("%d",&a[i][j]);
}
void dp()
{
    for(int i=1;i<f;++i)
        for(int j=i;j<=v-f+i;++j)
        {
            int max=a[i-1][0];
            for(int k=1;k<j;++k)
                if(max<a[i-1][k])max=a[i-1][k];
             a[i][j]+=max;
        }
    
    int max=a[f-1][f-1];
    for(int i=f;i<v;++i)
        if(max<a[f-1][i])max=a[f-1][i];
     printf("%d\n",max);
}
int main()
{
    readin();
    dp();
    return 0;
}