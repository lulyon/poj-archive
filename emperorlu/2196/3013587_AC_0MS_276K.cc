#include<iostream>
using namespace std;
int sum(int n)
{
	int s;
	s=n%10;
	n/=10;
	s+=n%10;
	n/=10;
	s+=n%10;
	n/=10;
	s+=n%10;
	return s;
}
int to12(int n)
{
	int s;
	s=n%12;
	n/=12;
	s+=n%12;
	n/=12;
	s+=n%12;
	n/=12;
	s+=n%12;
	return s;
}
int to16(int n)
{
	int s;
	s=n%16;
	n/=16;
	s+=n%16;
	n/=16;
	s+=n%16;
	n/=16;
	s+=n%16;
	return s;
}
bool check(int n)
{
	int a,b,c;
	a=sum(n);
	b=to12(n);
	c=to16(n);
	if(a==b&&b==c)return 1;
	else return 0;
}
int main()
{
	int n;
	for(int i=2992;i<10000;i++)
		if(check(i))cout<<i<<endl;
	return 0;
}
