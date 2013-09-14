#include<iostream>
using namespace std;
char a[2][250];
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
            
            //cout<<k<<endl;
            //getchar();
            getchar();
            gets(&a[0][1]);
            //scanf("%s",&a[0][1]);
            for(int i=strlen(&a[0][1])+1;i<=n;++i)
            {
                a[0][i]=' ';
            }
            
            a[0][n+1]=a[1][n+1]=0;
            
            //cout<<&a[0][1]<<endl;
            
            
            int tmp;
            for(int i=1;i<=k;++i)
            {
                tmp=i%2;
                for(int j=1;j<=n;++j)
                {
                    a[tmp][hash[j]]=a[!tmp][j];
                }
                
            }
            
            //cout<<"hello"<<endl;
            printf("%s\n",&a[tmp][1]);
        }
    }
    return 0;
}
