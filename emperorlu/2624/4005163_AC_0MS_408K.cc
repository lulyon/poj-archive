#include<iostream>
#include<math.h>
using namespace std;
#define exp 1e-6

typedef struct
{
	double x,y;
}point;

bool cmp(const point &aa,const point &bb)
{
	if(aa.x!=bb.x)
		return aa.x<bb.x;
	else
		return aa.y<bb.y;
}
point p[5];

point pp[5];
int main()
{
	int i,j;
	while(scanf("%lf%lf",&p[0].x,&p[0].y)!=EOF) 
	{
		
		for(i=1;i<=3;++i)
			scanf("%lf%lf",&p[i].x,&p[i].y);
			
		sort(p,p+4,cmp);
		for(i=1;i<4;++i)
			if(fabs(p[i].x-p[i-1].x)<exp&&fabs(p[i].y-p[i-1].y)<exp)
			{
				pp[0].x=p[i].x;
				pp[0].y=p[i].y;		
				break;
			}
			int top=1;
		for(j=0;j<4;++j)
			if(j!=i&&j!=i-1)
			{
				pp[top].x=p[j].x;
				pp[top].y=p[j].y;
				top++;
			}
			
		printf("%.3lf %.3lf\n",pp[1].x+pp[2].x-pp[0].x,pp[1].y+pp[2].y-pp[0].y);
	}
    return 0;
}
