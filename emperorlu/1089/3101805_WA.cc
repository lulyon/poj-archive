#include<iostream>
using namespace std;
int stack[100000];
typedef struct In
{
	long long num;
	bool d;
}node;
node itv[100001];
int cmp(const void *a,const void *b)
{
	node *c = (node *)a; 
	node *d = (node *)b;
	if(c->num != d->num)
		return c->num < d->num;
	else
		return c->d < d->d;
}
int main()
{
	long n;
	scanf("%ld",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld%lld",&itv[2*i].num,&itv[2*i+1].num);
		itv[2*i].d = 0;
		itv[2*i+1].d = 1;
	}
	qsort(itv,2*n,sizeof(itv[0]),cmp);
	int cn=1,flag=0;
	stack[flag++]=itv[2*n-1].num;
	for(int i=2*n-2;i>=0;i--)
	{
		if(itv[i].d==0)
			cn++;
		else
			cn--;
		if(cn==0)
		{
			stack[flag++]=itv[i].num;
			if(i!=0)
				stack[flag++]=itv[i-1].num;
		}
	}
	for(int i=0;2*i<flag;i++)
		printf("%lld %lld\n",stack[2*i],stack[2*i+1]);
	//system("pause");
	return 0;
}
