#include<iostream>
using namespace std;
char a[10010][15];
int hash[10010];
bool comp(const int aa,const int bb)
{
	return strcmp(a[bb],a[aa])>0;
}
bool prefix(int i,int j)
{
	for(int k=0;a[i][k];++k)
	{
		if(a[i][k]!=a[j][k])return 0;
	}
	return 1;
}
int main()
{
	int t,n,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;++i)
		{
			scanf("%s",a[i]);
			hash[i]=i;
		}
		sort(hash,hash+n,comp);
		for(i=0;i<n;++i)
		{
			for(j=i;j<n;++j)
			{
				if(prefix(hash[i],hash[j]))
				{
					printf("NO\n");
					goto leap;
				}
			}
		}
		printf("YES\n");
		leap:;
		
	}
	
	return 0;
}
