#include<iostream>
using namespace std;

int r,c,n;

bool b[30][30],flag;

typedef struct
{
	int r,c;
}info;

info ans[1000];


void init(void)
{
	for(int j=0;j<=c+3;++j)
	{
		b[0][j]=b[1][j]=b[r+2][j]=b[r+3][j]=1;
	}
	
	for(int i=2;i<=r+1;++i)
	{
		for(int j=2;j<=c+1;++j)
		{
			b[i][j]=0;
		}
		b[i][0]=b[i][1]=b[i][c+2]=b[i][c+3]=1;
	}
}

void output(void)
{
	for(int i=1;i<=n;++i)
	{
		printf("%c%d",ans[i].r+'A'-2,ans[i].c-1);
	}
	cout<<endl;
	
}

void backtrack(int t,int i,int j)
{
	if(!flag)
	{
		if(t>n)
		{
			flag=1;
			output();
			return;
		}
		else
		{
			b[i][j]=1;
			
			ans[t].r = i;
			ans[t].c = j;
						
			if(!b[i-2][j-1])
			{
				backtrack(t+1,i-2,j-1);
				if(flag)return;
				else b[i-2][j-1]=0;
			}
			
			if(!b[i-2][j+1])
			{
				backtrack(t+1,i-2,j+1);
				if(flag)return;
				else b[i-2][j+1]=0;
			}
			
			if(!b[i-1][j-2])
			{
				backtrack(t+1,i-1,j-2);
				if(flag)return;
				else b[i-1][j-2]=0;
			}
			
			if(!b[i-1][j+2])
			{
				backtrack(t+1,i-1,j+2);
				if(flag)return;
				else b[i-1][j+2]=0;
			}
			
			if(!b[i+1][j-2])
			{
				backtrack(t+1,i+1,j-2);
				if(flag)return;
				else b[i+1][j-2]=0;
			}
			
			if(!b[i+1][j+2])
			{
				backtrack(t+1,i+1,j+2);
				if(flag)return;
				else b[i+1][j+2]=0;
			}
			
			if(!b[i+2][j-1])
			{
				backtrack(t+1,i+2,j-1);
				if(flag)return;
				else b[i+2][j-1]=0;
			}
			
			if(!b[i+2][j+1])
			{
				backtrack(t+1,i+2,j+1);
				if(flag)return;
				else b[i+2][j+1]=0;
			}
			
			
			
			if(t==n)
			{
				flag=1;
				output();
				return;
			}
		}
	}
}

int main()
{
	int t,tt=0;
	cin>>t;
	
	while(t--)
	{
		scanf("%d%d",&c,&r);
		
		init();
		
		flag=0;
		
		n=r*c;
		
		printf("Scenario #%d:\n",++tt);
		
		backtrack(1,2,2);
		
		if(!flag)
			printf("impossible\n");
	}
    return 0;
}

