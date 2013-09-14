#include<iostream>
#include<math.h>
using namespace std;
__int64 a[10000];
int main()
{
	__int64 i,j;
	__int64 k=1;
	a[0]=0;
	for(i=1;;i*=2)
	{
		if(i>2000000000)break;
		else a[k++]=i;
	}
	__int64 tmp;
	__int64 kk=k;
	for(i=1;i<k;++i)
	{
		for(j=3;;j*=3)
		{
			tmp = j*a[i];
			if(tmp>2000000000)break;
			else a[kk++]=tmp;
		}
	}
	__int64 kkk=kk;
	for(i=1;i<kk;++i)
	{
		for(j=5;;j*=5)
		{
			tmp = j*a[i];
			if(tmp>2000000000)break;
			else a[kkk++]=tmp;
		}
	}
	__int64 kkkk=kkk;
	for(i=1;i<kkk;++i)
	{
		for(j=7;;j*=7)
		{
			tmp = j*a[i];
			if(tmp>2000000000)break;
			else a[kkkk++]=tmp;
		}
	}
	sort(a,a+kkkk);
	int n,m;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)break;
		m=n%100;
		if(m/10!=1 && m%10==1)
			printf("The %dst humble number is ",n);
		else if(m/10!=1 && m%10==2)
			printf("The %dnd humble number is ",n);
		else if(m/10!=1 && m%10==3)
			printf("The %drd humble number is ",n);
		else
			printf("The %dth humble number is ",n);
		printf("%d.\n",a[n]);
	}
    return 0;
}
