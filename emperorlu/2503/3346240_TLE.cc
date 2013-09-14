#include<iostream>
using namespace std;
typedef struct
{
	char a[15],b[15];
}node;
node mp[100010];
char c[15];
bool cmp(const node &m,const node &n)
{
	return strcmp(m.b,n.b)<0;
}
int main()
{
	char test;
	int n, i=0;
	while(1)
	{
		test = getchar();
		if(test == '\n')break;
		mp[i].a[0]=test;
		scanf("%s %s",&mp[i].a[1],&mp[i].b[0]);
		getchar();
		++i;
	}
	n=i;
	sort(mp,mp+n,cmp);
//	for(i=0;i<n;++i)
//		cout<<mp[i].b<<endl;
//	system("pause");
	
	while(scanf("%s",c)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			if(strcmp(c,mp[i].b)==0)
			{
				printf("%s\n",mp[i].a);
				break;
			}
		}
		if(i==n)
			printf("eh\n");
	}
	return 0;
}
