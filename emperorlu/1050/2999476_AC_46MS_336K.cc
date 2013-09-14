#include<iostream>
using namespace std;

int a[101][101];
int MaxSum(int n,int *a)
{
	int sum=0;
	int b=0;
	for(int i=1;i<=n;i++)
	{
		if(b>0)b+=a[i];
		else
			b=a[i];
		if(b>sum)
			sum=b;
	}
	return sum;
}

int MaxSum2(int m,int n)
{
	int sum=0;
	int *b=new int [n+1];
	for(int i=1;i<=m;i++)
	{
		for(int k=1;k<=n;k++)
			b[k]=0;
		for(int j=i;j<=m;j++)
		{
			for(int k=1;k<=n;k++)
				b[k]+=a[j][k];
			int max=MaxSum(n,b);
			if(max>sum)sum=max;
		}
		
	}
        delete b;
	return sum;
}
int main()
{
	int N;
	
	int sum;
	cin>>N;
	int i,j;
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
		{
			cin>>a[i][j];
		}
	}
	sum=MaxSum2(N,N);
	cout<<sum<<endl;
	
	
	
	return 0;
}