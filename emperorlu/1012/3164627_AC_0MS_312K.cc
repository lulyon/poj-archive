#include <stdio.h>

int array[15]={0,2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881,13482720};

main()
{
 int k;
 while(scanf("%d",&k)&&k!=0)printf("%d\n",array[k]);
}
