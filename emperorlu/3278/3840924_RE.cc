#include<iostream>
#include<math.h>
using namespace std;
bool b[100010];
int stack[100000000];
int pan[100000000];
int main()
{
    int n,k;
    cin>>n>>k;
    if(n>=k)cout<<n-k<<endl;
    else
    {
        int cn=0,top=0,m=1;
        stack[0]=n;
        b[n]=1;
        while(1)
        {
            cn++;
            for(int i=0;i<m;++i)
            {
                if(stack[i]>0&&!b[stack[i]-1])
                {
                    b[stack[i]-1]=1;
                    pan[top++]=stack[i]-1;    
                    if(pan[top-1]==k)
                    {
                        
                        cout<<cn<<endl;
                         //system("pause");
                        
                        return 0;
                    }
                }
                if(stack[i]<k && !b[stack[i]+1])
                {
                    b[stack[i]+1]=1;
                    pan[top++]=stack[i]+1;
                    if(pan[top-1]==k)
                    {
                        cout<<cn<<endl;
                         //system("pause");
                        return 0;
                    }
                }
                if(stack[i]<k&&!b[2*stack[i]])
                {
                    b[2*stack[i]]=1;
                    pan[top++] = 2*stack[i];
                    
                    if(pan[top-1]==k)
                    {
                        cout<<cn<<endl;
                         //system("pause");    
                        return 0;
                    }
                }
            }
            sort(pan,pan+top);
            for(int i=0;i<top;++i)
                stack[i] = pan[i];
            m = top;
            top = 0;
        }
    }
    
    return 0;
} 
