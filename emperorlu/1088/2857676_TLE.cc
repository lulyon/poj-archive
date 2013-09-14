#include<stdio.h>
//#include<stdlib.h>
int r,c,a[101][101],flag[101][101];
int huaxue(int i,int j)
{
	int temp,max=1;
	//if(flag[i][j]!=-1) return flag[i][j];
	if(a[i][j]>a[i-1][j]&&i>1)
	{   temp=huaxue(i-1,j);
	    if(max<temp+1) max=temp+1;
	}
	if(a[i][j]>a[i][j-1]&&j>1)
	{   temp=huaxue(i,j-1);
	    if(max<temp+1) max=temp+1;
	}
	if(a[i][j]>a[i+1][j]&&i<r)
	{   temp=huaxue(i+1,j);
	    if(max<temp+1) max=temp+1;
	}
	if(a[i][j]>a[i][j+1]&&j<c)
	{   temp=huaxue(i,j+1);
	    if(max<temp+1) max=temp+1;
	}
	flag[i][j]=max;
	return max;
}

int main()
{
	int i,j,temp,max=0;
	scanf("%d%d",&r,&c);
	for(i=1;i<=r;i++)
		for(j=1;j<=c;j++)
		{
            scanf("%d",&a[i][j]);
		    flag[i][j]=-1;
		}
    for(i=1;i<=r;i++)
		for(j=1;j<=c;j++)
		{
            temp=huaxue(i,j);
            if(max<temp) max=temp;
		}
    printf("%d\n",max);
    //system("pause");
    return 0;
}