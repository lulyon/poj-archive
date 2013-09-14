#include<iostream>
#include<math.h>
using namespace std;
char f[300][150];
void init()
{
	f[0][0]='1';
	f[0][1]='\0';
	f[1][0]='1';
	f[1][1]='\0';
	int i,j,s;
	for(i=2;i<=250;++i)
	{
		//f[i]=2*f[i-2]+f[i-1];
		s = 0;
		for(j=0;f[i-2][j]&&f[i-1][j];++j)
		{
			f[i][j] = (2*(f[i-2][j]-'0')+f[i-1][j]-'0'+s)%10+'0';
			s = (2*(f[i-2][j]-'0')+f[i-1][j]-'0'+s)/10;
		}
		for(;f[i-2][j];++j)
		{
			f[i][j] = (2*(f[i-2][j]-'0')+s)%10+'0';
			s = (2*(f[i-2][j]-'0')+s)/10;
		}
		for(;f[i-1][j];++j)
		{
			f[i][j] = (f[i-1][j]-'0'+s)%10+'0';
			s = (f[i-1][j]-'0'+s)/10;
		}
		if(s)f[i][j]=s+'0';
		else f[i][j]='\0';
	}
}
int main()
{
	int i,n;
	init();
	while(scanf("%d",&n)!=EOF)
	{
		for(i=strlen(f[n])-1;i>=0;--i)
			printf("%c",f[n][i]);
		cout<<endl;
	}
    return 0;
}
