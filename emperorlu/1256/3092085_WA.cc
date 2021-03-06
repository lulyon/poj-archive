#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;

int mycompare(char a,char b)
{
	char c,d;
	c=tolower(a);
	d=tolower(b);

	if(c==d)
		return (a<b);
	return c<d;
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
	   sort(s,s+len,mycompare);
	   do
	   {
            strcpy(d,s);
            printf("%s\n",d);
        }
       while(next_permutation(s,s+len)&&strcmp(d,s));
	}
    return 0;
}
