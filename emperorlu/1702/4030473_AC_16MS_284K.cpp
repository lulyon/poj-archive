#include<iostream>
using namespace std;

long long l[100],r[100];

int main()
{
	int t;
	long long n;
	cin>>t;
	while(t--)
	{
		scanf("%I64d",&n);
		int t1,t2;
		t1 = t2 = 0;
		long long exp=1;
		while(n)
		{
			if(n%3==1)
			{
				r[t2++]=exp;
				--n;
			}
			else if(n%3==2)
			{
				l[t1++]=exp;
				++n;
			}
			n/=3;
			exp*=3;
		}
		if(t1==0)
			printf("empty ");
		else
		{
			printf("%I64d",l[0]);
			for(int i=1;i<t1;++i)
				printf(",%I64d",l[i]);
			printf(" ");
		}
		
		if(t2==0)
			printf("empty\n");
		else
		{
			printf("%I64d",r[0]);
			for(int i=1;i<t2;++i)
				printf(",%I64d",r[i]);
			printf("\n");
		}
	}
    return 0;
}
