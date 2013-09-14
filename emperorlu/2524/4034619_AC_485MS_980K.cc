#include<iostream>
using namespace std;
typedef struct node
{
	int data,parent,rank;
}ufs_tree;
ufs_tree t[50010];
void ufs_make(int n)
{
	for(int i=1;i<=n;++i)
	{
		t[i].parent=i;
		t[i].data=i;
		t[i].rank=0;
	}
}

int ufs_find(int x)
{
	int tmp=x;
        while(x!=t[x].parent)
            x = t[x].parent;
        
        t[tmp].parent = x;
        return x;
}

void ufs_union(int x,int y)
{
	x=ufs_find(x);
	y=ufs_find(y);
	if(t[x].rank<t[y].rank)
	{
		t[x].parent=y;
	}
	else
	{
		t[y].parent=x;
		if(t[x].rank==t[y].rank)
			++t[x].rank;
	}
}

int main()
{
	int n,m;
	int tt=0;
	while(1)
	{
		scanf("%d%d",&n,&m);
		if(!n&&!m)break;
		
		ufs_make(n);
		
		int t1,t2,i,j;
		for(i=0;i<m;++i)
		{
			scanf("%d%d",&t1,&t2);
			ufs_union(t1,t2);
		}
		int cn=0;
		for(i=1;i<=n;++i)
		{
			if(i == t[i].parent)cn++;
		}
		
		printf("Case %d: %d\n",++tt,cn);
	}
	return 0;
}
