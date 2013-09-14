#include<iostream>
using namespace std;
int len;
char s[1000];
char re[2000];
char rf[2000];
char pre[5][100]=
{
    "anti","post","pre","re","un"
};
char premin[5][100]=
{
    "against <","after <","before <","< again","not <"
};
char post[5][100]=
{
    "er","ing","ize","s","tion"
};
char postmin[5][100]=
{
    "one who <s","to actively <","change into <","multiple instances of <","the process of <ing"
};

bool prefix(int i,int &ii)
{
    int j;
    for(j=0;pre[i][j]&&s[j];++j)
    {
        if(pre[i][j]!=s[j])return 0;
    }
    if(s[j])
    {
        ii=j;
        return 1;
    }
    else return 0;
}
bool suffix(int i,int &jj)
{
    int j,k;
    for(j=len-1,k=strlen(post[i])-1;j>=0&&k>=0;--j,--k)
    {
        if(post[i][k]!=s[j])return 0;
    }
    if(j>=0)
    {
        jj=j;
        return 1;
    }
    else return 0;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%s",s);
        len=strlen(s);
        int ii,iindex,jj,jindex;
        bool flag1=0,flag2=0;
        for(int i=0;i<5;++i)
        {
            if(prefix(i,ii))
            {
                flag1=1;
                iindex=i;
                break;
            }
        }
        
        for(int i=0;i<5;++i)
        {
            if(suffix(i,jj))
            {
                flag2=1;
                jindex=i;
                break;
            }
        }
        if(flag1)
        {
            if(flag2)
            {
                int top=0;
                for(int i=0;postmin[jindex][i];++i)
                {
                    if(postmin[jindex][i]!='<')
                    {
                        re[top++]=postmin[jindex][i];
                    }
                    else
                    {
                        for(int j=ii;j<=jj;++j)
                        {
                            re[top++]=s[j];
                        }
                    }
                }
                re[top]=0;
                int top1=0;
                for(int i=0;premin[iindex][i];++i)
                {
                    if(premin[iindex][i]!='<')
                    {
                        rf[top1++]=premin[iindex][i];
                    }
                    else
                    {
                        for(int j=0;j<top;++j)
                        {
                            rf[top1++]=re[j];
                        }
                    }
                }
                rf[top1]=0;
                
                printf("%s\n",rf);
            }
            else
            {
                int top1=0;
                for(int i=0;premin[iindex][i];++i)
                {
                    if(premin[iindex][i]!='<')
                    {
                        rf[top1++]=premin[iindex][i];
                    }
                    else
                    {
                        for(int j=ii;s[j];++j)
                        {
                            rf[top1++]=s[j];
                        }
                    }
                }
                rf[top1]=0;
                printf("%s\n",rf);
            }
        }
        else
        {
            if(flag2)
            {
                int top=0;
                for(int i=0;postmin[jindex][i];++i)
                {
                    if(postmin[jindex][i]!='<')
                    {
                        re[top++]=postmin[jindex][i];
                    }
                    else
                    {
                        for(int j=0;j<=jj;++j)
                        {
                            re[top++]=s[j];
                        }
                    }
                }
                re[top]=0;
                printf("%s\n",re);
            }
            else
            {
                printf("%s\n",s);
            }
        }
    }
    return 0;
}

