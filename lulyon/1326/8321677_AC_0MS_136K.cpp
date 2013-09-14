#include<stdio.h>
#include<string.h>
int main()
{
	char s1[100],s2[100],s3[10];
	int sum,n;
	while(1)
	{   
		sum=0;
		while(1)
		{
			scanf("%s",s1);
			if(strcmp(s1,"#")==0)
				goto loop;
			if(strcmp(s1,"0")==0)
			             break;
			scanf("%s %d %s",s2,&n,s3);
			if(strcmp(s3,"Y")==0)
			{ 
				if(n<=500)
			     sum+=500;
				else
				  sum+=n;
			}
			else if(strcmp(s3,"B")==0)
			sum+=n+(n+1)/2;
			else if(strcmp(s3,"F")==0)
			sum+=2*n;
		}
		printf("%d\n",sum);
		sum=0;
	}
	loop:;
	 return 0;
}