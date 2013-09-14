#include<iostream>
#include<math.h>
using namespace std;
bool a[1000010];
long c[11][11];
void init()
{
	int i,j,L;
	a[0]=1;
	long tmp=1;
    for(i=1;i<=9;i++)
    {
		tmp*=i;
		c[i][i]=tmp;
		a[tmp]=1;
	}
	for(L=1;L<9;L++)
	{
		for(i=1;i+L<10;i++)
		{
			j=i+L;
			c[i][j]=c[i][j-1]+c[j][j];
			if(c[i][j]<=1000000)a[c[i][j]]=1;
		}
	}
}
int main()
{
    init();
    long n;
    while(1)
    {
        scanf("%ld",&n);
        if(n<0)break;
        if(a[n])printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
