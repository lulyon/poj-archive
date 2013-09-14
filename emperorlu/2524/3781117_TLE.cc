#include<iostream>
using namespace std;
typedef struct node
{
	int data,parent,rank;
}ufs_tree;
ufs_tree t[50010];
bool b[50010];
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
	if(x==t[x].parent)
		return x;
	return ufs_find(t[x].parent);
}

void ufs_union(int x,int y)
{
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
	int t=0;
	while(1)
	{
		scanf("%d%d",&n,&m);
		if(!n&&!m)break;
		
		ufs_make(n);
		
		int t1,t2;
		for(int i=0;i<m;++i)
		{
			scanf("%d%d",&t1,&t2);
			ufs_union(t1,t2);
		}
		
		memset(b,0,(n+5)*sizeof(bool));
		
		for(int i=1;i<=n;++i)
			b[ufs_find(i)]=1;
		
		int cn=0;
		
		for(int i=1;i<=n;++i)
			if(b[i])cn++;
		printf("Case %d: %d\n",++t,cn);
	}
	return 0;
}


