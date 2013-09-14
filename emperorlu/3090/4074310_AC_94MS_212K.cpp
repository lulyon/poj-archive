#include <iostream>
using namespace std;
int res1[1001],res2[1001];
int gcd(int a,int b)
{ 
	int igcd;
	if(b == 0)
	   igcd = a; 
	else 
	  igcd = gcd(b,a%b); 
	  return igcd;
}
int main(void)
{
	res1[1] = 3;
	res2[1] = 1;
	int i,j;
	int ans,n,cas,cnt = 1;
	for(i=2;i<=1000;i++)
	{
		for(j=1;j<i;j++)
			if(gcd(i,j) == 1)
			{
				res2[i]++;
			}
	}
	for(i=2;i<=1000;i++)
	{
		res1[i] = res1[i-1] + 2*res2[i];
	}
	scanf("%d",&n);
	while(n--)
	{
		ans = 1;
		scanf("%d",&cas);
	    printf("%d %d ",cnt++,cas);
		printf("%d\n",res1[cas]); 
	}
	return 0;
}
