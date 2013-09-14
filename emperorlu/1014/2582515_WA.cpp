#include<stdio.h>
#include<stdlib.h>
int cmp ( const void *a , const void *b ) 
{ 
return *(int *)b - *(int *)a; 
} 
int main()
{
 		int i,a[6],flag,count=0,t1,t2,sum,temp;
 		leap:count++;
 		for(i=0,flag=0,sum=0;i<6;i++)
 		{
		   scanf("%d",a+i);
		   if(a[i]!=0)flag=1;
		   a[i]*=(i+1);
		   sum+=a[i];
    }
 		if(flag==1)
 		{
		   printf("Collection #%d:\n",count);
		   qsort(a,6,sizeof(a[0]),cmp);
		   if(sum%2!=0)printf("Can't be divided.\n\n");
			 else
			 {
			 		 for(i=0,temp=0;i<6&&temp<sum/2;i++)
			 		 {
						  if(temp+a[i]<=sum/2)
						      temp+=a[i];
			     }
			     if(temp==sum/2)printf("Can be divided.\n\n");
			     else printf("Can't be divided.\n\n");
			 }
			 goto leap;
    }
    return 0;
}
