#include<stdio.h>
int main()
{
 		int n,x,y,a,b;
 		scanf("%d",&n);
 		while(n--)
 		{
			 scanf("%d%d",&x,&y);
			 a=(x+y)/2;
			 b=(x-y)/2;
			 if(b>=0)printf("%d %d\n",a,b);
			 else printf("impossible\n");
    }
    return 0;
}
