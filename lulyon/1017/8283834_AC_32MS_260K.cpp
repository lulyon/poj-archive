#include <iostream>
using namespace std;
int main()
{
	int a[10],i,j,sum,m,left1,left2;
	int u[4]={0,5,3,1};
	while (1)
	{
		sum=0;
		for(i=1;i<=6;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
		if(sum==0)
			break;
		m=a[6]+a[5]+a[4]+(3+a[3])/4;
		left2=a[4]*5+u[a[3]%4];
		if(a[2]>left2)
			m+=(a[2]-left2+8)/9;
		left1=m*36-a[6]*36-a[5]*25-a[4]*16-a[3]*9-a[2]*4;
		if(a[1]>left1)
			m+=(a[1]-left1+35)/36;
		cout<<m<<endl;
	}
	return 0;
}