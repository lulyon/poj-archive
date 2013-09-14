#include<iostream>
#include<algorithm>
using namespace std;
typedef struct
{
    char str[20];
}TYPE;
TYPE info[10];
bool cmp(const TYPE &aa,const TYPE &bb)
{
    return strcmp(aa.str,bb.str)<0;
}
bool prefix(char *aa,char *bb)
{
    for(int i=0;aa[i];++i)
    {
        if(aa[i]!=bb[i])return 0;
    }
    return 1;
}

int main()
{
    int ttt=0,n=0;
    while(scanf("%s",info[n].str)!=EOF)
    {
        if(info[n].str[0]=='9')
        {
            sort(info,info+n,cmp);
            bool flag=0;
            for(int i=0;i<n;++i)
            {
                for(int j=i+1;j<n;++j)
                {
                    if(prefix(info[i].str,info[j].str))
                    {
                        printf("Set %d is not immediately decodable\n",++ttt);
                        flag=1;
                        goto leap;
                    }
                    else break;
                }
            }
            leap:
            if(flag==0)
                printf("Set 1 is immediately decodable\n",++ttt);
            
            n=0;
        }
        else
        {
            ++n;
        }
    }
    return 0;
}
