#include<stdio.h>
#include<stdlib.h>
int cmp ( const void *a , const void *b ) 
{ 
return *(int *)b - *(int *)a; 
} 
int main()
{
 		int i,a[6],flag,count=0,t1,t2;
 		leap:count++;
 		for(i=0,flag=0;i<6;i++)
 		{
		   scanf("%d",a+i);
		   if(a[i]!=0)flag=1;
		   a[i]*=(i+1);
    }
 		if(flag==1)
 		{
		   printf("\nCollection #%d:\n",count);
		   qsort(a,6,sizeof(a[0]),cmp);
			 for(i=0,t1=0,t2=0;i<6;i++)
			 {
			    if(t1<=t2)t1+=a[i];
			    else t2+=a[i];
			 } 
			 if(t1==t2)printf("Can be divided.\n");
			 else printf("Can't be divided.\n");
			 goto leap;
    }
    return 0;
}
