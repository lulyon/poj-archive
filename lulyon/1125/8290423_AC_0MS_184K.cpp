#include<iostream>
using namespace std;

const int maxnum = 1000000;

int a[110][110];
int maxroute[110];

int main(){
	int n,t;
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=n; ++j){
				if(i==j)a[i][j]=0;
				else a[i][j]=maxnum;
			}
		}
		for(int i=1; i<=n; ++i){
			scanf("%d",&t);
			for(int j=1; j<=t; ++j){
				int index,time;
				scanf("%d%d",&index, &time);
				a[i][index] = time;
			}
		}
		
		for(int k=1; k<=n; ++k){
			for(int i=1; i<=n; ++i){
				for(int j=1; j<=n; ++j){
					if(a[i][j]>a[i][k]+a[k][j]){
						a[i][j] = a[i][k]+a[k][j];
					}
				}
			}
		}
		for(int i=1; i<=n; ++i){
			maxroute[i]=-1;
			for(int j=1; j<=n; ++j){
				if(maxroute[i]<a[i][j]){
					maxroute[i]=a[i][j];
				}
			}
		}
		
		int index, minroute;
		index = 1;
		minroute = maxroute[1];
		for(int i=2; i<=n; ++i){
			if(minroute>maxroute[i]){
				minroute=maxroute[i];
				index = i;
			}
		}
		if(minroute>=maxnum){
			printf("disjoint\n");
		}
		else{
			printf("%d %d\n", index, minroute);
		}
		
	}	
	return 0;
}

