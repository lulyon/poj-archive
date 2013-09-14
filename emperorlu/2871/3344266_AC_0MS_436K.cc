#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	double pre,now;
	cin>>pre;
	while(1)
	{
		cin>>now;
		if(now>200)break;
		printf("%.2lf\n",now-pre);
		pre = now;
	}
	printf("End of Output\n");
    return 0;
}
