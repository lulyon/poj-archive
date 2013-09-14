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
		int j;
		for(int i=2;i<=n;++i)
		{
			j=i;
			if(a[i]>a[j-1])
				l[i]=i;
			else
			{
				while(j>1&&a[i]<=a[l[j-1]])
					j=l[j-1];
				l[i]=j;
			}
		}
		for(int i=n-1;i>=1;--i)
		{
			j=i;
			if(a[i]>a[j+1])
				r[i]=i;
			else
			{
				while(j<n&&a[i]<=a[r[j+1]])
					j=r[j+1];
				r[i]=j;
			}
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

