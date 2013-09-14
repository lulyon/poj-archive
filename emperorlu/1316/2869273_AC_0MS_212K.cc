#include<stdio.h>
#include<stdlib.h>
int n[10000]={0};
int main()
{
    
    //freopen("me.txt","w",stdout);
    int i,j;
    for(i=1;i<10000;i++)
	{
          if(i>=1000)j=i+i%10+(i/10)%10+(i/100)%10+(i/1000)%10;
          else if(i>=100)j=i+(i/100)%10+(i/10)%10+i%10;
		  else if(i>=10)j=i+(i/10)%10+i%10;
          else j=i+i;
          n[j]=1;
    }
    for(j=1;j<10000;j++)
	    if(!n[j])printf("%d\n",j);
	//system("pause");
    return 0;
}
