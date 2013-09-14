#include<iostream>
using namespace std;
typedef struct node
{
	int data,parent;
        bool visit;
}ufs_tree;
ufs_tree t[50010];
void ufs_make(int n)
{
	for(int i=1;i<=n;++i)
	{
		t[i].parent=i;
		t[i].data=i;
                t[i].visit=0;
	}
}
void ufs_justify(int p,int c)
{
    t[c].parent=p;
}

int ufs_find(int x,int y)
{
        t[x].visit=1;
        while(x!=t[x].parent)
        {
            x=t[x].parent;
            t[x].visit=1;
        }
        t[x].visit=1;
	
        while(t[y].visit==0)
        {
            y=t[y].parent;
        }
        return y;
}

int main()
{
	int t,n;
	int tt=0,t1,t2;
        cin>>t;
	while(t--)
	{
		scanf("%d",&n);
                
		ufs_make(n);

		for(int i=1;i<n;++i)
		{
			scanf("%d%d",&t1,&t2);
			ufs_justify(t1,t2);
		}
		scanf("%d %d",&t1,&t2);
                printf("%d\n",ufs_find(t1,t2));
                
	}
	return 0;
}
