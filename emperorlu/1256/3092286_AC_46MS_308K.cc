#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;
char s[20];
int transfer(char c)
{
    if(c<='Z'&&c>='A')
       return (c-'A')*2;
    else if(c<='z'&&c>='a')
        return (c-'a')*2+1; 
}
bool cmp(char a,char b)
{
	int c,d;
	c=transfer(a);
	d=transfer(b);
	return c<d;
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int ii=0;ii<n;ii++)
	{	   
	   scanf("%s",s);
	   int len=strlen(s);
	   sort(s,s+len,cmp);
	   do
	   {
            for(int i=0;i<len;i++)
                printf("%c",s[i]);
            printf("\n");
        }
       while(next_permutation(s,s+len,cmp));
	}
    return 0;
}
