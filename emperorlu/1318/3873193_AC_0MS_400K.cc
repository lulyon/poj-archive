#include<iostream>
#include<algorithm>
using namespace std;
typedef struct
{
    char str[10];
}dict;
dict d[110];
char word[10];

bool cmp(const dict &aa,const dict &bb)
{
    return strcmp(aa.str,bb.str)<0;
}
bool match(char *aa,char *bb)
{
    int m=strlen(aa);
    int n=strlen(bb);
    if(m!=n)return 0;
    char cc[10],dd[10];
    for(int i=0;i<m;++i)
    {
        cc[i]=aa[i];
        dd[i]=bb[i];
    }
    sort(cc,cc+m);
    sort(dd,dd+m);
    for(int i=0;i<m;++i)
    {
        if(cc[i]!=dd[i])return 0;
    }
    return 1;
}

int main()
{
    int n=0;
    while(1)
    {
        scanf("%s",d[n++].str);
        if(d[n-1].str[0]=='X')break;
    }
    sort(d,d+n,cmp);
    while(1)
    {
        scanf("%s",word);
        if(word[0]=='X')break;
        bool flag=0;
        for(int i=0;i<n;++i)
        {
            if(match(word,d[i].str))
            {
                flag=1;
                printf("%s\n",d[i].str);
            }
        }
        if(flag==0)
            printf("NOT A VALID WORD\n");
        printf("******\n");
    }
    return 0;
}

