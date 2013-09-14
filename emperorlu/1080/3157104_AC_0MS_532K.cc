#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include<set>
#include<math.h>

using namespace std;
int opt[110][110];
char a[110],b[110];
int t[110][110];
int max(int a,int b,int c)
{
	int Max=a;
	if(Max<b)Max=b;
	if(Max<c)Max=c;
	return Max;
}
int inittable()
{
	t['A']['A']=5;
	t['A']['C']=-1;
	t['A']['G']=-2;
	t['A']['T']=-1;
	t['A']['-']=-3;
	
	t['C']['A']=-1;
	t['C']['C']=5;
	t['C']['G']=-3;
	t['C']['T']=-2;
	t['C']['-']=-4;
	
	t['G']['A']=-2;
	t['G']['C']=-3;
	t['G']['G']=5;
	t['G']['T']=-2;
	t['G']['-']=-2;
	
	t['T']['A']=-1;
	t['T']['C']=-2;
	t['T']['G']=-2;
	t['T']['T']=5;
	t['T']['-']=-1;
	
	t['-']['A']=-3;
	t['-']['C']=-4;
	t['-']['G']=-2;
	t['-']['T']=-1;
	
}
int table(char a,char b)
{
	return t[a][b];
}
int dp(int num1,int num2)
{
	int i,j;
	opt[0][0]=0;
	for(i=1;i<=num1;i++)
		opt[0][i] = opt[0][i-1]+table('-',a[i-1]);
	for(i=1;i<=num2;i++)
        opt[i][0] = opt[i-1][0]+table('-',b[i-1]);
    for(i=1;i<=num2;i++)
		for(j=1;j<=num1;j++)
			opt[i][j] = max(opt[i-1][j-1]+table(b[i-1],a[j-1]),
							opt[i][j-1]+table('-',a[j-1]),
							opt[i-1][j]+table('-',b[i-1]));
	return opt[num2][num1];
}
int main()
{
	int num1,num2,t;
	inittable();
	cin>>t;
	while(t--)
	{
		scanf("%d %s",&num1,a);
		scanf("%d %s",&num2,b);
		
		cout<<dp(num1,num2)<<endl;
	}
    return 0;
}
