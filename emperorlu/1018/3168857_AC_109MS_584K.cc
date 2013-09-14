#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
int width[10000];
int top;

struct man
{
	int price,width;
};

struct node
{
	man value;
	node* next;
	node():next(NULL){};
};

node *head[100];
void init()
{
	int i;
	for(i=0;i<100;i++)
	{
		head[i]=new node();
	}
}

void clear(int n)
{
	node* dp;
	int i;
	for(i=0;i<n;i++)
	{
		dp=head[i]->next;
		while(dp!=NULL)
		{
			head[i]->next=dp->next;
			delete dp;
			dp=head[i]->next;
		}
	}
}



inline int cmp(const man& m1,const man& m2)
{
	if(m1.price<=m2.price&&m1.width>=m2.width)
		return 1;
	if(m2.price<=m1.price&&m2.width>=m1.width)
		return -1;
	return 0;
}

inline bool cmp1(const man& m1,const man& m2)
{
	return m1.width*m2.price>m1.price*m2.width;
}

bool cmp2(int a,int b)
{
	return a>b;
}


void insert(const man& in,int index)
{
	node *sp,*pre;
	int c;
	bool inser=true;
	pre=head[index];
	sp=pre->next;
	while(sp!=NULL)
	{
		c=cmp(in,sp->value);
		if(c==1)
		{
			pre->next=sp->next;
			delete sp;
			sp=pre->next;
		}
		else if(c==-1)
		{
			inser=false;
			break;
		}
		else
		{
			pre=sp;
			sp=sp->next;
		}
	}
	if(inser)
	{
		sp=head[index]->next;
		pre=head[index];
		while(sp!=NULL&&sp->value.price<in.price)
		{
			pre=sp;
			sp=pre->next;
		}
		pre->next=new node();
		pre=pre->next;
		pre->value.price=in.price;
		pre->value.width=in.width;
		pre->next=sp;
	}
}



int read(int n)
{
	int i,j,m;
	int maxrow,minmaxrow=0x7fffffff;
	man readin;
	top=0;
	for(i=0;i<n;i++)
	{
		cin>>m;
		maxrow=0;
		for(j=0;j<m;j++)
		{
			cin>>readin.width>>readin.price;
			width[top++]=readin.width;
			maxrow=max(readin.width,maxrow);
			insert(readin,i);
		}
		minmaxrow=min(minmaxrow,maxrow);
	}
	sort(width,width+top,cmp2);
	return minmaxrow;
}


int findminprice(int index,int boundwidth)
{
	node* sp=head[index]->next;
	while(sp->value.width<boundwidth)
	{
		sp=sp->next;
	}
	return sp->value.price;
}


int findmax(int boundwidth,int n)
{
	int allprice=0;
	int i;
	for(i=0;i<n;i++)
	{
		allprice+=findminprice(i,boundwidth);
	}
	return allprice;
}

int main()
{
	int test,n,boundw,nextindex;
	man currentman,minman;
	cin>>test;
	init();
	while(test>0)
	{
		test--;
		cin>>n;
		boundw=read(n);
		minman.width=boundw;
		minman.price=findmax(boundw,n);
		nextindex=0;
		while(width[nextindex]!=boundw)
			nextindex++;
		while(nextindex<top&&width[nextindex]==boundw)
			nextindex++;
		while(nextindex<top)
		{
			boundw=width[nextindex];
			currentman.width=boundw;
			currentman.price=findmax(boundw,n);
			if(cmp1(currentman,minman))
			{
				minman.price=currentman.price;
				minman.width=currentman.width;
			}
			while(nextindex<top&&width[nextindex]==boundw)
				nextindex++;
		}
		clear(n);
		cout<<fixed<<setprecision(3)<<(double)minman.width/(double)minman.price<<endl;
	}
	return 0;
}


