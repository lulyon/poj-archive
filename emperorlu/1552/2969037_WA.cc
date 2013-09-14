#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
	return *(int *)a>*(int *)b;
}
int main()
{
    int i,j,n,a[10000],temp,sub,count;
    while(1)
	{
		scanf("%d",a);
        if(a[0]==-1)return 0;
        for(i=0;a[i]!=0;i++)
            scanf("%d",a+i+1);
    	n=i;
        qsort(a,i,sizeof(a[0]),cmp);
 	    for(i=1,count=0;i<n;i++)
        {
        	for(j=0;j<i;j++)
           	{
                if(a[i]==2*a[j])
                {
                   	count++;
                   	break;
               	}
          	}
        }
        printf("%d\n",count);
	}
    return 0;
}