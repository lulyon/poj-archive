#include<iostream>
using namespace std;
typedef struct node
{
	int data,parent;
}ufs_tree;
ufs_tree t[50010];
int a[1000010][2];

void ufs_make(int n)
{
	for(int i=1;i<=n;++i)
	{
		t[i].parent=i;
		t[i].data=i;
	}
}

int ufs_find(int x,int &cnt)
{
	if(x==t[x].parent)
		return x;
        cnt++;
	return ufs_find(t[x].parent,cnt);
}

void ufs_union(int x,int y)
{
            t[y].parent=x;
}

int main()
{
    //freopen("/export/home/acm/Desktop/tud2005/secret/6/sin","r",stdin);
	int n,m;
        int Case;
        cin>>Case;
	int tt=0,t1,t2,d1,d2,r1,r2;
	while(Case--)
	{
		scanf("%d%d",&n,&m);
                
		ufs_make(n);
                for(int i=0;i<m;++i)
                    scanf("%d %d",&a[i][0],&a[i][1]);
                
                printf("Scenario #%d:\n",++tt);
                
                bool flag=0;
		for(int i=0;i<m;++i)
		{
			t1=a[i][0];
                        t2=a[i][1];
                        
                        d1=d2=0;
                        r1 = ufs_find(t1,d1);
                        r2 = ufs_find(t2,d2);
                        
                        if(r1==r2)
                        {
                            if((d1-d2)%2==0)
                            {
                                printf("Suspicious bugs found!\n\n");
                                flag=1;
                                break;
                            }
                        }
                        else
                        {
                            if((d1-d2)%2==0)
                                ufs_union(r1,r2);
                            else
                            {
                                if(d1<d2)
                                {
                                    int pre;
                                    while(t2!=t[t2].parent)
                                    {
                                        pre=t2;
                                        t2=t[t2].parent;
                                    }
                                    ufs_union(pre,t1);
                                }
                                else
                                {
                                    int pre;
                                    while(t1!=t[t1].parent)
                                    {
                                        pre=t1;
                                        t1=t[t1].parent;
                                    }
                                    ufs_union(pre,t2);
                                }
                            }
                        }
		}
                if(flag==0)
                    printf("No suspicious bugs found!\n\n");
	}
	return 0;
}


