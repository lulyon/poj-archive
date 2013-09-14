#include<stdio.h>
int main()
{
 		int n,x,y,a,b,c,d;
 		scanf("%d",&n);
 		while(n--)
 		{
			 scanf("%d%d",&x,&y);
			 a=(x+y)/2;
			 b=(x-y)/2;
			 c=(x+y)%2;
			 d=(x-y)%2;
			 if(c==0&&d==0&&b>=0)printf("%d %d\n",a,b);
			 else printf("impossible\n");
    }
    return 0;
}
