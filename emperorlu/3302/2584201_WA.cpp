#include<stdio.h>
#include<string.h>
int f(char a[],char b[])
{
 		int i,j,temp,flag;
 		for(i=0,temp=0,flag=0;i<strlen(b);i++)
    {
	    for(j=temp;j<strlen(a);j++)
	    {
				 if(a[j]==b[i])
				 {
				    temp=j+1;
	          break;
				 }
	    }
	    if(j==strlen(a))
	    {
 				 flag=1;
 				 break;
		  }
	 }
	 return flag;
}
int main()
{
 		int i,j,n,flag1,flag2;
 		char a[100],b[100],c[100];
 		scanf("%d",&n);
 		while(n--)
 		{
			 scanf("%s%s",a,b);
			 flag1=f(a,b);
			 if(flag1==0)printf("YES\n");
			 else
			 {
			 		 for(i=strlen(b)-1,j=0;i>=0;i--,j++)
			 		 {
	 				    c[j]=b[i];
	 				 }
	 				 flag2=f(a,c);
	 				 if(flag2==0)printf("YES\n");
	 				 else printf("NO\n");
 		   }
    }
    return 0;
}
