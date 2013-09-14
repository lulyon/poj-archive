#include<stdio.h>
#include<math.h>
int a[101];
int main()
{
	int n;
	scanf("%d%d",&n,a);
	double tmp,max=0;
	for(int i=1;i<n;i++)
	{
		scanf("%d",a+i);
		tmp=a[i]*a[i-1];
		if(max<tmp)max=tmp;
	}
	tmp=a[0]*a[n-1];
	if(max<tmp)max=tmp;
	max=2*sqrt(max);
	printf("%.3lf\n",max);
	//while(1);
	return 0;
}
