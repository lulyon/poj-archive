#include<stdio.h>
#include<string.h>
char a[100001],b[100001];
int main()
{
	int i,j,flag;
	while(scanf("%s%s",a,b)!=EOF)
	{
		i=j=0;
		flag=1;
		while(a[j])
		{
			while(a[j]!=b[i])
			{
				if(!b[i])
				{
					flag=0;
					goto leap;
				}
				i++;
			}
			i++;
			j++;
		}
		leap:
		if(flag&&strlen(a)!=strlen(b))printf("Yes\n");
			else printf("No\n");
	}
	return 0;
}
