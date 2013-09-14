#include<stdio.h>
void swap(int &m,int &n)
{
	int tmp;
	tmp=m;
	m=n;
	n=tmp;
}
int main()
{
	int i,m,n,tmp,cn,max;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		printf("%d %d ",m,n);
		if(m>n)swap(m,n);
		max=0;
		for(i=m;i<=n;i++)
		{
			tmp=i;
			cn=1;
			while(tmp!=1)
			{
				if(tmp%2)tmp=3*tmp+1;
				else tmp/=2;
				cn++;
			}
			if(max<cn)max=cn;
		}
		printf("%d\n",max);
	}
	return 0;
}
