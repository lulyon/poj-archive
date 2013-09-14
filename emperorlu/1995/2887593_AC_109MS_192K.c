#include<stdio.h>
int main()
{
	int sum,t,cn,tmp1,tmp2,s,c,n,a,b,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&c,&n);
		sum=0;
		while(n--)
		{
			scanf("%d%d",&a,&b);
			a%=c;
			cn=0;
			if(b%2)tmp1=a;
			else tmp1=1;
			tmp2=a;
			s=1;
			while(b)
			{
				cn++;
				b>>=1;
				if(b%2)
				{
					for(i=s;i<=cn;i++)
					{
						tmp2*=tmp2;
						tmp2%=c;
					}
					s=cn+1;
					tmp1*=tmp2;
					tmp1%=c;
				}
			}
			sum+=tmp1;
			sum%=c;
		}
		printf("%d\n",sum);
	}
	return 0;
}
