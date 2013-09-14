#include<iostream>
using namespace std;

const int maxn = 50000;

typedef struct
{
	int flag;
	int next;
	int pre;
}node;

node list[maxn];
int table[maxn];


void init()
{
	int i,j;
	for(i=2;i<maxn;++i)
	{
		list[i].next = i+1;
		list[i].pre = i-1;
		list[i].flag = 0;
	}
	
	int cnt=1;
	for(i=2;;i=list[i].next)
	{
		if(list[i].flag==0)
		{
			
			list[i].flag = -1;
			
			list[list[i].pre].next = list[i].next;
			list[list[i].next].pre = list[i].pre;
			
			table[cnt++]=i;
			
			if(cnt>3000)break;
			
			j=i;
			
			
			for(;;)
			{
				
				for(int k=1;k<=i;++k)
				{
					j=list[j].next;
					if(j>40000)break;
				}
				
				if(j>40000)break;
				
				list[j].flag = 1;
				
				list[list[j].pre].next=list[j].next;
				list[list[j].next].pre = list[j].pre;
				
				
			}
		}
	}
	
}

int main()
{
	init();
	int n;
	while(1)
	{
		scanf("%d",&n);
		if(!n)break;
		
		printf("%d\n",table[n]);
	}
    return 0;
}
