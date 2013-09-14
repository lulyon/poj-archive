#include<iostream>
#include<algorithm>
using namespace std;
int a[1100];

int main()
{
	int n,k,t;
	cin>>t;
	
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;++i)
			scanf("%d",a+i);	
		
		while(k--)
		{
			next_permutation(a,a+n);
		}
		printf("%d",a[0]);
		for(int i=1;i<n;++i)
			printf(" %d",a[i]);
		cout<<endl;
		
	}
    return 0;
}

