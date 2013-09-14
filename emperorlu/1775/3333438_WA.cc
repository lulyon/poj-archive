#include<iostream>
#include<math.h>
using namespace std;
bool a[1000010];
long c[11][10000000];
void init()
{
	int i,j,L;
	a[0]=1;
	
	long tmp=1;
    for(i=1;i<=9;i++)
    {
		tmp*=i;
		c[0][i]=tmp;
		a[tmp]=1;
	}
	
	int flag,num=9;
	for(L=1;L<9;L++)
	{
		flag=0;
		for(i=1;i<=num;i++)
		{
			for(j=1;j<10;j++)
			{
				
				tmp=c[L-1][i]+c[0][j];
				if(tmp<=1000000 && !a[tmp])
				{
					a[tmp]=1;
					c[L][++flag]=tmp;
				}
			}
		}
		num=flag;
	//	cout<<num<<endl;
	//	system("pause");
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
