#include<iostream>
#include<math.h>
using namespace std;
typedef struct In
{
	int x,y;
}stick;
stick stack[10010];
bool cmp(const stick &a,const stick &b)
{
	return a.x<b.x;
}
int main()
{
	int t,
		n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;++i)
			cin>>stack[i].x>>stack[i].y;
		sort(stack,stack+n,cmp);
		stick tmp;
		tmp.x=stack[0].x;
		tmp.y=stack[0].y;
		int cn=1;
		for(int i=1;i<n;++i)
		{
			if(tmp.y<=stack[i].y)continue;
			else
			{
				cn++;
				tmp.y=stack[i].y;
			}
		}
		cout<<cn<<endl;
	}
    return 0;
}
