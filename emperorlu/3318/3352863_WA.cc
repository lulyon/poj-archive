#include<iostream>
#include<math.h>
#include <time.h>
using namespace std;
char a[510][510],b[510][510],c[510][510];
int main()
{
	clock_t start,finish;
	double duration;
	int ii,jj,i,j,k,n;
	start = clock();
	scanf("%d",&n);
	for(i=0;i<n;++i)
		for(j=0;j<n;++j)
			scanf("%d",&a[i][j]);
			
	for(i=0;i<n;++i)
		for(j=0;j<n;++j)
			scanf("%d",&b[i][j]);
	
	for(i=0;i<n;++i)
		for(j=0;j<n;++j)
			scanf("%d",&c[i][j]);
	
	while(1)
	{
		srand((int)time(0));
		ii = rand()%n;
		srand((int)time(0)%n);
		jj= rand()%n;
		for(k=0;k<n;++k)
			c[ii][jj] -= a[ii][k]*b[k][jj];
		if(c[ii][jj])
		{
			printf("NO\n");
			//system("pause");
			return 0;
		}
		else
		{
			finish = clock();
			duration = (double)(finish - start) / CLOCKS_PER_SEC;
			if(duration>1.7)
			{
				printf("YES\n");
				//system("pause");
				return 0;
			}
		}
	}
	
    return 0;
}
