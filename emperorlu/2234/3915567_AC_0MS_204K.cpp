#include<iostream>
using namespace std;
int main()
{
	int n,tmp,a;
	while(scanf("%d",&n)!=EOF)
	{
		scanf("%d",&tmp);
		if(n==1)
		{
			printf("Yes\n");
			continue;
		}
		
		while(--n)
		{
			scanf("%d",&a);
			tmp ^= a;
		}
		if(tmp)
			printf("Yes\n");
		else
			printf("No\n");
	}
    return 0;
}
