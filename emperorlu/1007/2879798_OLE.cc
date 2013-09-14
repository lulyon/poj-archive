#include<stdio.h>
#include<stdlib.h>
char a[100][50];
struct bat
{
	int a,b;
}bb[100];
int cmp(const void *a,const void *b) 
{ 
	return (*(bat *)a).b > (*(bat *)b).b? 1 : -1; 
} 
int main()
{
	int n,m,tmp;
	//freopen("me.txt","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%s",a[i]);
		int cn=0;
		for(int j=1;j<n;j++)
			for(int k=0;k<j;k++)
				if(a[i][k]>a[i][j])cn++;
		bb[i].b=cn;
		bb[i].a=i;
	}
	qsort(bb,m,sizeof(bb[0]),cmp);
	for(int i=0;i<m;i++)
		printf("%s\n",a[bb[i].a]);
	//system("pause");
	return 0;
}
