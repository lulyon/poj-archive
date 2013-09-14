#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include<set>
#include<math.h>

void swap(__int64 &a,__int64 &b)
{
	__int64 tmp;
	tmp = a;
	a = b;
	b = tmp;
}
using namespace std;
int main()
{
	const double ygold= (sqrt(5.0)+1)/2;
	__int64 a,b,k;
	while(cin>>a>>b)
	{
		if(a>b)
			swap(a,b);
		k= b-a;
		if(a == (__int64)(k*ygold))
			cout<<1<<endl;
		else
			cout<<0<<endl;
	}
    return 0;
}
