#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a[1000][1000];
int main()
{
    memset(a,0,sizeof(a));
	char head[20];
	int x,y,l,i,j,t,g,num=0;
	scanf("%d",&t);
	for(g=1;g<=t;g++)
    {
		scanf("%s %d %d %d",head,&x,&y,&l);
		if(head[0]=='B')
        {
			for(i=x;i<=x+l-1;i++)
				for(j=y;j<=y+l-1;j++)
					a[i][j]=1;
		}
		if(head[0]=='W')
        {
			for(i=x;i<=x+l-1;i++)
				for(j=y;j<=y+l-1;j++)
					a[i][j]=0;
		}
		if(head[0]=='T')
        {
			num=0;
			for(i=x;i<=x+l-1;i++)
            {
				for(j=y;j<=y+l-1;j++)
                {
					if(a[i][j]==1)num++;
				}
			}
			printf("%d\n",num);
		}
	}
	system("pause");
	return 0;
}
