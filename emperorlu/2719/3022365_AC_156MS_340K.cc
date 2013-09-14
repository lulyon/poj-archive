#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	char a[20];
	__int64 i,j,n,m,sum;
	while(1)
	{
		cin>>a;
		if(a[0]=='0')break;
		sum=0;
		n=strlen(a);
		for(i=n-1,j=0;i>=0&&j<n;i--,j++)
		{	
			m=a[j]-'0';
		    if(m>=4)m--;
			sum+=m*(int)pow(9.0,i);
		}
		cout<<a<<": "<<sum<<endl;
	}
	return 0;
}
