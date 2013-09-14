/* Note:Your choice is C IDE */
#include "stdio.h"
int main()
{int n;float r,s;//s放到while里面赋初值 
  //while(scanf("%f",&r)!=EOF)输入r遇到0.0结束
	//改成下面 
  while(scanf("%f",&r),r!=0)
  {
  	for(n=1,s=0;s<=r;n++)
		  	s+=1.0/(n+1);
 // if(r>=0.01&&r<=5.20)对r没有限制啊 
 // printf("%d\n",n-1);
 // else printf(" ");
 //以上三行改成
    printf("%d card(s)\n",n-1);
 } 
 while(1);
 return 0;  
}
