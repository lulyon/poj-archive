#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	int c,n,a,b;
	scanf("%d%d",&c,&n);
	int sum=0;
	int tmp1,tmp2,m,a1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		a%=c;
		tmp1=a;
		int cn=0;
		m=b%2;
		if(m)tmp1;
		else tmp1=1;
		while(b)
		{
			cn++;
			b/=2;
			m=b%2;
			tmp2=a;
			if(m)
			{
				for(int i=1;i<=cn;i++)
					tmp2=tmp2*tmp2%c;
			}
			else tmp2=1;
			tmp1=tmp1*tmp2%c;
		}
		sum=(sum+tmp1)%c;
	}
	printf("%d\n",sum);
	}
	//while(1);
	return 0;
}
