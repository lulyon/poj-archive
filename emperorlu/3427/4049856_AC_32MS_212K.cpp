#include<iostream>
using namespace std;

const int maxn = 30010;

int a[maxn];

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	
	for(int i=0;i<n;++i)
		scanf("%d",a+i);
		
	int sum,min=0,index=0;
	
	for(int j=0;j<n;++j)
			min += (a[j])%m;
	
	for(int i=1;i<m;++i)
	{
		sum=0;
		for(int j=0;j<n;++j)
			sum += (++a[j])%m;
		
		if(min>sum)
		{
			min=sum;
			index=i;
		}
	}
	
	printf("%d\n",index);
	
    return 0;
}
