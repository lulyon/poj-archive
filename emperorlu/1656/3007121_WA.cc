#include<stdio.h>
#include<string.h>
#include<memory.h>
#include<stdlib.h>
char a[10];
bool check[1000][1000];
int main()
{
	int t,x,y,l;
	scanf("%d",&t);
	memset(check,0,sizeof(check));
	while(t--)
	{
		scanf("%s%d%d%d",a,&x,&y,&l);
		if(strcmp(a,"BLACK")==0)
		{
			for(int i=x;i<x+l;i++)
				for(int j=y;j<y+l;j++)
					check[i][j]=1;
			
		}
		else if(strcmp(a,"WHLIE")==0)
		{
			for(int i=x;i<x+l;i++)
				for(int j=y;j<y+l;j++)
					check[i][j]=0;
		}
		else if(strcmp(a,"TEST")==0) 
		{
			int cn=0;
			for(int i=x;i<x+l;i++)
				for(int j=y;j<y+l;j++)
                    if(check[i][j])
                        cn++;
			printf("%d\n",cn);
		}
	}
	return 0;
}
