#include<iostream>
using namespace std;

const int MAXN = 100010;

long long a[MAXN],l[MAXN],r[MAXN];

int main()
{
	int n;
	while(1)
	{
		scanf("%d",&n);
		if(!n)break;
		
		for(int i=1;i<=n;++i)
			scanf("%I64d",a+i);
		
		l[1]=1;
		r[n]=n;
		for(int i=2;i<=n;++i)
		{
			if(a[i]<=a[i-1])
				l[i]=l[i-1];
			else
				l[i]=i;
		}
		for(int i=n-1;i>=1;--i)
		{
			if(a[i]<=a[i+1])
				r[i]=r[i+1];
			else
				r[i]=i;
		}
		
		long long  area,max=-INT_MAX;
		for(int i=1;i<=n;++i)
		{
			area = (r[i]-l[i]+1)*a[i];
			if(max<area)max=area;
		}
		
		printf("%I64d\n",max);
	}
    return 0;
}

