#include<iostream>
using namespace std;
typedef struct node
{
	int rank,parent;
}ufs_tree;


ufs_tree t[500100];
char temp[1000];

void ufs_make(int n)
{
	for(int i=1;i<=n;++i)
	{
		t[i].parent=i;
                t[i].rank=0;
	}
}

int ufs_find(int x,int &cnt,int &pre)
{
    while(x!=t[x].parent)
    {
        pre=x;
        x=t[x].parent;
        cnt++;
    }
    return x;
}

void ufs_union1(int x,int y)
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

void ufs_union(int x,int y)
{
    t[x].parent=y;
}

int main()
{
    //freopen("/export/home/acm/Desktop/tud2005/secret/6/sin","r",stdin);
	int n,m;
        int Case;
        int tt=0,t1,t2,d1,d2,r1,r2,p1,p2;
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
                        
                    p1=p2=d1=d2=0;
                        r1 = ufs_find(t1,d1,p1);
                        r2 = ufs_find(t2,d2,p2);
                        
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
                                    
                                    ufs_union1(p2,r1);
                                }
                                else
                                {
                                    
                                    ufs_union(p1,r2);
                                }
                            }
                        }
                    }
                    
		}
	}
	return 0;
}
