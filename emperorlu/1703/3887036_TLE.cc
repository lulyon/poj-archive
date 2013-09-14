#include<iostream>
using namespace std;
typedef struct node
{
	int data,parent;
}ufs_tree;
	int tt=0,t1,t2,d1,d2,r1,r2;

ufs_tree t[500100];
char temp[1000];

void ufs_make(int n)
{
	for(int i=1;i<=n;++i)
	{
		t[i].parent=i;
	}
}

int ufs_find(int x,int &cnt)
{
    while(x!=t[x].parent)
    {
        x=t[x].parent;
        cnt++;
    }
    return x;
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

	while(Case--)
	{
		scanf("%d%d",&n,&m);
                getchar();
                
		ufs_make(n);
                
                
                bool flag=0;
                char tag;
		for(int i=0;i<m;++i)
		{
                    gets(temp);
                    sscanf(temp,"%c %d %d",&tag,&t1,&t2);
                        
                    d1=d2=0;
                        r1 = ufs_find(t1,d1);
                        r2 = ufs_find(t2,d2);
                        
                    if(tag=='A')
                    {
                        if(r1==r2)
                        {
                            if((d1-d2)%2==0)
                            {
                                printf("In the same gang.\n");                     
                            }
                            else
                            {
                                printf("In different gangs.\n");
                            }
                        }
                        else
                        {
                            printf("Not sure yet.\n");
                        }
                    }
                    else
                    {
                        if(r1!=r2)
                        {
                            if((d1-d2)%2==0)
                            {
                               
                                    ufs_union(r1,r2);
                            }
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
                                    ufs_union(pre,r1);
                                }
                                else
                                {
                                    int pre;
                                    while(t1!=t[t1].parent)
                                    {
                                        pre=t1;
                                        t1=t[t1].parent;
                                    }
                                    ufs_union(pre,r2);
                                }
                            }
                        }
                    }
                    
		}
	}
	return 0;
}

