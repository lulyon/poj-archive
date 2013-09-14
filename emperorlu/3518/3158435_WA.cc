#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include<set>
#include<math.h>
using namespace std;

bool prime(int n)
{
	int i;
	if(n%2==0)return 0;
	int m = (int)sqrt(n);
	for(i=3;i<=m;i+=2)
		if(n%i==0)return 0;
	return 1;
}
int main()
{
	long num;
	int i,j,left,right,lenth;
	while(1)
	{
		scanf("%ld",&num);
		if(!num)break;
		if(!prime(num))
		{
			for(i=num-1;i>1;i--)
				if(prime(i))break;
			left = i;
			for(i=num+1;;i++)
				if(prime(i))break;
			right = i;
			lenth = right - left;
		}
		else lenth = 0;
		cout<<lenth<<endl;
	}
    return 0;
}
