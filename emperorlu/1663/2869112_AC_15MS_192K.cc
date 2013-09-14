#include<stdio.h>
int main()
{
	int t,x,y;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&x,&y);
		if(x==y+2||x==y)printf("%d\n",x+y-x%2);
		else printf("No Number\n");
	}
	return 0;
}