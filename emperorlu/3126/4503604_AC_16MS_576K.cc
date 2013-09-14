#include<iostream>
#include<math.h>
using namespace std;
const int maxn=10000;
bool bused[maxn];

typedef struct
{
	int depth;
	int num;
	int bindex;
}Lst;
Lst list[maxn];
bool pr[maxn];


bool prime(int n)
{
	return pr[n];
}

int bfs(int a,int b)
{
	if(a==b)return 0;
	
	int head,tail;
	head=tail=0;
	bused[a]=1;
	list[0].num=a;
	list[0].depth=0;
	list[0].bindex=-1;
	int num,temp,remain;
	while(head<=tail)
	{	
		num=list[head].num%10;
		remain = list[head].num-num;
		
		for(int i=1;i<10;i+=2)
		{
			if(i==num)continue;
			temp = remain+i;
			if(prime(temp))
			{
				if(temp==b)
				{
				
					return list[head].depth+1;
				}
				if(!bused[temp])
				{
					bused[temp]=1;
					list[++tail].num=temp;
					list[tail].depth=list[head].depth+1;
					list[tail].bindex=head;
				}
			}
		}
		
		num=list[head].num%100/10;
		remain=list[head].num-num*10;
		
		for(int i=0;i<10;++i)
		{
			if(i==num)continue;
			temp = i*10+remain;
			if(prime(temp))
			{
				
				if(temp==b)
				{
					
					return list[head].depth+1;
				}
				if(!bused[temp])
				{
					
					bused[temp]=1;
					list[++tail].num=temp;
					list[tail].depth=list[head].depth+1;
					list[tail].bindex=head;
				}
			}
		}
		
		num=list[head].num%1000/100;
		remain=list[head].num-num*100;
		
		for(int i=0;i<10;++i)
		{
			if(i==num)continue;
			temp = i*100+remain;
			if(prime(temp))
			{
				if(temp==b)
				{
					
					return list[head].depth+1;
				}
				if(!bused[temp])
				{
					bused[temp]=1;
					list[++tail].num=temp;
					list[tail].depth=list[head].depth+1;
					list[tail].bindex=head;
				}
			}
		}
		
		num=list[head].num/1000;
		remain=list[head].num-num*1000;
		
		for(int i=1;i<10;++i)
		{
			if(i==num)continue;
			temp = i*1000+remain;
			if(prime(temp))
			{
				if(temp==b)
				{
					
					return list[head].depth+1;
				}
				if(!bused[temp])
				{
					bused[temp]=1;
					list[++tail].num=temp;
					list[tail].depth=list[head].depth+1;
					list[tail].bindex=head;
				}
			}
		}
		++head;
	}
	return -1;
}

void init()
{
	int flag;
	for(int i=1001;i<10000;i+=2)
	{
		int m=(int)sqrt((double)i);
		flag=0;
		for(int j=2;j<=m;++j)
		{
			if(i%j==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)pr[i]=1;
	}
	
}

int main()
{
	int t;
	cin>>t;
	int a,b;
	
	init();
	while(t--)
	{
		scanf("%d%d",&a,&b);
		memset(bused,0,sizeof(bused));
		memset(list,0,sizeof(list));
		int result=bfs(a,b);
		if(result>=0)
			printf("%d\n",result);
		else
			printf("Impossible\n");
	}
    return 0;
}
