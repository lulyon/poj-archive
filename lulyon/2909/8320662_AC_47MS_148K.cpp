#include<stdio.h>
#include<math.h>

int prime(int n)
{
	int i;
	int m = (int)sqrt(n+0.0);
	for(i=3;i<=m;i+=2)
		if(n%i==0)return 0;
	return 1;	 
}


int gen(int n)
{
	int i,count=0;
	int m=n/2;
	for(i=3;i<=m;i+=2)
		if(prime(i)&&prime(n-i))
			count++;
	return count;
}


int main()
{
	int n;
	while(scanf("%d",&n)&&n!=0)
		printf("%d\n",gen(n));
	return 0;
}

