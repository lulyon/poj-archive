#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;
char s[20];
inline int transfer(char c)
{
    if(c<='Z'&&c>='A')
        return (c-'A')*2;
    else
        return (c-'a')*2+1; 
}
bool cmp(char a,char b)
{
	return transfer(a) < transfer(b);
}
int main()
{
	int n,len;
	scanf("%d",&n);
	while(n--)
	{	   
	   scanf("%s",s);
	   len=strlen(s);
	   sort(s,s+len,cmp);
	   do
        printf("%s\n",s);
       while(next_permutation(s,s+len,cmp));
	}
    return 0;
}
