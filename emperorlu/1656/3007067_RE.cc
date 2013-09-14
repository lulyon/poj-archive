#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char a[10];
bool check[1000][1000];
int main()
{
	int t,x,y,l;
	scanf("%d\n",&t);
	memset(check,0,sizeof(check));
	while(t--)
	{
		scanf("%s %d %d %d\n",a,&x,&y,&l);
		if(strcmp(a,"BLACK")==0)
		{
			for(int i=x;i<x+l;i++)
				for(int j=y;i<y+l;j++)
					check[i][j]=1;	
		}
		else if(strcmp(a,"WHLIE")==0)
		{
			for(int i=x;i<x+l;i++)
				for(int j=y;i<y+l;j++)
					check[i][j]=1;
		}
		else 
		{
			int cn=0;
			for(int i=x;i<x+l;i++)
				for(int j=y;i<y+l;j++)
					if(check[i][j])cn++;
			printf("%d\n",cn);
			memset(check,0,sizeof(check));
		}
	}
	return 0;
}
