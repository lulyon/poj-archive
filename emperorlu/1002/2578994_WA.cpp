#include<stdio.h>
#include<string.h>
char f(char x)
{
 		if(x=='A'||x=='B'||x=='C')return '2'; 
 		if(x=='D'||x=='E'||x=='F')return '3';
		if(x=='G'||x=='H'||x=='I')return '4';  
		if(x=='J'||x=='K'||x=='L')return '5'; 
		if(x=='M'||x=='N'||x=='O')return '6'; 
		if(x=='P'||x=='R'||x=='S')return '7'; 
		if(x=='T'||x=='U'||x=='V')return '8'; 
		if(x=='W'||x=='X'||x=='Y')return '9'; 
}
int main()
{
    int i,j,n,count;
    char a[10000][30];
		int flag[10000]={0};
    scanf("%d\n",&n);
    for(i=0;i<n;i++)
    {
		 	for(j=0,a[i][0]=getchar();a[i][j]!='\n';)
		 	{
					if(a[i][j]>='A'&&a[i][j]<='Z')
					{
						a[i][j]=f(a[i][j]);
						j++;
					}
					else if(a[i][j]>='0'&&a[i][j]<='9')
					{
						j++;
					}
					a[i][j]=getchar();
				}
    }
    for(i=0;i<n;i++)
    {
				count=1;
				for(j=i+1;j<n;j++)
				{
				   if(strcmp(a[i],a[j])==0)
						 {
						    count++;
						    flag[j]=1;
						 }
				}
				if(count>1&&flag[i]==0)
				{
			 	   for(j=0;j<7;j++)
			 	   {
							 if(j==3)printf("-");
						   printf("%c",a[i][j]);
				   }
				   printf(" %d\n",count);
				}
    }
    return 0;
}
