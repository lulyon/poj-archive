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
	int i,j,n,tmp,pp,qq;
	while(1)
	{
		cin>>pp>>qq;
		if(pp==-1&&qq==-1)break;
		stack[0].x=pp;
		stack[0].y=qq;
		for(i=1;;++i)
		{
			cin>>stack[i].x>>stack[i].y;
			if(!stack[i].x&&!stack[i].y)
			{
				n=i;
				break;
			}
		}
		sort(stack,stack+n,cmp);
		memset(b,0,n*sizeof(bool));
		int cn=0;
		while(1)
		{
			for(j=0;j<n;++j)
				if(!b[j])
				{
					cn++;
					tmp=stack[j].y;
					b[j]=1;
					break;
				}
			if(j==n)break;
			for(i=j+1;i<n;++i)
			{
				if(!b[i]&&tmp<=stack[i].y)
				{
					tmp=stack[i].y;
					b[i]=1;
				}
			}
		}
		cout<<cn<<endl;
	}
    return 0;
}
