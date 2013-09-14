#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char a[100],b[100],c[100],d[100];
int count[26];
int main()
{
	memset(count,0,sizeof(count));
	gets(a);
	for(int i=0;a[i];i++)
	{
		if(a[i]>='A'&&a[i]<='Z')
			count[a[i]-'A']++;
	}
	gets(b);
	for(int i=0;b[i];i++)
	{
		if(b[i]>='A'&&b[i]<='Z')
			count[b[i]-'A']++;
	}
	gets(c);
	for(int i=0;c[i];i++)
	{
		if(c[i]>='A'&&c[i]<='Z')
			count[c[i]-'A']++;
	}
	gets(d);
	for(int i=0;d[i];i++)
	{
		if(d[i]>='A'&&d[i]<='Z')
			count[d[i]-'A']++;
	}
	int max=0;
	for(int i=0;i<26;i++)
	{
		if(max<count[i])max=count[i];
	}
	while(max)
	{
		for(int i=0;i<26;i++)
		{
			if(count[i]==max)
			{
				printf("*");
				count[i]--;
			}
			else printf(" ");
			printf(" ");
		}
		printf("\n");
		max--;
	}
	for(int i=0;i<26;i++)
		printf("%c ",i+'A');
	//system("pause");
	return 0;
}
