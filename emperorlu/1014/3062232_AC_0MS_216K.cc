#include<stdio.h>
int a[7];
int check(int sum)
{
	for(int b=0;b<=a[1];b++)
		for(int c=0;c<=a[2];c++)
			for(int d=0;d<=a[3];d++)
				for(int e=0;e<=a[4];e++)
					for(int f=0;f<=a[5];f++)
						for(int g=0;g<=a[6];g++)
							if(sum==b+2*c+3*d+4*e+5*f+6*g)return 1;
	return 0;
}
int main()
{
	int i,sum,cn=1;
	while(1)
	{
		sum=0;
		for(i=1;i<=6;i++)
			scanf("%d",a+i);
		if(!a[1]&&!a[2]&&!a[3]&&!a[4]&&!a[5]&&!a[6])break;
		for(i=1;i<=6;i++)
		{
            a[i]%=30;
            sum+=i*a[i];
        }
		printf("Collection #%d:\n",cn++);
		if(sum%2)
		{
			printf("Can't be divided.\n\n");
			continue;
		}
		sum/=2;	
		if(check(sum))printf("Can be divided.\n\n");
			else printf("Can't be divided.\n\n");
	}
	return 0;
}
