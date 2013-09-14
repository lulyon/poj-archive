#include<iostream>
#include<math.h>
using namespace std;
__int64 a[550][550],b[550][550],c[550][550];
int main()
{
	int i,j,k,n;
	cin>>n;
	for(i=0;i<n;++i)
		for(j=0;j<n;++j)
			scanf("%I64d",&a[i][j]);
	for(i=0;i<n;++i)
		for(j=0;j<n;++j)
			scanf("%I64d",&b[i][j]);
	for(i=0;i<n;++i)
		for(j=0;j<n;++j)
		{
			scanf("%I64d",&c[i][j]);
			for(k=0;k<n;++k)
				c[i][j]-=a[i][k]*b[k][j];
			if(c[i][j])
			{
				printf("NO\n");
				return 0;
			}
		}
	printf("YES\n");
	//system("pause");
    return 0;
}
