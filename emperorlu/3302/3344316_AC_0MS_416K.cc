#include<iostream>
#include<math.h>
using namespace std;
char a[200],b[200];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		scanf("%s%s",a,b);
		int i,j;
		for(i=0,j=0;a[i] && b[j];)
		{
			if(a[i]==b[j])
			{
				i++;
				j++;
			}
			else
				i++;
		}
		if(b[j])
		{
			i=0,j=strlen(b)-1;
			for(;a[i] && j>=0;)
			{
				if(a[i]==b[j])
				{
					i++;
					j--;
				}
				else
					i++;
			}
			if(j<0)printf("YES\n");
			else
				printf("NO\n");
		}
		else
			printf("YES\n");
	}
    return 0;
}
