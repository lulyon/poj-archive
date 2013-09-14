#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include<set>
#include<math.h>
using namespace std;
int main()
{
	const double yGold = (sqrt(5)+1)/2;
	double ki;
	__int64 a,b,k,tmp;
	while(cin>>a>>b)
	{
		if(a>b)
		{
			tmp = a;
			a = b;
			b = tmp;
		}
		ki=a/yGold;
		k=(__int64)ki;
		if((__int64)(k*yGold)==a)
		{
			if(b==k+a)
				cout<<0<<endl;
			else
				cout<<1<<endl;
		}
		else
		{
			k++;
			if((__int64)(k*yGold)==a)
			{
				if(b==k+a)
					cout<<0<<endl;
				else
					cout<<1<<endl;
			}
		}
	}
    return 0;
}
