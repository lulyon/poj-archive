#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct in
{
	char a[100];
}dat[100001];
struct In
{
	char b[10];
}data[100001];
int cmp ( const void *a1 , const void *b1 ) 
{ 
	return strcmp( ((In *)a1)->b,((In *)b1)->b ); 
} 
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",dat[i].a);
		int k=0;
		char *p=dat[i].a;
		char *q=data[i].b;
		for(;*p;p++)
		{
			if(*p>='A'&&*p<='P')
			{
				*q=(*p-'A')/3+'2';
				q++;
				k++;
				if(k==3)
				{
					*q='-';
					q++;
				}
			}
			else if(*p>='R'&&*p<='Y')
			{
				*q=(*p-'A'-1)/3+'2';
				q++;
				k++;
				if(k==3)
				{
					*q='-';
					q++;
				}
			}
			else if(*p>='0'&&*p<='9')
			{
				*q=*p;
				q++;
				k++;
				if(k==3)
				{
					*q='-';
					q++;
				}
			}
		}		
	}
	qsort(data,n,sizeof(data[0]),cmp);
	int cn=1;
	bool flag=0;
	for(int i=0;i<n-1;i++)
	{
		if(strcmp(data[i].b,data[i+1].b))
		{
			if(cn>1)
			{
				printf("%s",data[i].b);
				printf(" %d\n",cn);
				flag=1;
			}
			cn=1;
		}
		else
		{
			cn++;
		}
	}
	if(cn>1)
	{
		printf("%s",data[n-1].b);
		printf(" %d\n",cn);
		flag=1;
	}
	if(flag==0)printf("No duplicates.\n");
}
