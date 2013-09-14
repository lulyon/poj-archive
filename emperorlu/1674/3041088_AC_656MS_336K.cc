#include<iostream>
using namespace std;
int a[10010];
int main()
{
    int t,n,tmp;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        int cn=0;
        for(int i=0;i<n-1;i++)
        {
            int min=a[i],s=i;
            for(int j=i+1;j<n;j++)
            {
                if(min>a[j])
                {
                    min=a[j];
                    s=j;
                }
            }
            if(s!=i)
            {
                tmp=a[i];
                a[i]=a[s];
                a[s]=tmp;
                cn++;
            }
        }
        printf("%d\n",cn);
    }
    return 0;
}
