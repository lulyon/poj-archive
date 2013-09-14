#include<iostream>
using namespace std;
int cn;

void judge(int a,int b)
{
    if(a==b)return;
    if(a<b)
    {
        if(b/a>=2)return;
        ++cn;
        judge(a,b-a);
    }
    else
    {
        if(a/b>=2)return;
        ++cn;
        judge(a-b,b);
    }
}

int main()
{
    int m,n;
    while(1)
    {
        scanf("%d%d",&m,&n);
        if(!m&&!n)break;
        
        cn=0; 
        judge(m,n);
        if(cn%2)
            printf("Ollie wins\n");
        else
            printf("Stan wins\n");
    }
    return 0;
}
