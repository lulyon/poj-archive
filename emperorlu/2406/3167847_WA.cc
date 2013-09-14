#include<iostream>
using namespace std;
char T[1000000];
int next[1000000];
bool same(char T[])
{
    int len = strlen(&T[1]);
    if(len==1)return 1;
    else
    {
        for(int i=2;i<=len;++i)
            if(T[1]!=T[i])return 0;
        return 1;
    }
}

int gcd(int m,int n)
{
    int tmp;
    while(n)
    {
        tmp = n;
        n = m % n;
        m = tmp;
    }
    return m;
}

void get_next(char T[],int next[])
{
    int i=1,j=0;
    next[1]=0;
    T[0]=strlen(&T[1]);
    while(i<=T[0])
    {
        if(j==0||T[i]==T[j])
        {
            ++i;
            ++j;
            next[i]=j;
        }
        else j=next[j];
    }
}

int main()
{
    while(1)
    {
        scanf("%s",&T[1]);
        if(T[1]=='.')break;
        int len = strlen(&T[1]);
        if(len==1)
        {
            printf("1\n");
            continue;
        }
        get_next(T,next);
        int tmp = gcd(len,next[len]);
        if(tmp==1)
        {
            if(same(T))
                printf("%d\n",len);
            else
                printf("1\n");
        }
        else
            printf("%d\n",len/tmp);
    }
    return 0;
}
