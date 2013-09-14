#include<iostream>
using namespace std;

typedef struct
{
	int len;
	char digit[1000];
	
}node;

node num[400];

node tmp;


int cnt[400][10];

int stack[10];

void add(node &bb,node &tmp,int i)
{
	int temp;
	int s=0,k,j;
	for(k=1,j=i+k-1;k<=tmp.len && j<=bb.len;++k,++j)
	{
		temp = bb.digit[j]-'0'+tmp.digit[k]-'0'+s;
		
		bb.digit[j]=temp%10+'0';
		
		s = temp/10;
	}
	
	
	for(;k<=tmp.len;++k,++j)
	{
		temp = tmp.digit[k]-'0'+s;
		
		bb.digit[j]=temp%10+'0';
		
		s = temp/10;
	}
	
	for(;j<=bb.len;++k,++j)
	{
		temp = bb.digit[j]-'0'+s;
		
		bb.digit[j]=temp%10+'0';
		
		s = temp/10;
	}
	
	if(s)
	{
		bb.len=j;
		bb.digit[bb.len]=s+'0';
	}
	else
	{
		bb.len=j-1;
	}
	
}

void mult(node &aa,int i,node &bb)
{
	int top=1;
	while(i)
	{
		stack[top++]=i%10;
		i/=10;
	}
	
	bb.len=0;
	int s=0,temp;
	for(int i=1;i<top;++i)
	{
		tmp.len=0;
		 s=0;
		for(int j=1;j<=aa.len;++j)
		{
			temp = (aa.digit[j]-'0')*stack[i]+s;
			
			tmp.digit[j]=temp%10+'0';
			
			s = temp/10;
		}
		if(s)
		{
			tmp.len=aa.len+1;
			tmp.digit[tmp.len]=s+'0';
		}
		else
		{
			tmp.len=aa.len;
		}
		
		add(bb,tmp,i);
	}
	
}

void init()
{
	num[1].digit[1]='1';
	num[1].len=1;
	
	
	for(int i=1;i<=num[1].len;++i)
		cnt[1][num[1].digit[i]-'0']++;
	
	
	for(int i=2;i<=366;++i)
	{
		mult(num[i-1],i,num[i]);
		
		for(int j=1;j<=num[i].len;++j)
			cnt[i][num[i].digit[j]-'0']++;
	}
	
	
/*	
	for(int i=1;i<366;++i)
	{
		for(int j=num[i].len;j;--j)
			printf("%c",num[i].digit[j]);
		
		cout<<endl;

	}
	*/
	
}

int main()
{
	int t;
	
	init();
	
	cin>>t;
	
	int n,m;
	
	while(t--)
	{
		scanf("%d%d",&n,&m);
		
		printf("%d\n",cnt[n][m]);
		
	}
    return 0;
}
