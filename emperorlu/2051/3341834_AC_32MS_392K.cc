#include<iostream>
#include<math.h>
using namespace std;
char head[20];
typedef struct
{
	int q_num,pos,period;
}node;
node que[50000];
bool cmp(const node &a,const node &b)
{
	return a.q_num < b.q_num;
}
int main()
{
	int i,n,k;
	for(i=0;;++i)
	{
		scanf("%s",head);
		if(head[0]=='#')
			break;
		scanf("%d%d",&que[i].q_num,&que[i].period);
		que[i].pos = que[i].period;
	}
	n = i;
	scanf("%d",&k);
	if(n==0)return 0;
	sort(que,que+n,cmp);
	
	while(k--)
	{
		int s=-1,min = INT_MAX;
		for(i=0;i<n;i++)
		{
			if(min>que[i].pos)
			{
				min = que[i].pos;
				s = i;
			}
		}
		if(s!=-1)
		{
			que[s].pos += que[s].period;
			printf("%d\n",que[s].q_num);
		}
	}
	
	//system("pause");
    return 0;
}
