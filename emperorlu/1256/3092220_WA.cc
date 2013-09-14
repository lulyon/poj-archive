#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;
int transfer(char c)
{
    if(c<='Z'&&c>='A')
       return (c-'A')*2;
    else if(c<='z'&&c>='a')
        return (c-'A')*2+1; 
}
int cmp(char a,char b)
{
	int c,d;
	c=transfer(a);
	d=transfer(b);
	return c<b;
}

int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	   char s[20],d[20];
	   scanf("%s",s);
	   int len=strlen(s);
	   sort(s,s+len,cmp);
	   do
	   {
            strcpy(d,s);
            printf("%s\n",d);
        }
       while(next_permutation(s,s+len)&&strcmp(d,s));
	}
    return 0;
}
