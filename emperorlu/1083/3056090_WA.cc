#include<iostream>
using namespace std;
int a[1000][2];
int stack[1000][2];
bool b[250];
int cmp(const void *a,const void *b)
{
    if(*(int *)a!=*(int *)b)
        return *(int *)a-*(int *)b;
    else
        return *((int *)a+1)-*((int *)b+1);
}
int main()
{
    int t,n,tmp;
    cin>>t;
    while(t--)
    {
        cin>>n;
        memset(b,0,sizeof(b));
        for(int i=0;i<n;i++)
        {
            cin>>a[i][0]>>a[i][1];
            if(a[i][0]>a[i][1])
            {
                tmp=a[i][0];
                a[i][0]=a[i][1];
                a[i][1]=tmp;
            }
        }
        qsort(a,n,2*sizeof(int),cmp);
        
        int cn=0;
        while(1)
        {
            b[0]=1;
            for(int i=1;i<n;i++)
            {
                int mark=0;
                for(int j=0;j<i;j++)
                {
                    if(b[j])
                    {
                        if(a[j][1]%2)
                        {
                            if(a[j][1]+1>=a[i][0])
                            {
                                mark=1;
                                break;
                            }
                        }
                        else
                        {
                            if(a[j][1]>=a[i][0])
                            {
                                mark=1;
                                break;
                            }
                        }
                    }
                }
                if(mark==0)b[i]=1;
            }
            /*
            for(int i=0;i<n;i++)
                cout<<b[i]<<endl;
            system("pause");
            */
            cn++;
            int flag=0;
            for(int i=0;i<n;i++)
            {
                if(b[i]==0)
                {
                    stack[flag][0]=a[i][0];
                    stack[flag][1]=a[i][1];
                    flag++;
                }
            }
            n=flag;
            if(n==0)break;
            for(int i=0;i<n;i++)
            {
                a[i][0]=stack[i][0];
                a[i][1]=stack[i][1];
            }
        }
        cout<<10*cn<<endl;
    }
}
