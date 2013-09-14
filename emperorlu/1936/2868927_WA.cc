#include<stdio.h>
#include<string.h>
char a[100001],b[100001];
int main()
{
	int i,j,flag,tag;
	while(scanf("%s%s",a,b)!=EOF)
	{
		i=j=0;
		tag=1;
		while(a[j])
		{
			while(a[j]!=b[i])
			{
				if(!b[i])
				{
					tag=0;
					goto leap;
				}
				i++;
			}
			j++;
		}
		leap:
		if(tag&&strcmp(a,b))printf("Yes\n");
			else printf("No\n");
	}
	return 0;
}
