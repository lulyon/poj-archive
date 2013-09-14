#include<iostream>
using namespace std;
int main()
{
    int t,n;
    int a[1001],b[1001],c[1001];
    cin>>t;
    while(t--)
    {
        memset(b,0,sizeof(b));
        cin>>n;
        int flag=0;
        cin>>a[0];
        for(int j=0;j<a[0];j++)
            b[flag++]=-1;
        b[flag++]=1;
        for(int i=1;i<n;i++)
        {
            cin>>a[i];
            int tmp=a[i]-a[i-1];
            for(int j=0;j<tmp;j++)
                b[flag++]=-1;
            b[flag++]=1;
        }
        //for(int i=0;i<flag;i++)
        //    printf("%d ",b[i]);
        //system("pause");
        for(int i=0;i<flag;i++)
        {
            if(b[i]==1)
            {
                int sum=1,num=1;
                for(int j=i-1;j>=0;j--)
                {
                    sum+=b[j];
                    if(sum>0)
                    {
                        if(b[j]==1)
                            num++;
                    }
                    else if(sum==0)
                    {
                        printf("%d ",num);
                        break;
                    }
                }
            }
        }
        printf("\n");
    }
    return 0;
}
