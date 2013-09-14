#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n&&n)
	{
		while(1)
		{
			int sh[1010],m=0;
			sh[m++]=0;
			int ch[1010];
			int yes[1010];
			memset(yes,1,sizeof(yes));
			int i=0;
			for(i=0;i<n;i++)
			{
				cin>>ch[i];
				if(ch[i]==0)break;
			}
			if(i==0)
			{
				printf("\n");
				break;
			}
			int no=0;
			for(i=0;i<n;i++)
			{	
				yes[ch[i]]=0;
				for(int j=sh[m-1]+1;j<ch[i];j++)
					if(yes[j])sh[m++]=j;
				if(ch[i]==sh[m-1])m--;
				else if(ch[i]<sh[m-1])no=1;
				if(no)break;
			}
			if(no)printf("No\n");
			else printf("Yes\n");
		}
	}
	return 0;
}