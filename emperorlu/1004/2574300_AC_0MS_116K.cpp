#include "stdio.h"
int main()
{ 
	int i;
	float temp,sum,aver;
	for(i=1,sum=0;i<=12;i++)
	{
		scanf("%f",&temp);
		sum+=temp;
	}
	aver=sum/12;
	printf("$%.2f\n",aver);
	return 0;
}