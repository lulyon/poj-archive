#include<iostream>
using namespace std;

char str[110];

bool judge(char cc)
{
	if((cc>='A'&&cc<='Z')||(cc>='a'&&cc<='z')||cc=='_')return 0;
	else return 1;
	 
}

int main()
{
	freopen("a.txt","w",stdout);
	
	gets(str);
	
	int len=strlen(str);
	
	bool flag=0;
	
	for(int i=0;i<len;++i)
	{
		if(judge(str[i]))
		{
			printf("Error!\n");
			return 0;
		}
		
		if(str[i]=='_')flag=1;
	}
	
	if(flag)
	{
		if(!(str[0]>='a'&&str[0]<='z'))
		{
			printf("Error!\n");
			return 0;
		}
		
		for(int i=1;i<len;++i)
		{
			if(str[i]>='A'&&str[i]<='Z')
			{
				printf("Error!\n");
				return 0;
			}
		}
		if(str[len-1]=='_')
		{
			printf("Error!\n");
			return 0;
		}
		
		for(int i=0;i<len;++i)
		{
			if(str[i]=='_')
			{
				if(str[i+1]=='_')
				{
					printf("Error!\n");
					return 0;	
				}
				str[i+1]-=32;
			}
			else printf("%c",str[i]);
		}
		printf("\n");
	}
	else
	{
		if(!(str[0]>='a'&&str[0]<='z'))
		{
			printf("Error!\n");
			return 0;
		}
		for(int i=0;i<len;++i)
		{
			if(str[i]>='a'&&str[i]<='z')
				printf("%c",str[i]);
			else
				printf("_%c",str[i]+32);
		}
		printf("\n");
	}
	
    return 0;
}

