#include<stdio.h>
#include<math.h>
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
		m=(int)(log(b)/log(2));
		for(int i=1;i<=m;i++)
			tmp1=tmp1*tmp1%c;
		while(1)
		{
			b-=(1<<m);
			if(b==0)break;
			m=(int)(log(b)/log(2));
			tmp2=a;
			for(int i=1;i<=m;i++)
				tmp2=tmp2*tmp2%c;
			tmp1=tmp1*tmp2%c;
			if(b==1)break;
		}
		sum=(sum+tmp1)%c;
	}
	printf("%d\n",sum);
	}
	//while(1);
	return 0;
}
