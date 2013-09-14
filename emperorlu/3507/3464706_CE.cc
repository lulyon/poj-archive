#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int a[6];
	while(1)
	{
		int max=-1,min=INT_MAX;
		for(int i=0;i<6;++i)
		{
			scanf("%d",a+i);
			if(a[i]<min)min = a[i];
			if(a[i]>max)max = a[i];
		}
		
		if(!a && !b && !c && !d && !e && !f)break;
		cout<<(a[0]+a[1]+a[2]+a[3]+a[4]+a[5]+a[6]-max-min)/6.0<<endl;
	}
    return 0;
}
