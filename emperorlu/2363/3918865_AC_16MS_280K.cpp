#include<iostream>
using namespace std;
int main()
{
    int i,j,k,t,n,s,tmp;
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        s = INT_MAX;
        i=j=k=1;
        for(i=1;;++i)
        {
            for(j=i;;++j)
            {
                if(i*j>n)break;
                if(n%(i*j)==0)
                {
                    k=n/(i*j);
                    tmp = i*j+j*k+i*k;
                    if(s>tmp)s=tmp;
                }
                
            }
            if(i*i>n)break;
        }
        printf("%d\n",s+s);
    }
    return 0;
}
