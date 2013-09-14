#include<iostream>
using namespace std;
int main()
{
	int n,m,a,b,t;
	cin>>t;
	while(t--)
	{
		scanf("%d%d",&m,&n);
		
		int sum=0,ans;
		while(n--)
		{
			scanf("%d%d",&a,&b);
			
			a%=m;
			ans=1;
			
			while(b)
			{
				if(b&1)ans=(ans*a)%m;
				a=(a*a)%m;
				b>>=1;
			}
			sum=(sum+ans)%m;
		}
		printf("%d\n",sum);
	}
    return 0;
}

