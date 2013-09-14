#include<iostream>
using namespace std;
int a[500];
bool b[100000];
int main()
{
    int i,j,n,t;
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);       

        for(i=0;i<n;++i)
        {
            scanf("%d",a+i);
        }
        if(n==1)
        {
            printf("1\n");
            continue;
        }
        int tmp;
        for(i=n;;++i)
        {
            memset(b,0,i*sizeof(bool));
            for(j=0;j<n;++j)
            {
                tmp = a[j]%i;
                if(b[tmp])break;
                else b[tmp]=1;
            }
            if(j==n)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
