#include<iostream>
using namespace std;
int main()
{
	int n,i,a[13],j,k,l,m,p;
	bool cn=0;
	cin>>n;
	while(n)
	{
        if(cn)printf("\n");
		for(i=1;i<=n;i++)
			cin>>a[i];
		for(i=1;i<=n-5;i++)
			for(j=i+1;j<=n-4;j++)
				for(k=j+1;k<=n-3;k++)
					for(l=k+1;l<=n-2;l++)
						for(m=l+1;m<=n-1;m++)
							for(p=m+1;p<=n;p++)
								printf("%d %d %d %d %d %d\n",a[i],a[j],a[k],a[l],a[m],a[p]);
		cn=1;
	   cin>>n;
	}
}
