#include<iostream>
#include<string>
using namespace std;
int a[1000],b[1000],c[1000][1000];
int lcslen(int nn)
{
	int m,n,i,j;
	m=n=nn;
	for(i=0;i<=m;i++)
		c[i][0]=0;
	for(j=0;j<=n;j++)
		c[0][j]=0;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(a[i-1]==b[j-1])
				c[i][j]=c[i-1][j-1]+1;
			else
				if(c[i-1][j]>=c[i][j-1])
					c[i][j]=c[i-1][j];
			else
				c[i][j]=c[i][j-1];
	return c[m][n];
}

int main()
{
    int nn;
    scanf("%d",&nn);
    if(!nn)
    {
        printf("1\n");
        return 0;
    }
    for(int i=0;i<nn;i++)
    {
        scanf("%d",a+i);
        b[i]=a[i];
    }
    sort(b,b+nn);
    printf("%d\n",lcslen(nn));
    //system("pause");
    return 0;
}
