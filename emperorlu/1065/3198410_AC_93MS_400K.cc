#include<iostream>
#include<math.h>
using namespace std;
typedef struct In
{
	int x,y;
}stick;
stick stack[10010];
bool b[10010];
bool cmp(const stick &a,const stick &b)
{
	if(a.x!=b.x)return a.x<b.x;
	else return a.y<b.y;
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
		memset(b,0,n*sizeof(bool));
		stick tmp;
		int cn=0;
		
		/*
		for(int i=0;i<n;++i)
			cout<<stack[i].x<<' '<<stack[i].y<<' ';
		system("pause");
		*/
		int i,j;
		while(1)
		{
			for(j=0;j<n;++j)
				if(!b[j])
				{
					cn++;
					tmp.y=stack[j].y;
					b[j]=1;
					break;
				}
			if(j==n)break;
			for(i=j+1;i<n;++i)
			{
				if(!b[i]&&tmp.y<=stack[i].y)
				{
					tmp.y=stack[i].y;
					b[i]=1;
				}
			}
		}
		cout<<cn<<endl;
	}
    return 0;
}
