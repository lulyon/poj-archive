#include<iostream>
using namespace std;
int stack[1000];
char tab[100000][100];
void f(int i)
{
    int s=0;
    for(int j=1;j<=tab[i-1][0];++j)
    {
        tab[i][j] = ((tab[i-1][j]-'0')*3+s)%10+'0';
        s = (s+(tab[i-1][j]-'0')*3)/10;
    }
    if(s)
    {
        tab[i][0]=tab[i-1][0]+1;
        tab[i][tab[i][0]]=s+'0';
    }
    else
        tab[i][0]=tab[i-1][0];
}
void init()
{
    tab[0][0]=1;
    tab[0][1]='1';
    for(int i=1;;++i)
    {
        f(i);
        if(tab[i][0]>90)break;
    }
}
void print(char *aa)
{
    for(int j=aa[0];j>0;--j)
        printf("%c",aa[j]);
}

int main()
{
    init();
    /*
    for(int i=0;i<10;++i)
    {
        print(tab[i]);
        cout<<endl;
    }
   */
    long long k,n,m;
    
    while(scanf("%lld",&n),n)
    {
        if(n==1)
        {
            printf("{ }\n");
            continue;
        }
        int top=0,k=0;
        n--;
        
        while(n>0)
        {
            if(n%2)
            {
                stack[top++]=k;
            }
            n>>=1;
            ++k;
        }
        printf("{ ");
        for(int i=0;i<top-1;++i)
        {
            print(tab[stack[i]]);
            printf(", ");
        }
        print(tab[stack[top-1]]);
        printf(" }\n");
     
    }
     
    return 0;
}
