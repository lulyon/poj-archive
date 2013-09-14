#include<iostream>
using namespace std;
char a[100010][50],b[100010][50],c[50];

int main()
{
	char test;
	int n, i=0;
	while(1)
	{
		test = getchar();
		if(test == '\n')break;
		a[i][0]=test;
		scanf("%s %s",&a[i][1],b[i]);
		getchar();
		++i;
	}
	n=i;
	while(scanf("%s",c)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			if(strcmp(c,b[i])==0)
			{
				printf("%s\n",a[i]);
				break;
			}
		}
		if(i==n)
			printf("eh\n");
	}
	return 0;
}
