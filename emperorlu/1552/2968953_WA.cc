#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
	return *(int *)a>*(int *)b;
}

int main()
{
	int p,i=0;
	int a[20];
	while(scanf("%d",&p),p+1)
	{
		if(p)
		{
			a[i++]=p;
			continue;
		}
		else
		{
			i--;
			int cn=0;
			qsort(a,i,sizeof(a[0]),cmp);
			for(int j=0;j<i;j++)
			{
				for(int k=j+1;k<i;k++)
				{
					if(a[k]==2*a[j])
					{
						cn++;
						break;
					}
				}
			}
			printf("%d\n",cn);
			i=0;
		}
	}
	return 0;
}
