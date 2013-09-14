#include<iostream>
using namespace std;
bool b[15][1000000];

int a[15];

void init()
{
	a[0]=1;
	for(int i=1;i<=12;++i)
		a[i]=a[i-1]*3;
	
	b[0][1]=1;
	for(int i=1;i<=12;++i)
	{
		for(int j=1;j<=a[i-1];++j)
		{
			b[i][j]=b[i-1][j];
			b[i][j+a[i-1]]=0;
			b[i][j+a[i-1]+a[i-1]]=b[i-1][j];
		}
	}
		
}

int main()
{
	init();
	
	int m,n;
	while(scanf("%d",&n)!=EOF)
	{
		m = a[n];
		for(int i=1;i<=m;++i)
			if(b[n][i])printf("-");
			else
				printf(" ");
		cout<<endl;
	}
    return 0;
}
