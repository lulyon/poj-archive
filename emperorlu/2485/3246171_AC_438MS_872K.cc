#include<iostream>
using namespace std;
int a[550][550],visited[550],stack[550];
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
                scanf("%d",&a[i][j]);
            visited[i]=0;
        }
        
        int min = INT_MAX,tmp;
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                if(i!=j && min>a[i][j])
                {
                    min = a[i][j];
                    stack[0]=i;
                    stack[1]=j;
                }
        int top=2,result=min;
        visited[stack[0]]=1;
        visited[stack[1]]=1;
        
        while(1)
        {
            int min = INT_MAX;
            for(int i=0;i<top;++i)
                for(int j=0;j<n;++j)
                    if(stack[i]!=j && !visited[j] && min>a[stack[i]][j])
                    {
                        min = a[stack[i]][j];
                        tmp = j;
                    }
            if(min!=INT_MAX)
            {
                visited[tmp]=1;
                stack[top++]=tmp;
                if(result<min) result = min;
            }
            
            if(top==n)break;
        }
        cout<<result<<endl;
    }
    return 0;
}
