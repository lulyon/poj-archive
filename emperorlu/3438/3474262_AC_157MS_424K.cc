#include<iostream>
#include<math.h>
using namespace std;
char str[1010];
int num[20];

int main()
{
	int i,t;
	cin>>t;
	while(t--)
	{
		scanf("%s",str);
		
		for(i=0;str[i];++i)
		{
			if(i==0)
				num[str[i]-'0']=1;
			else
				if(str[i]==str[i-1])
					num[str[i]-'0']++;
				else
				{
					printf("%d%c",num[str[i-1]-'0'],str[i-1]);
					num[str[i]-'0']=1;
				}
		}
		printf("%d%c\n",num[str[i-1]-'0'],str[i-1]);
		
	}
    return 0;
}
