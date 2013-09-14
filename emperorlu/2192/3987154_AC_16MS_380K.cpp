#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
char a[210],b[210],c[420];
int store[210][210];

int cnt[256];

int la,lb,lc;

int workout()
{
    int i,j;
    memset(store,0,sizeof(store));
    for(i=0;i<la;i++)
    {
        if(a[i]==c[i])store[i+1][0]=1;
        else break;
    }
    for(j=0;j<lb;j++)
    {
        if(b[j]==c[j])store[0][j+1]=1;
        else break;
    }
    
    for(i=0;i<=la;i++)
    {
        for(j=0;j<=lb;j++)
        {
            if(store[i][j]&&(i||j))
            {
                if(a[i]==c[i+j])store[i+1][j]=1;
                if(b[j]==c[i+j])store[i][j+1]=1;
            }
        }
    }
    if(store[la][lb]==1)return 1;
    else return 0;
}
int main()
{
    int num,z=0;
    scanf("%d",&num);
    while(num--)
    {
        z++;
        scanf("%s %s %s",a,b,c);
        printf("Data set %d: ",z);
        
        la = strlen(a);
        lb = strlen(b);
        lc = strlen(c);
        if(la+lb!=lc)
            printf("no\n");
        else
        {
            memset(cnt,0,sizeof(cnt));
            
            for(int i=0;i<la;++i)
                ++cnt[a[i]];
            
            for(int i=0;i<lb;++i)
                ++cnt[b[i]];
            
            for(int i=0;i<lc;++i)
                --cnt[c[i]];
            
            bool flag=0;
            for(int i=0;i<26;++i)
            {
                if(cnt[i+'A']||cnt[i+'a'])
                {
                    printf("no\n");
                    flag=1;
                    break;
                }
            }
            if(!flag)
            {   
                if(workout())
                    printf("yes\n");
                else
                    printf("no\n");
            }
        }
    }
    return 0;
}
