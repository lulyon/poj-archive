#include<iostream>
using namespace std;
char a[10000];
bool b[26];
bool c[26];
int main()
{
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(!n)break;
        
        memset(b,0,sizeof(b));
        
        memset(c,0,sizeof(c));
        
        scanf("%s",a);
        
        int cn=0,ans=0;
        for(int i=0;a[i];++i)
        {
            if(!b[a[i]-'A'])
            {
                if(cn==n)
                {
                    c[a[i]-'A']=1;
                    b[a[i]-'A']=1;
                    ans++;
                }
                else
                {
                    cn++;
                    b[a[i]-'A']=1;
                }
            }
            else
            {
                b[a[i]-'A']=0;
                if(!c[a[i]-'A'])cn--;
            }
        }
        if(ans)
            printf("%d customer(s) walked away.\n",ans);
        else
            printf("All customers tanned successfully.\n");
    }
    return 0;
}
