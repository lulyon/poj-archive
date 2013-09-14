#include<stdio.h>
#include<math.h>
int a[101];
int main()
{
	int n;
	double max;
	scanf("%d",&n);
	if(n==1)
	{
		scanf("%d",a);
		printf("%.3lf\n",(double)a[0]);
		return 0;
	}
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	int s,tmp;
	for(int i=0;i<2;i++)
	{
		for(int j=i;j<n;j++)
		{
			s=j;	
			for(int k=j+1;k<n;k++)
				if(a[s]<a[k])s=k;
			tmp=a[j];
			a[j]=a[s];
			a[s]=tmp;
		}
	}
	max=2*sqrt(a[0]*a[1]);
	printf("%.3lf\n",max);
	//while(1);
	return 0;
}
