#include<iostream>
using namespace std;

typedef struct
{
	int w,h;
}node;

node stack[100];

int main()
{
	int w,n;
	while(1)
	{
		scanf("%d",&w);
		if(!w)break;
		
		n=0;
		while(1)
		{
			scanf("%d%d",&stack[n].w,&stack[n].h);
			
			if(stack[n].w==-1 && stack[n].h==-1)
				break;
			
			++n;
		}
		
		int Left,Right,Hight,tH;
		
		Left = Right = Hight= tH = 0;
		
		
		
		for(int i=0;i<n;++i)
		{
			if(Left+stack[i].w<=w)
			{
		
				Left += stack[i].w;
				if(Right<Left)Right=Left;
				if(Hight<stack[i].h)Hight=stack[i].h;
			}
			else
			{

				Left = stack[i].w;
				
				if(Right<Left)Right=Left;
				tH += Hight;
				
				Hight = stack[i].h;
			}
		}
		
		tH += Hight;
		
		printf("%d x %d\n",Right,tH);
	}
    return 0;
}

