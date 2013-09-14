#include <stdio.h>
int main()
{
	long a,i;
	cin>>a;
	for(i=a;;i--)if((a*a+1)%i==0)break;
	cout<<2*a+(a*a+1)/i+i<<endl;
	return 0;
}