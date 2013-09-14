#include<iostream>
using namespace std;

char f[100000][110];

char s1[110],s2[110];

void add(char *aa,char *bb,char *cc)
{
	int i,s=0,tmp;
	for(i=1;i<=bb[0]&&i<=cc[0];++i)
	{
		tmp = (bb[i]-'0')+(cc[i]-'0')+s;
		aa[i]=tmp%10+'0';
		s=tmp/10;
	}
	
	for(;i<=bb[0];++i)
	{
		tmp = (bb[i]-'0')+s;
		aa[i]=tmp%10+'0';
		s=tmp/10;
	}
	
	for(;i<=cc[0];++i)
	{
		tmp = (cc[i]-'0')+s;
		aa[i]=tmp%10+'0';
		s=tmp/10;
	}
	
	if(s)
	{
		aa[0]=i;
		aa[i]=s+'0';
	}
	else
	{
		aa[0]=i-1;
	}
}

void init()
{
	f[1][0]=1;
	f[1][1]='1';
	f[2][0]=1;
	f[2][1]='2';
	
	for(int i=3;;++i)
	{
		add(f[i],f[i-1],f[i-2]);
		if(f[i][0]>100)break;
		
		
	}
	
	
	
}

int cmp(char *aa,char *bb)
{
	if(aa[0]!=bb[0])return aa[0]-bb[0];
	
	for(int i=aa[0];i>0;--i)
	{
		if(aa[i]!=bb[i])return aa[i]-bb[i];
	}
	return 0;
}

void Swap(char *aa,char *bb)
{
	char cc[110];
	
	for(int i=0;i<=aa[0];++i)
	{
		cc[i]=aa[i];
	}
	
	for(int i=0;i<=bb[0];++i)
	{
		aa[i]=bb[i];
	}
	
	for(int i=0;i<=cc[0];++i)
	{
		bb[i]=cc[i];
		
		
	}
}

void swap(char &aa,char &bb)
{
	char cc;
	
	cc = aa;
	aa = bb;
	bb = cc;
}

int main()
{
	
	freopen("in.txt","r",stdin);
	freopen("oo.txt","w",stdout);
	
	
	init();
	
	while(1)
	{
		scanf("%s%s",s1+1,s2+1);
		if(s1[1]=='0'&&s2[1]=='0')break;
		
		int low,high;
		s1[0]=strlen(s1+1);
		s2[0]=strlen(s2+1);
		

		
		low=1;
		high=s1[0];
		while(low<high)
		{
			swap(s1[low],s1[high]);
			++low;
			--high;
		}
		
		low=1;
		high=s2[0];
		
		while(low<high)
		{
			swap(s2[low],s2[high]);
			++low;
			--high;
		}
		
		if(cmp(s1,s2)>0)
		{
			Swap(s1,s2);
		}
		
		int i;
		for(i=1;;++i)
		{
			if(cmp(f[i],s1)>=0)break;
		}
		low=i;
		for(;;++i)
		{
			if(cmp(f[i],s2)>0)break;
		}
		high=i;
		

		printf("%d\n",high-low);
		
	}
    return 0;
}
