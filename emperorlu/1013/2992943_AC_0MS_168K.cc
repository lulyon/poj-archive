#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int n;
    scanf("%d\n",&n);
    while(n--)
    {
        char left[10],right[10],mid[10];
        int check[13],count[13];
        memset(check,0,sizeof(check));
        memset(count,0,sizeof(count));
        for(int i=1;i<=3;i++)
        {
            scanf("%s%s%s",left,right,mid);
            if(strcmp(mid,"up")==0)
            {
                for(int j=0;left[j];j++)
                {
                    int lf,rt;
                    lf=left[j]-'A';
                    rt=right[j]-'A';
					count[lf]++;
					count[rt]++;
                    if(check[lf]==0)
                    {
                        check[lf]=1;
                    }
                    else if(check[lf]==-1)
                    {
                        check[lf]=2;
                    }
                    if(check[rt]==0)
                    {
                        check[rt]=-1;
                    }
                    else if(check[rt]==1)
                    {
                        check[rt]=2;
                    }
                }
            }
            else if(strcmp(mid,"down")==0)
            {
                for(int j=0;left[j];j++)
                {
                    int lf,rt;
                    lf=left[j]-'A';
                    rt=right[j]-'A';
					count[lf]++;
					count[rt]++;
                    if(check[lf]==0)
                    {
                        check[lf]=-1;
                    }
                    else if(check[lf]==1)
                    {
                        check[lf]=2;
                    }
                    if(check[rt]==0)
                    {
                        check[rt]=1;
                    }
                    else if(check[rt]==-1)
                    {
                        check[rt]=2;
                    }
                }
            }
            else
            {
                for(int j=0;left[j];j++)
                {
                    check[left[j]-'A']=2;
                    check[right[j]-'A']=2;
                }
            }
        }
        int max=0;
        for(int i=0;i<12;i++)
        {
			if(max<count[i]&&(check[i]==-1||check[i]==1))max=count[i];
		}
        for(int i=0;i<12;i++)
        {
			if(count[i]==max)
			{
            	if(check[i]==-1)
           		{
                	printf("%c is the counterfeit coin and it is light.\n",i+'A');
            	}
            	else if(check[i]==1)
            	{
                	printf("%c is the counterfeit coin and it is heavy.\n",i+'A');
            	}
			}
        }
    }
    return 0;
}
