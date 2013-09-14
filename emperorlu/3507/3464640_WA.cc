#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int a,b,c,d,e,f;
	while(1)
	{
		scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
		if(!a && !b && !c && !d && !e && !f)break;
		cout<<(a+b+c+d+e+f)/6.0<<endl;
	}
    return 0;
}
