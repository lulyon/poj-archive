#include<stdio.h>
#include<string.h>
char s[100001],t[100001],flag,tag;
int i,j;
int main()
{
    while(scanf("%s%s",s,t)!=EOF)
    {
		tag=1;
        for(i=0;t[i];i++)
        {
            if(s[0]==t[i])
            {
                i++;
                j=1;
                flag=1;
                for(;s[j];j++,i++)
                {
                     while(s[j]!=t[i])
					 {
						if(!t[i])
						{
							flag=0;
							goto leap;
						}
						i++;
					 }
                }
                leap:
                if(flag)
                {
					tag=0;
					if(strcmp(s,t)==0)
						printf("No\n");
					else printf("Yes\n");
				}
            }
        }
        if(tag)printf("No\n");
    } 
    return 0;
}
