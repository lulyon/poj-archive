#include<iostream>
#include<math.h>
using namespace std;
int a[100010],Left[100010],Right[100010];
int main()
{
	int n,sum,max,tmp;
	while(1)
	{
		scanf("%d",&n);
		if(!n)break;
		for(int i=0;i<n;++i)
			scanf("%d",a+i);
		sum=0;
		max=-10000000;
		for(int i=0;i<n;++i)
		{
			if(sum>=0)sum+=a[i];
			else sum=a[i];
			if(max<sum)max=sum;
			Left[i]=max;
		}
		sum=0;
		max=-10000000;
		for(int i=n-1;i>=0;--i)
		{
			if(sum>=0)sum+=a[i];
			else sum=a[i];
			if(max<sum)max=sum;
			Right[i]=max;
		}
		
		/*
		for(int i=0;i<n;++i)
			printf("%d ",Left[i]);
		cout<<endl;
		
		for(int i=0;i<n;++i)
			printf("%d ",Right[i]);
		cout<<endl;
		
		system("pause");
		max=-10000000;
		*/
		for(int i=0;i<n-1;++i)
		{
			tmp=Left[i]+Right[i+1];
			if(max<tmp)max=tmp;
		}
		printf("%d\n",max);
	}
    return 0;
}
