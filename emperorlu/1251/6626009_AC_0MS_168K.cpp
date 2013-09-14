#include<iostream>
using namespace std;
int cost[27][27];
char label[3];

#define _PKUDEBUG_ 0

int main()
{
#if _PKUDEBUG_
	freopen("in","r",stdin);
	freopen("out","w",stdout);
#endif

	int n_v,n_n,n_label,n_tmp_label,n_cost;

	while(1)
	{
		//input
		scanf("%d",&n_v);
		
#if _PKUDEBUG_
		printf("%d\n",n_v);
#endif

		
		if(!n_v)break;
		
		for(int i=0; i<n_v; ++i)
		{
			for(int j=0; j<n_v; ++j)
			{
				cost[i][j]=100000;
			}
		}
		
		for(int i=0; i<n_v-1; ++i)
		{
			scanf("%s%d",label,&n_n);

#if _PKUDEBUG_
			printf("%c %d ",label[0],n_n);
#endif

			n_label = label[0] - 'A';
			for(int j=0; j<n_n; ++j)
			{
				scanf("%s%d", label, &n_cost);

#if _PKUDEBUG_
				printf("%c %d " ,label[0],n_cost);
#endif

				n_tmp_label = label[0] - 'A';
				cost[n_label][n_tmp_label] = n_cost;
				cost[n_tmp_label][n_label] = n_cost;
			}
			
#if _PKUDEBUG_
			printf("\n");
#endif

		}
		
		//process
		int min_edge=100000,index1,index2,total_cost;
		for(int i=0; i<n_v; ++i)
		{
			for(int j=0; j<i; ++j)
			{
				if(cost[i][j]<min_edge)
				{
					min_edge = cost[i][j];
					index1 = i;
					index2 = j;
				}
			}
		}
		
		total_cost = min_edge;
				
		
		int min_cost_index[27];
		bool b_visit[27];
		
		for(int i=0; i<n_v; ++i)
			b_visit[i] = 0;
		
		b_visit[index1] = 1;
		b_visit[index2] = 1;
		
		for(int i=0; i<n_v; ++i)
		{
			if(!b_visit[i])
			{
				
				if(cost[i][index1]<=cost[i][index2])
					min_cost_index[i] = index1;
				else
					min_cost_index[i] = index2;	
				
			}
		}
		
		int tmp_index,min_index;
		for(int k=0; k<n_v-2; ++k)
		{
			min_edge = 100000;
			for(int i=0; i<n_v; ++i)
			{
				if(!b_visit[i])
				{
					tmp_index = min_cost_index[i];
					if(cost[i][tmp_index]<min_edge)
					{
						min_edge = cost[i][tmp_index];
						min_index = i;
					}
				}
			}
			
			total_cost += min_edge;
			b_visit[min_index] = 1;
			
			
			for(int i=0; i<n_v; ++i)
			{
				if(!b_visit[i])
				{
					tmp_index = min_cost_index[i];
					if(cost[i][min_index]<cost[i][tmp_index])
						min_cost_index[i] = min_index;
				}
			}
			
		}
		
		//output
		printf("%d\n",total_cost);
		
	}
	return 0;
}

