#include<iostream>
using namespace std;
int main()
{
	int a,b,c,d,t,tt=0;
	cin>>t;
	while(t--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		printf("Scenario #%d:\n",++tt);
		printf("%d\n\n",(a+b+c+d)%2);
	}
    return 0;
}
