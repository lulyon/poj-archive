#include<iostream>
#include<math.h>
using namespace std;
__int64 w[100000]; 
typedef struct
{
	int parent,lchild,rchild;
	__int64 weight;
}node,*huffmanTree;
void Select(huffmanTree &HT,int n,int &s1,int &s2)
{
	int i;
	__int64 min=100000000;
	for(i=1;i<=n;i++)
	{
		if(!HT[i].parent && HT[i].weight<min)
		{
			min  = HT[i].weight;
			s1 = i;
		}
	}
	
	//cout<<min<<endl;
	//system("pause");
	
	min = 10000000;
	for(i=1;i<=n;i++)
	{
		if(i!=s1 && !HT[i].parent && HT[i].weight<min)
		{
			min = HT[i].weight;
			s2 = i;
		}
	}
	///cout<<s1<<' '<<s2<<endl;
//	system("pause");
}
void huffmanCoding(huffmanTree &HT,__int64 *w,int n)
{
	if(n<=1)return;
	int m=2*n-1;
	huffmanTree p;
	HT = new node[m+1];
	
	//system("PAUSE");
	
	
	int i,s1,s2;
	
	for( p=&HT[1],i=1,++w;i<=n;++i,++p,++w)
	{
		p->parent = p->lchild = p->rchild = 0;
		p->weight = *w;
	}
	for(; i<=m ; ++i)
	{
		p->parent = p->lchild = p->rchild = 0;
		p->weight = 0;
	}
	
	//system("pause");
	
	for(i=n+1 ; i<=m ; ++i)
	{
		s1 = s2= 0;
		Select(HT,i-1,s1,s2);
		
		//cout<<s1<<' '<<s2<<endl;
	//	system("pause");
		
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].parent = 0;
		HT[i].weight = HT[s1].weight +HT[s2].weight;
	}
	
	//system("pause");
}
__int64 WPL(huffmanTree &HT,__int64 *w,int n)
{
	__int64 sum=0;
	int i,f,level;
	
	//system("pause");
	
	for(i=1;i<=n;++i)
	{
		level = 0;
		
		//system("pause");
		
		for(f=HT[i].parent ; f!=0; f=HT[f].parent)
		{
			//cout<<f<<endl;
			//system("pause");
			level++;
		}
		
	//	system("pause");
		
		sum+=level*w[i];
	}
	return sum;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%I64d",w+i);
	
	
	if(n==1)
	{
		printf("0\n");
		
		//system("pause");
		
		return 0;
	}
	
	//system("pause");
	huffmanTree HT;
	
	huffmanCoding(HT,w,n);
	printf("%I64d\n",WPL(HT,w,n));
	
	//system("pause");
    return 0;
}
