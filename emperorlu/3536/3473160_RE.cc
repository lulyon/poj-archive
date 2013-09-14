#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int n;
	int cn=0,a,b,c;
	char str[10000];
	while(scanf("%s%d",str,&n)!=EOF)
	{
		int m = (int)pow(n,1/3.0);
		
		
		for(int i=1;i<=m;++i)
			if(n%i==0)a = i;
			
		n /= a;
		
		m = (int)sqrt(n);
		for(int i=1;i<=m;++i)
		{
			if(n%i==0)
			{
				b = i;
				c = n/i;
			}
		}
		printf("#%d %d %d %d\n",++cn,a,b,c);
	}
    return 0;
}
