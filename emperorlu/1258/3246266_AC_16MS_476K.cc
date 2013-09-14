#include<iostream>
using namespace std;
int n,a[110][110];
int stack[110],visited[110];
int main()
{
    while(cin>>n)
    {
        int sum=0;
        int min = INT_MAX,top=0;
        
        
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                scanf("%d",&a[i][j]);
                if(i!=j&&a[i][j]<min)
                {
                    min = a[i][j];
                    stack[0]=i;
                    stack[1]=j;
                }
            }
            visited[i]=0;
        }
        sum += min;
        top=2;
        visited[stack[0]]=1;
        visited[stack[1]]=1;
        while(1)
        {
            int min = INT_MAX,tmp;
            for(int i=0;i<top;++i)
                for(int j=0;j<n;++j)
                    if( stack[i]!=j && !visited[j] && a[stack[i]][j]<min)
                    {
                        min = a[stack[i]][j];
                        tmp = j;
                    }
            if(min!=INT_MAX)
            {
                visited[tmp]=1;
                stack[top++]=tmp;
                sum += min;
                if(top==n)break;
            }
        }
        cout<<sum<<endl;        
    }
    return 0;
}
