#include<stdio.h>
int main()
{
 		int i,n,mem,sum,max;
 		while(scanf("%d",&n),n!=0)
		{
		   max=sum=0;
	     while(n--)
 		   {
			   scanf("%d",&mem);
			   if(mem>max)max=mem;
			   sum+=mem;
       }
       for(i=max+1;sum%i!=0;i++);
       printf("%d\n",i);
		}
 		return 0;
}
