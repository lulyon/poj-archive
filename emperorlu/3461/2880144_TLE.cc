#include<stdio.h>
#include<stdlib.h>
char a[10000],b[1000000];
int main()
{
	int t;
	scanf("%d\n",&t);
	while(t--)
	{
		scanf("%s%s",a,b);
		int j,begin;
		int flag,cn=0;
		for(int i=0;b[i];i++)
		{
			if(a[0]==b[i])
			{
				begin=i;
				j=1;
				i++;
				flag=1;
				while(1)
				{
					if(!b[i])
					{
						flag=0;
						break;
					}
					if(b[i]!=a[j])
					{
						flag=0;
						break;
					}
					i++;
					j++;
					if(!a[j])
					{
						i=begin;
						break;
					}
				}
				if(flag)
				{
					cn++;
					//printf("i=%d",i);
					//system("pause");
				}
			}
		}
		printf("%d\n",cn);
	}
	//system("pause");
	return 0;
}
