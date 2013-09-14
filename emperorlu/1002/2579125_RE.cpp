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
    int i,j,n,min,count[10000],temp2,temp3;
    char a[10000][30],*p[10000],*temp1;
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
				count[i]=1;
				for(j=i+1;j<n;j++)
				{
				   if(strcmp(a[i],a[j])==0)
						 {
						    count[i]++;
						    flag[j]=1;
						 }
				}
    }
    for(i=0;i<n;i++)
    {
				if(count[i]>1&&flag[i]==0)
				p[i]=a[i];
		}
    for(i=0;i<n;i++)
    {
				if(count[i]>1&&flag[i]==0)
				{
				   for(j=i+1,min=i;j<n;j++)
			     {
				     if(count[j]>1&&flag[j]==0&&strcmp(p[j],p[i])<0)
									min=j;
				   }
				temp1=p[i];p[i]=p[min];p[min]=temp1;
				temp2=count[i];count[i]=count[min];count[min]=temp2;
				temp3=flag[i];flag[i]=flag[min];flag[min]=temp3;
				}
 		}
 		for(i=0;i<n;i++)
 		{
			if(count[i]>1&&flag[i]==0)
			{
			   for(j=0;j<7;j++)
			   {
					 if(j==3)printf("-");
					 printf("%c",*(p[i]+j));
		 		 }
		 		 printf(" %d\n",count[i]);
			}
		}
    return 0;
}
