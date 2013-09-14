#include<stdio.h>
#include<stdlib.h>
struct In
{
	int p,num;
};
struct In data[101];
int cmp( const void *a ,const void *b) 
{ 
	return (*(In *)a).num > (*(In *)b).num ? 1 : -1; 
} 
int main()
{
	int m,n;
	char a[101][52];
	freopen("result.txt","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",a[i]);
		int cn=0;
		for(int j=0;j<m-1;j++)
		{
			for(int k=j+1;k<m;k++)
			{
				if(a[i][j]>a[i][k])cn++;
			}
		}
		data[i].num=cn;
		data[i].p=i;
	}
	qsort(data,n,sizeof(data[0]),cmp);
	for(int i=0;i<n;i++)
	{
		printf("%s\n",a[data[i].p]);
	}
	return 0;
}
