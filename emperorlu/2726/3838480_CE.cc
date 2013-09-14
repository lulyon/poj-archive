#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n&&n!=0)
	{
		int (*a)[2]=new int[n][2];
		for(int i=0;i<n;i++)
		{
scanf("%d%d",&a[i][0],&a[i][1]);
			//cin>>a[i][0]>>a[i][1];
		}
		int s=0;
		for(i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(a[i][0]<a[j][0]&&a[i][1]<a[j][1])
				{
					s++;
					break;
				}
			}
		}
		cout<<s<<endl;
	}
	return 0;
}