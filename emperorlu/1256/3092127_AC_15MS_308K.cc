#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct
{
    char s;
    int num;
}node;
node a[15];
int nnn(char a)
{
       if(a>='A' && a<='Z')
              return (a-'A')*2;
       else
              return (a-'a')*2+1;
}
bool cmp(node a,node b)
{
       return a.num < b.num;
}
int main()

{
       int i,n,len;
       char s[15];
       scanf("%d",&n);
       while(n--)
       {
              scanf("%s",s);
              len=strlen(s);
              for(i=0;i<len;i++)
              {
                     a[i].s=s[i];
                     a[i].num=nnn(s[i]);
              }
              sort(a,a+len,cmp);
              for(i=0;i<len;i++)
                     printf("%c",a[i].s);
              printf("\n");
              while(next_permutation(a,a+len,cmp))
              {
                     for(i=0;i<len;i++)
                            printf("%c",a[i].s);
                     printf("\n");
              }
       }
       return 0;
} 
