#include<iostream>
using namespace std;
int a[510][510];
bool b[510];
int minedge[510];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
			{
				scanf("%d",&a[i][j]);
			}
		int iindex,jindex,min;
		min = INT_MAX;
		
		for(int i=0;i<n;++i)
		{
			b[i]=0;
			for(int j=i+1;j<n;++j)
			{
				if(min < a[i][j])
				{
					min = a[i][j];
					iindex = i;
					jindex = j;
				}
			}
		}
		
		int max = min;
		b[iindex]=b[jindex]=1;
		for(int i=0;i<n;++i)
		{
			if(!b[i])
			{
				if(a[i][iindex]<a[i][jindex])
					minedge[i]=a[i][iindex];
				else
					minedge[i]=a[i][jindex];
			}
		}
		
		int index;
		for(int iter=2;iter<n;++iter)
		{
			min=INT_MAX;
			for(int i=0;i<n;++i)
			{
				if(!b[i])
				{
					if(min>minedge[i])
					{
						min = minedge[i];
						index = i;
					}
				}
			}
			
			b[index]=1;
			if(max<min)max=min;
			
			for(int i=0;i<n;++i)
			{
				if(!b[i])
				{
					if(minedge[i]>a[i][index])
						minedge[i]=a[i][index];
				}
			}
		}
		printf("%d\n",max);
	}
	return 0;
}
