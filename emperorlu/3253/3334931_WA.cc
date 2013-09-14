#include<iostream>
#include<math.h>
using namespace std;
double w[100000]; 
typedef struct
{
	int parent,lchild,rchild;
	double weight;
}node,*huffmanTree;
void Select(huffmanTree &HT,int n,int &s1,int &s2)
{
	int i;
	double min=100000000;
	for(i=1;i<=n;i++)
	{
		if(!HT[i].parent && HT[i].weight<min)
		{
			min  = HT[i].weight;
			s1 = i;
		}
	}
	min = 10000000;
	for(i=1;i<=n;i++)
	{
		if(i!=s1 && !HT[i].parent && HT[i].weight<min)
		{
			min = HT[i].weight;
			s2 = i;
		}
	}
}
void huffmanCoding(huffmanTree &HT,double *w,int n)
{
	if(n<=1)return;
	int m=2*n-1;
	huffmanTree p;
	HT = new node[m+1];
	
	//system("PAUSE");
	
	
	int i,s1,s2;
	
	for( p=HT,i=1;i<=n;++i,++p,++w)
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
double WPL(huffmanTree &HT,double *w,int n)
{
	double sum=0;
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
	while(cin>>n)
	{
	for(int i=1;i<=n;i++)
		scanf("%lf",w+i);
	
	
	if(n==1)
	{
		printf("0\n");
		return 0;
	}
	
	//system("pause");
	huffmanTree HT;
	
	huffmanCoding(HT,w,n);
	printf("%.0lf\n",WPL(HT,w,n));
	}
    return 0;
}
