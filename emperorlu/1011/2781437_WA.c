#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *num,i,sum,n,max,a;
	while(scanf("%d",&n),n!=0)
    {
		sum=0;
        max=0;
		num=(int*)malloc((n+1)*sizeof(int));
		for(i=1;i<=n;i++)
        {
			scanf("%d",num+i);
			if(num[i]>max)max=num[i];
			sum+=num[i];
		}
		for(a=max;sum%a!=0;a++)
		printf("%d\n",a+1);
		free(num);
	}
	return 0;
}
