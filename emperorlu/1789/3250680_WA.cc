#include<iostream>
using namespace std;
char ac[2010][10];
int a[2020][2020],stack[2020];
bool visited[2020];
int main()
{
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(!n)break;
        for(int i=0;i<n;++i)
        {
            scanf("%s",ac+i);
            visited[i]=0;
        }
        for(int i=0;i<n;++i)
            for(int j=i+1;j<n;++j)
            {
                int cn=0;
                for(int k=0;k<7;++k)
                    if(ac[i][k]!=ac[j][k])
                        cn++;
                a[i][j]=cn;
                a[j][i]=cn;
            }
        
        continue;
        
        int s0,s1;
        int min = INT_MAX,tmp;
        for(int i=0;i<n;++i)
            for(int j=i+1;j<n;++j)
                if(a[i][j]<min)
                {
                    min = a[i][j];
                    s0 = i;
                    s1 = j;
                }
        
        visited[s0]=1;
        visited[s1]=1;
        stack[0]=s0;
        stack[1]=s1;
        
        int sum = min,top=2;
        while(1)
        {
            int min = INT_MAX,s;
            for(int i=0;i<top;++i)
                for(int j=0;j<n;++j)
                {
                    int k=stack[i];
                    if(k!=j && !visited[j] && a[k][j]<min)
                    {
                        min = a[k][j];
                        s = j;
                    }
                }
            sum += min;
            stack[top++]=s;
            visited[s]=1;
            if(top==n)break;
        }
        printf("The highest possible quality is 1/%d\n",sum);
    }
    return 0;
}
