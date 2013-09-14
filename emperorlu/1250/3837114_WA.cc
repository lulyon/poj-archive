#include<iostream>
using namespace std;
char a[10000];
bool b[26];
int main()
{
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(!n)break;
        
        memset(b,0,sizeof(b));
        scanf("%s",a);
        
        int cn=0,ans=0;
        for(int i=0;a[i];++i)
        {
            if(!b[a[i]-'A'])
            {
                if(cn==n)
                {
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
                cn--;
            }
        }
        printf("%d\n",ans/2);
    }
    return 0;
}
