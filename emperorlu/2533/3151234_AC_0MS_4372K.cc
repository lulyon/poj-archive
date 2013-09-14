#include<iostream>
#include<string>
using namespace std;
int a[1010],b[1010],c[1010][1010];
int lcslen(int mm,int nn)
{
	int m,n,i,j;
	m=mm,n=nn;
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
    int mm;
    scanf("%d",&mm);
    for(int i=0;i<mm;i++)
    {
        scanf("%d",a+i);
        b[i]=a[i];
    }
    sort(b,b+mm);
    int nn=mm;
    for(int i=0;i<nn-1;)
    {
        if(b[i]==b[i+1])
        {
            for(int j=i;j<nn-1;j++)
            {
                b[j]=b[j+1];
            }
            nn--;
        }
        else i++;
    }
    //cout<<nn<<endl;
    //system("pause");
    printf("%d\n",lcslen(mm,nn));
    
    //system("pause");
    return 0;
}