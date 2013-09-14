#include<iostream>
#include<math.h>
using namespace std;
int m,n;
char a[15][15];
bool b[15][15];
void calc(int i,int j)
{
	if(a[i][j]=='\\')
	{
		if(!b[i-1][j-1]&&a[i-1][j-1]=='\\')
		{
			b[i-1][j-1]=1;
			calc(i-1,j-1);
		}
		if(!b[i+1][j+1]&&a[i+1][j+1]=='\\')
		{
			b[i+1][j+1]=1;
			calc(i+1,j+1);
		}
	}
	else if(a[i][j]=='/')
	{
		if(!b[i-1][j+1]&&a[i-1][j+1]=='/')
		{
			b[i-1][j+1]=1;
			calc(i-1,j+1);
		}
		if(!b[i+1][j-1]&&a[i+1][j-1]=='/')
		{
			b[i+1][j-1]=1;
			calc(i+1,j-1);
		}
	}
	else if(a[i][j]=='|')
	{
		if(!b[i-1][j]&&a[i-1][j]=='|')
		{
			b[i-1][j]=1;
			calc(i-1,j);
		}
		if(!b[i+1][j]&&a[i+1][j]=='|')
		{
			b[i+1][j]=1;
			calc(i+1,j);
		}
	}
	else if(a[i][j]=='-')
	{
		if(!b[i][j-1]&&a[i][j-1]=='-')
		{
			b[i][j-1]=1;
			calc(i,j-1);
		}
		if(!b[i][j+1]&&a[i][j+1]=='-')
		{
			b[i][j+1]=1;
			calc(i,j+1);
		}
	}
	
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>m>>n;
		memset(b,0,sizeof(b));
		for(int i=1;i<=m;++i)
			cin>>&a[i][1];
		int cn=0;
		for(int i=1;i<=m;++i)
			for(int j=1;j<=n;++j)
			{
				if(!b[i][j]&&a[i][j]!='.')
				{
					b[i][j]=1;
					calc(i,j);
					cn++;
					if(cn==2)
					{
						cout<<"INCORRECT"<<endl;
						goto leap;
					}
				}
			}
		if(cn==0)
			cout<<"INCORRECT"<<endl;
		else if(cn==1)
			cout<<"CORRECT"<<endl;
		leap:;
	}
    return 0;
}
