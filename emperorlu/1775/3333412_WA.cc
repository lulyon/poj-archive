#include<iostream>
#include<math.h>
using namespace std;
bool a[1000010];
void init()
{
	long i;
	a[0]=1;
	long long tmp=1,sum=0;
    for(i=1;;i++)
    {
		tmp*=i;
		sum+=tmp;
		if(sum>1000000)break;
		a[sum]=1;
	}
}
int main()
{
    init();
    long n;
    while(1)
    {
        scanf("%ld",&n);
        if(n<0)break;
        if(a[n])printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
