#include <iostream>
using namespace std;
int cmp(const void *a, const void *b)
{
    return(*(long *)b-*(long *)a);
}
int main()
{	int i,n,j;	
	long a[20010];
	__int64 sum=0,t=0;
	while(scanf("%d",&n)!=EOF)
	{
		sum=0;t=0;
		for(i=0;i<n;i++)
		{
			scanf("%ld",&a[i]);
			t=t+a[i];
		}
		if(n==1)
		{
			printf("0\n");
			continue;
		}
		qsort(a,n,sizeof(a[0]),cmp);
		sum=sum+t;
		for(j=0;j<n-2;j++)
		{
			t=t-a[j];
			sum=sum+t;
		}
		printf("%I64d\n",sum);
	}
	return 0;
}
