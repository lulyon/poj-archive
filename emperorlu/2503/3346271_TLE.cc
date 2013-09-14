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
	int n, i=0,j;
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
	
	int mid;
	while(scanf("%s",c)!=EOF)
	{
		i=0;
		j=n-1;
		mid = (i+j)/2;
		int flag;
		while(i!=j)
		{
			flag = strcmp(c,mp[mid].b);
			if(flag == 0)
			{
				printf("%s\n",mp[i].a);
				break;
			}
			else if(flag<0)
			{
				j=mid-1;
				mid = (i+j)/2;
			}
			else
			{
				i = mid+1;
				mid = (i+j)/2;
			}
		}
		if(i==j)
		{
			flag = strcmp(c,mp[mid].b);
			if(flag == 0)
				printf("%s\n",mp[mid].a);
			else
				printf("eh\n");
			continue;
		}
	}
	return 0;
}
