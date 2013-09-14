#include<iostream>
using namespace std;
char a[60010],b[60010];
int numa[30],numb[30];
int f(int a,int b)
{
    if(a>b)
        return a-b;
    
    else return b-a;
}


int main()
{
    int n,tt=0;
    scanf("%d",&n);
    getchar();
    while(gets(a))
    {
        gets(b);
       
        memset(numa,0,sizeof(numa));
        memset(numb,0,sizeof(numb));
        
        
        for(int i=0;a[i];++i)
            ++numa[a[i]-'a'];
        for(int i=0;b[i];++i)
            ++numb[b[i]-'a'];
        
        int cn=0;
        for(int i=0;i<26;++i)
            cn+=f(numa[i],numb[i]);
        
        printf("Case #%d:  %d\n",++tt,cn);
    }
    return 0;
}


