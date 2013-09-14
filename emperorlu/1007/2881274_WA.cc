#include<stdio.h>
#include<stdlib.h>
char a[100][50];
int b[100],c[100];
int main()
{
	//freopen("me.txt","w",stdout);
	int n,m,i,j,k,cn;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%s",a[i]);
		cn=0;
		for(j=1;j<n;j++)
			for(k=0;k<j;k++)
				if(a[i][k]>a[i][j])cn++;
		b[i]=cn;
		c[i]=i;
	}
	int s,tmp;
	for(i=0;i<m;i++)
	{
		s=i;
		for(j=i+1;j<m;j++)
			if(b[j]<b[s])s=j;
		tmp=b[i];b[i]=b[s];b[s]=tmp;
		tmp=c[i];c[i]=c[s];c[s]=tmp;
	}
	for(i=0;i<m;i++)
		printf("%s\n",a[c[i]]);
	//system("pause");
	return 0;
}
