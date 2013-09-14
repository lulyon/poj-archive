#include<iostream>
using namespace std;
char a[250];
char b[250];
int hash[250];
int main()
{
    int n,k;
    while(1)
    {
        scanf("%d",&n);
        if(!n)break;
        
        for(int i=1;i<=n;++i)
        {
            scanf("%d",hash+i);
        }
        
        while(1)
        {
            scanf("%d",&k);
            if(!k)break;
            
            getchar();
            gets(&a[1]);
            for(int i=strlen(&a[1])+1;i<=n;++i)
            {
                a[i]=' ';
            }
            
            a[n+1]=0;
            
            bool tmp;
            
            if(k%2)
            {
                for(int j=1;j<=n;++j)
                {
                    b[hash[j]]=a[j];
                }
                b[n+1]=0;
                printf("%s\n",&b[1]);
            }
            else
            {
                printf("%s\n",&a[1]);
            }
        }
    }
    return 0;
}
