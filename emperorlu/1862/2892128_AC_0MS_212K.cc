#include <stdio.h>
#include <math.h>
#include<stdlib.h>
double a[101];
int cmp(const void *a,const void *b)
{
	return *(double *)a>*(double *)b?1:-1;
}
int main()
{
	int num,i,j;
	scanf("%d",&num);
	for(i=0;i<num;i++)
		scanf("%lf",a+i);
	if(num==1)printf("%.3lf\n",a[0]);
	else
	{
		qsort(a,num,sizeof(a[0]),cmp);
		for(i=num-2;i>=0;i--)
			a[i]=2*sqrt(a[i]*a[i+1]);
		printf("%.3lf\n",a[0]);
	}
	///while(1);
	return 0;
}
