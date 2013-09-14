#include<iostream>
using namespace std;

const int MaxN = 10010;
const int len=MaxN/2+1;
int p[len]={2},pp=1;

bool b[10010];

int d[len],e[len],dp;
void init()
{
    int i,j,cur;
    for(i=1;;++i)
    {
        if(!p[i])
        {
            p[pp++]=cur=i+i+1;
            for(j=2*i*(i+1);j<len;j+=cur)
                p[j]=1;
            if(j==2*i*(i+1))
                break;
        }
    }
    for(++i;i<len;++i)
    {
        if(!p[i])p[pp++]=i+i+1;
    }
}
void factorization(int num)
{
    int i,cnt,div;
    for(i=0;i<pp&&p[i]<num;++i)
    {
        if(num%p[i]==0)
        {
			if(b[p[i]]==0)
			{
            	d[dp]=p[i];
            	b[p[i]]=1;
            	div=p[i]*p[i];
            	cnt=1;
            	while(num%div==0)
            	{
                	div*=p[i];
                	++cnt;
            	}
            	e[dp++] += cnt;
            	div/=p[i];
            	num/=div;
            	if(num==1)
                	break;
			}
			else
			{
				div=p[i]*p[i];
            	cnt=1;
            	while(num%div==0)
            	{
                	div*=p[i];
                	++cnt;
            	}
            	int j;
            	for(j=0;j<dp;++j)
            		if(d[j]==p[i])break;
            	
            	e[j]+=cnt;
            	div/=p[i];
            	num/=div;
            	if(num==1)
                	break;
			}
        }
    }
    
    if(num!=1)
    {
		if(b[p[i]]==0)
		{
			b[p[i]]=1;
        	d[dp]=num;
        	e[dp++]++;
		}
		else
		{
			int j;
			for(j=0;j<dp;++j)
            	if(d[j]==p[i])break;
            e[j]++;
		}
    }
}

int main()
{
    int num;
    init();
    dp=0;
    int t=10;
    while(t--)
    {
		scanf("%d",&num);
        factorization(num);
    }
    
    int ans=1;
    
    for(int i=0;i<dp;++i)
    	ans = (ans*(e[i]+1))%10;
    
    printf("%d\n",ans);
    
    
    return 0;
}
